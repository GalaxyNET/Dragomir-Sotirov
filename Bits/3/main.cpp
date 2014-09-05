#include <iostream> 
#include <iomanip>
using namespace std;

void displayBits( unsigned );
unsigned power2( unsigned, unsigned );

int main()
{
   unsigned number;
   unsigned pow;
   unsigned result;

   cout << "Enter two integers: ";
   cin >> number >> pow;
   
   cout << "\nnumber:\n";
   displayBits( number );
   cout << "\npower:\n";
   displayBits( pow );
   result = power2( number, pow );
   cout << '\n' << number << " * 2^" << pow << " = " << result << '\n';
   displayBits( result );
}

unsigned power2( unsigned n, unsigned p )  
{ 
   return n << p;
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
