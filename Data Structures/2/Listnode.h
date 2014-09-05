#ifndef LISTNODE_H
#define LISTNODE_H

template< typename D > class List;

template< typename NODETYPE >
class ListNode 
{
   friend class List< NODETYPE >;
public:
   ListNode( const NODETYPE & );
   NODETYPE getData() const;

   void setNextPtr( ListNode *nPtr ) 
   { 
      nextPtr = nPtr; 
   }
   
   ListNode *getNextPtr() const 
   { 
      return nextPtr; 
   }

private:
   NODETYPE data;
   ListNode *nextPtr;
};

template< typename NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
{
   data = info;
   nextPtr = 0;
}

template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
}

#endif
