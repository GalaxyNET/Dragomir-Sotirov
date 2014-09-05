#include <iostream> 
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   ofstream outFile( "datasize.dat" );
   
   if ( !outFile ) 
   {
      cerr << "Unable to open \"datasize.dat\".\n";
      exit( 1 );
   }

   outFile << "Data type" << setw( 24 ) << "Size\nchar" << setw( 21 )
      << sizeof( char ) << "\nunsigned char" << setw( 12 )
      << sizeof( unsigned char ) << "\nshort int" << setw( 16 )
      << sizeof( short int ) << "\nunsigned short int" << setw( 7 )
      << sizeof( unsigned short ) << "\nint" << setw( 22 ) 
      << sizeof( int ) << '\n';

   outFile << "unsigned int" << setw( 13 ) << sizeof( unsigned ) 
      << "\nlong int" << setw( 17 ) << sizeof( long )
      << "\nunsigned long int" << setw( 8 ) << sizeof( unsigned long )
      << "\nfloat" << setw( 20 ) << sizeof( float ) 
      << "\ndouble" << setw( 19 ) << sizeof( double ) 
      << "\nlong double" << setw( 14 ) << sizeof( long double ) << endl;
}
