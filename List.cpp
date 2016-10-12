#include "List.h"

List::List()
{
   head = NULL;
   numNodes = 0;
}

List::List(List const &copyingList)
{
   head = NULL;
   // traverse list copyingList
   // create a copyof each node
   // append new node to new list
}

void List::append(Node *newNode)
{
   cout << "We are in the append method\n";
   Node *curr = head;
   if (head == NULL)
   {
      head = newNode;
   }else{
      curr = head;
      while(curr->getNextPtr() != NULL){
         curr = curr->getNextPtr();
      }
      curr->setNextPtr(newNode);
   }
}

void List::display()
{
   Node *curr = head;
   while(curr)
   {
      curr->display();
      curr = curr->getNextPtr();
   }
}

void List::deleteNode(Node *toBeDeletedNode)
{
   cout << "We are in the delete method\n";
}
