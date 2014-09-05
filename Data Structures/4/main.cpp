#include <iostream> 
#include <new>
#include "List.h"

using namespace std;

template< typename T > void reverseList( List< T > &, List< T > & );

int main()
{
   List< char > list1;
   List< char > list2;

   for ( char c = 'a'; c <= 'j'; c++ )
      list1.insertAtBack( c );

   list1.print();
   reverseList( list2, list1 );

   cout << "The list after reversing:\n";
   list2.print();
}

template< typename T >void reverseList( List< T > &first, List< T > &second )
{
   List< T > temp( second );
   T value;

   while ( !temp.isEmpty() )
   {
      temp.removeFromFront( value );
      first.insertAtFront( value );
   }
}
