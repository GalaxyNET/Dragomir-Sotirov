#ifndef TREENODE_H
#define TREENODE_H

template< typename T > class Tree;

template< typename NODETYPE >
class TreeNode 
{
   friend class Tree< NODETYPE >;
public:
   TreeNode( const NODETYPE & );
   NODETYPE getData() const;

   TreeNode *getLeftPtr() const 
   { 
      return leftPtr; 
   }
   
   TreeNode *getRightPtr() const 
   { 
      return rightPtr; 
   }

   void setLeftPtr( TreeNode *ptr ) 
   { 
      leftPtr = ptr; 
   }
   
   void setRightPtr( TreeNode *ptr ) 
   { 
      rightPtr = ptr; 
   }
private:
   TreeNode *leftPtr;
   NODETYPE data;
   TreeNode *rightPtr;
};

template< typename NODETYPE >
TreeNode< NODETYPE >::TreeNode( const NODETYPE &d )
{
   data = d;
   leftPtr = rightPtr = 0;
}

template< typename NODETYPE >
NODETYPE TreeNode< NODETYPE >::getData() const 
{ 
   return data; 
}

#endif
