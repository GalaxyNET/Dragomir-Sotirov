#ifndef LIST2_H
#define LIST2_H

#include <iostream> 
#include "ListNode.h"
#include "List.h"
using namespace std;

template< typename NODETYPE >
class List2 : public List< NODETYPE > 
{
public:
   void recursivePrintReverse() const;
private:
   void recursivePrintReverseHelper( ListNode< NODETYPE > * ) const;
};

template< typename NODETYPE >
void List2< NODETYPE >::recursivePrintReverse() const
{
   cout << "The list printed recursively backward is:\n";
   recursivePrintReverseHelper( this->firstPtr );
   cout << '\n';
}

template< typename NODETYPE >
void List2< NODETYPE >::recursivePrintReverseHelper( 
   ListNode< NODETYPE > *currentPtr ) const
{
   if ( currentPtr == 0 )
      return;
      
   recursivePrintReverseHelper( currentPtr->getNextPtr() );
   cout << currentPtr->getData() << ' ';
}

#endif
