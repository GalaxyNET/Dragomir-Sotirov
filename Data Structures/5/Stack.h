#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "Listnode.h"

template< typename STACKTYPE >
class Stack : private List< STACKTYPE >
{
public:
   void push( const STACKTYPE &data ) 
   { 
      this->insertAtFront( data );
   }

   bool pop( STACKTYPE &data ) 
   { 
      return this->removeFromFront( data );
   }

   bool isStackEmpty() const 
   { 
      return this->isEmpty();
   }
 
   void printStack() const 
   { 
      this->print();
   }
};

#endif
