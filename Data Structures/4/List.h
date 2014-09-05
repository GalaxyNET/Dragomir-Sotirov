#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include <new>
#include "ListNode.h"

using namespace std;

template< typename NODETYPE >
class List 
{
public:
   List();
   List( const List< NODETYPE > & );
   ~List();

   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;
protected:
   ListNode< NODETYPE > *firstPtr;
   ListNode< NODETYPE > *lastPtr;

   ListNode< NODETYPE > *getNewNode( const NODETYPE & );
};

template< typename NODETYPE >
List< NODETYPE >::List() 
{ 
   firstPtr = lastPtr = 0; 
}

template< typename NODETYPE >
List< NODETYPE >::List( const List<NODETYPE> &copy )
{
   firstPtr = lastPtr = 0;

   ListNode< NODETYPE > *currentPtr = copy.firstPtr;

   while ( currentPtr != 0 ) 
   {
      insertAtBack( currentPtr->data );
      currentPtr = currentPtr->nextPtr;
   }
}

template< typename NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() )
   {

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )
      {
         tempPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      }
   }

}

template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode<NODETYPE> *newPtr = getNewNode( value );

   if ( isEmpty() )
      firstPtr = lastPtr = newPtr;
   else
   {
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;
   }
}

template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )
      firstPtr = lastPtr = newPtr;
   else
   {
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;
   }
}

template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )
      return false;
   else 
   {
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;

      delete tempPtr;
      return true;
   }
}

template< typename NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;
   else 
   {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else 
      {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;
      }

      value = tempPtr->data;
      delete tempPtr;
      return true;
   }
}

template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
}

template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
   const NODETYPE &value)
{
   ListNode< NODETYPE > *ptr = new ListNode< NODETYPE >( value );
   return ptr;
}

template< typename NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() )
   {
      cout << "The list is empty\n\n";
      return;
   }

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 )
   {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;
   }

   cout << "\n\n";
}

#endif
