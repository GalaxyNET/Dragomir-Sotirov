#include <iostream> 
#include <iomanip> 
using namespace std;

void unpackCharacters( char * const, char * const, unsigned );
void displayBits( unsigned );

int main()
{
   char a;
   char b;
   unsigned packed = 16706;
   
   cout << "The packed character representation is:\n";
   displayBits( packed );

   unpackCharacters( &a, &b, packed );
   cout << "\nThe unpacked characters are \'" << a << "\' and \'" << b 
      << "\'\n";
   displayBits( a );
   displayBits( b );
}

void unpackCharacters( char * const aPtr, char * const bPtr, 
   unsigned pack )
{
   unsigned mask1 = 65280;
   unsigned mask2 = 255;
   
   *aPtr = static_cast< char >( ( pack & mask1 ) >> 8 );
   *bPtr = static_cast< char >( pack & mask2 );
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
