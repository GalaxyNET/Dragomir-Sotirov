#include <iostream> 
#include <cstring>
using namespace std;

const int SIZE = 20;

int main()
{
   int length, i;
   char array[ 5 ][ SIZE ];
      
   for ( i = 0; i <= 4; i++ )
   {
      cout << "Enter a string: ";
      cin.getline( &array[ i ][ 0 ], SIZE );
   }
   
   cout << "\nThe strings ending with \"ED\" are:\n";

   for ( i = 0; i <= 4; i++ )
   {
      length = strlen( &array[ i ][ 0 ] );
      
      if ( strcmp( &array[ i ][ length - 2 ], "ED" ) == 0 )
         cout << &array[ i ][ 0 ] << '\n';
   }
}
