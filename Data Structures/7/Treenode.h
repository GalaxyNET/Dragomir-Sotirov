#ifndef TREENODE_H
#define TREENODE_H


template< typename NODETYPE > class Tree;  

template< typename NODETYPE >
class TreeNode 
{
   friend class Tree< NODETYPE >;
public:
   TreeNode( const NODETYPE &d )   
      : leftPtr( 0 ),
        data( d ),
        rightPtr( 0 )
   { 

   }

   NODETYPE getData() const 
   { 
      return data; 
   }
private:
   TreeNode< NODETYPE > *leftPtr;
   NODETYPE data;
   TreeNode< NODETYPE > *rightPtr;
};

#endif
