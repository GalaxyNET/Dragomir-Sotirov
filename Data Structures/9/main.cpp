#include "List2.h"

int main()
{
   List2< int > intList; 

   for ( int i = 1; i <= 10; i++ )
      intList.insertAtBack( i );

   intList.print();
   intList.recursivePrintReverse();
}
