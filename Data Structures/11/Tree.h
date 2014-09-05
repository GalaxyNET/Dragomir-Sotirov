#ifndef TREE_H
#define TREE_H

#include <iostream> 
#include <new>
#include "TreeNode.h"
using namespace std;

template< typename NODETYPE >
class Tree 
{
public:
   Tree();
   void insertNode( const NODETYPE & );
   void preOrderTraversal() const;
   void inOrderTraversal() const;
   void postOrderTraversal() const;
   TreeNode< NODETYPE > *binaryTreeSearch( int ) const;
protected:
   TreeNode< NODETYPE > *rootPtr;
private:
   void insertNodeHelper( TreeNode< NODETYPE > **, const NODETYPE & );
   void preOrderHelper( TreeNode< NODETYPE > * ) const;
   void inOrderHelper( TreeNode< NODETYPE > * ) const;
   void postOrderHelper( TreeNode< NODETYPE > * ) const;
   TreeNode< NODETYPE > *binarySearchHelper( TreeNode< NODETYPE > *, int ) const;
};

template< typename NODETYPE >
Tree< NODETYPE >::Tree() 
{ 
   rootPtr = 0; 
}

template< typename NODETYPE >
void Tree< NODETYPE >::insertNode( const NODETYPE &value )
{ 
   insertNodeHelper( &rootPtr, value ); 
}

template< typename NODETYPE >
void Tree< NODETYPE >::insertNodeHelper( TreeNode< NODETYPE > **ptr,
   const NODETYPE &value )
{
   if ( *ptr == 0 )
      *ptr = new TreeNode< NODETYPE >( value );
   else
   {     
      if ( value <= ( *ptr )->data )
         insertNodeHelper( &( ( *ptr )->leftPtr ), value );
      else
         insertNodeHelper( &( ( *ptr )->rightPtr ), value );
   }
}

template< typename NODETYPE >
void Tree< NODETYPE >::preOrderTraversal() const 
{ 
   preOrderHelper( rootPtr ); 
}

template< typename NODETYPE >
void Tree< NODETYPE >::preOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) 
   {
      cout << ptr->data << ' ';
      preOrderHelper( ptr->leftPtr );
      preOrderHelper( ptr->rightPtr );
   }
}

template< typename NODETYPE >
void Tree< NODETYPE >::inOrderTraversal() const 
{ 
   inOrderHelper( rootPtr ); 
}

template< typename NODETYPE >
void Tree< NODETYPE >::inOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) 
   {
      inOrderHelper( ptr->leftPtr );
      cout << ptr->data << ' ';
      inOrderHelper( ptr->rightPtr );
   }
}

template< typename NODETYPE >
void Tree< NODETYPE >::postOrderTraversal() const 
{ 
   postOrderHelper( rootPtr ); 
}

template< typename NODETYPE >
void Tree< NODETYPE >::postOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) 
   {
      postOrderHelper( ptr->leftPtr );
      postOrderHelper( ptr->rightPtr );
      cout << ptr->data << ' ';
   }
}

template< typename NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binaryTreeSearch( int val ) const
{ 
   return binarySearchHelper( rootPtr, val ); 
}

template< typename NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binarySearchHelper( 
   TreeNode< NODETYPE > *ptr, int value ) const
{
   if ( ptr == 0 )
      return 0;

   cout << "Comparing " << value << " to " << ptr->getData();

   if ( value == ptr->getData() )
   {
      cout << "; search complete\n";
      return ptr;
   }
   else if ( value < ptr->getData() )
   {
      cout << "; smaller, walk left\n";
      return binarySearchHelper( ptr->getLeftPtr(), value );
   }
   else
   {
      cout << "; larger, walk right\n";
      return binarySearchHelper( ptr->getRightPtr(), value );
   }
}

#endif
