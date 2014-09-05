#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "Tree.h"
using namespace std;

int main()
{
   srand( time( 0 ) );

   Tree< int > intTree;
   int intVal;

   cout << "The values being placed in the tree are:\n";

   for ( int i = 1; i <= 15; i++ ) 
   {
      intVal = rand() % 100;
      cout << intVal << ' ';
      intTree.insertNode( intVal );
   }

   cout << "\n\nEnter a value to search for: ";
   cin >> intVal;

   TreeNode< int > *ptr = intTree.binaryTreeSearch( intVal );

   if ( ptr != 0 )
      cout << ptr->getData() << " was found\n";
   else
      cout << "Element was not found\n";

   cout << endl;
}
