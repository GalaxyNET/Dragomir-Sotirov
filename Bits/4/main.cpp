#include <iostream> 
#include <iomanip> 

using namespace std;

unsigned packCharacters( char, char );
void displayBits( unsigned );

int main()
{
   char a;
   char b;
   unsigned result;

   cout << "Enter two characters: ";
   cin >> a >> b;

   cout << "\n\'" << a << '\'' << " in bits as an unsigned integer is:\n";
   displayBits( a );

   cout << '\'' << b << '\'' << " in bits as an unsigned integer is:\n";
   displayBits( b );

   result = packCharacters( a, b );

   cout << "\n\'" << a << '\'' << " and " << '\'' << b << '\''
      << " packed in an unsigned integer:\n";
   displayBits( result );
}

unsigned packCharacters( char x, char y )
{
   unsigned pack = x;
   pack <<= 8;
   pack |= y;
   return pack;
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
