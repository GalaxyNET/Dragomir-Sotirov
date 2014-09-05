#ifndef LIST2_H
#define LIST2_H

#include <iostream> 
#include <new>
#include "ListNode.h"
#include "List.h"
using namespace std;

template< typename NODETYPE >
class List2 : public List< NODETYPE > 
{
public:
   NODETYPE *searchList( NODETYPE & ) const;
private:
   NODETYPE *recursiveSearchHelper( ListNode< NODETYPE > *, NODETYPE & ) const;
};

template< typename NODETYPE >
NODETYPE *List2< NODETYPE >::searchList( NODETYPE &val ) const
{ 
   return recursiveSearchHelper( this->firstPtr, val );
}

template< typename NODETYPE >
NODETYPE *List2< NODETYPE >::recursiveSearchHelper( ListNode< NODETYPE > *currentPtr, NODETYPE &value ) const
{
   if ( currentPtr == 0 )
      return 0;

   if ( currentPtr->getData() == value )
      return currentPtr->getAddress();

   return recursiveSearchHelper( currentPtr->getNextPtr(), value );
}

#endif
