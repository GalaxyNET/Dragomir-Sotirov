#include <iostream> 
#include <iomanip> 
using namespace std;

void displayBits( unsigned );

int main()
{
   unsigned val;

   cout << "Enter an integer: ";
   cin >> val;

   cout << "\nBefore right shifting 4 bits is:\n";
   displayBits( val );
   cout << "After right shifting 4 bits is:\n";
   displayBits( val >> 4 );
}

void displayBits( unsigned value )
{
   const int SHIFT = 8 * sizeof( unsigned ) - 1;
   const unsigned MASK = 1 << SHIFT;

   cout << setw( 7 ) << value << " = ";
	
   for ( unsigned c = 1; c <= SHIFT + 1; c++ ) 
   {
      cout << ( value & MASK ? '1' : '0' );
      value <<= 1;
	
      if ( c % 8 == 0 ) 
         cout << ' ';
   }
	
   cout << endl;
}
