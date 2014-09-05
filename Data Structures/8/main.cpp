#include <iostream> 
#include "Tree.h"
using namespace std;

int main()
{
   Tree< int > intTree;
   int intVal;

   cout << "Enter 10 integer values:\n";

   for ( int i = 0; i < 10; i++ ) 
   {
      cin >> intVal;
      intTree.insertNode( intVal );
   }

   cout << "\nPreorder traversal\n";
   intTree.preOrderTraversal();

   cout << "\nInorder traversal\n";
   intTree.inOrderTraversal();

   cout << "\nPostorder traversal\n";
   intTree.postOrderTraversal();

   cout << "\n\nThere are " << intTree.getDepth()
      << " levels in this binary tree\n";
}
