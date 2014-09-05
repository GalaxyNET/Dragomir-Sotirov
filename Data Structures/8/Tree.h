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
   int getDepth() const;
protected:
   TreeNode<NODETYPE> *rootPtr;
private:
   void insertNodeHelper( TreeNode< NODETYPE > **, const NODETYPE & );
   void preOrderHelper( TreeNode< NODETYPE > * ) const;
   void inOrderHelper( TreeNode< NODETYPE > * ) const;
   void postOrderHelper( TreeNode< NODETYPE > * ) const;
   void determineDepth( TreeNode< NODETYPE > *, int *, int * ) const;
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
int Tree< NODETYPE >::getDepth() const
{
   int totalDepth = 0;
   int currentDepth = 0;

   determineDepth( rootPtr, &totalDepth, &currentDepth );
   return totalDepth;
}

template< typename NODETYPE >
void Tree< NODETYPE >::determineDepth( TreeNode< NODETYPE > *ptr,
   int *totPtr, int *currPtr ) const
{   
   if ( ptr != 0 )
   {
      ( *currPtr )++;

      if ( *currPtr > *totPtr )
         *totPtr = *currPtr;

      determineDepth( ptr->getLeftPtr(), totPtr, currPtr );
      determineDepth( ptr->getRightPtr(), totPtr, currPtr );
      ( *currPtr )--;
   }
}

#endif
