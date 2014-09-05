#include <iostream> 
using namespace std;

const int SIZE = 20;

int main()
{
   char array[ 5 ][ SIZE ];
   int i;

   for ( i = 0; i <= 4; i++ )
   {
      cout << "Enter a string: ";
      cin.getline( &array[ i ][ 0 ], SIZE );
   }
   
   cout << "\nThe strings starting with 'b' are:\n";
   
   for ( i = 0; i <= 4; i++ )

      if ( array[ i ][ 0 ] == 'b' )
         cout << &array[ i ][ 0 ] << '\n';
}
