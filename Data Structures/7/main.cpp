#include <iostream> 
#include <string>
#include "Tree.h"
using namespace std;

int main()
{
   Tree< string > stringTree;
   char sentence[ 80 ];
   char *tokenPtr;

   cout << "Enter a sentence:\n";
   cin.getline( sentence, 80 );

   tokenPtr = strtok( sentence, " " );

   while ( tokenPtr != 0 ) 
   {
      string *newString = new string( tokenPtr );
      stringTree.insertNode( *newString );
      tokenPtr = strtok( 0, " " );
   }

   cout << "\nPreorder traversal\n";
   stringTree.preOrderTraversal();

   cout << "\nInorder traversal\n";
   stringTree.inOrderTraversal();

   cout << "\nPostorder traversal\n";
   stringTree.postOrderTraversal();

   cout << endl;
}
