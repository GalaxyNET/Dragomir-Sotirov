#include <iostream> 
#include "List.h"
using namespace std;

template< typename D >void concatenate( List< D > &, List< D > & );

int main()
{
      List< char > list1;
      List< char > list2;

      list1.insertAtBack( 'D' );
      list1.insertAtBack( 'r' );
      list1.insertAtBack( 'a' );
      list1.insertAtBack( 'g' );
      list1.insertAtBack( 'o' );
      list1.insertAtBack( 'm' );
      list1.insertAtBack( 'i' );
      list1.insertAtBack( 'r' );
      list1.insertAtBack( ' ' );

      list1.print();

      list2.insertAtBack( 'S' );
      list2.insertAtBack( 'o' );
      list2.insertAtBack( 't' );
      list2.insertAtBack( 'i' );
      list2.insertAtBack( 'r' );
      list2.insertAtBack( 'o' );
      list2.insertAtBack( 'v' );

      list2.print();

      concatenate( list1, list2 );
      cout << "The new List after concatenation is: "<<endl;

      list1.print();

      return 0;
}

template< typename D >void concatenate( List< D > &list1, List< D > &list2 )
{
   List< D > newList( list2 );
   D newL;

   while ( !newList.isEmpty() )
   {
      newList.removeFromFront( newL );
      list1.insertAtBack( newL );
   }
}
