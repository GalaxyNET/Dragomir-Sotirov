#include <iostream> 
#include "List2.h"

int main()
{
   List2< int > intList;

   for ( int i = 2; i <= 20; i += 2 )
      intList.insertAtBack( i );

   intList.print();

   int value;  
   int *ptr;

   cout << "Enter a value to search for: ";
   cin >> value;
   ptr = intList.searchList( value );

   if ( ptr != 0 )
      cout << *ptr << " was found\n";
   else
      cout << "Element not found\n";
}
