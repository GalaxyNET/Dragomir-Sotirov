#include <iostream> 
#include <cctype>
#include "Stack.h"
using namespace std;

int main()
{
   Stack< char > charStack;
   char c;
   char string1[ 80 ];
   char string2[ 80 ];
   int i = 0;

   cout << "Enter a sentence:\n";
  
   while ( ( c = static_cast< char >( cin.get() ) ) != '\n' )
   {
      if ( isalpha( c ) ) 
      {
         string1[ i++ ] = c;
         charStack.push( c );
      }
   }

   string1[ i ] = '\0';
   i = 0;

   while ( !charStack.isStackEmpty() )
      charStack.pop( string2[ i++ ] );

   string2[ i ] = '\0';

   if ( strcmp( string1, string2 ) == 0 )
      cout << "\nThe sentence is a palindrome\n";
   else
      cout << "\nThe sentence is not a palindrome\n";
}
