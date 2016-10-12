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
   cout << "We are in the display method\n";
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
   Node *curr = head;
   Node *prev = NULL;
   bool didDelete = false;
   while(curr)
   {
      if(toBeDeletedNode->getStudent()->getLastName() == curr->getStudent()->getLastName())
      {
         didDelete = true;
         break;
      }
      prev = curr;
      curr = curr->getNextPtr();
   }

   if(curr)
   {
      if(prev)
      {
         prev->setNextPtr(curr->getNextPtr());
      }else
      {
         head = curr->getNextPtr();
      }

      curr->setNextPtr(NULL);
      delete curr;
      curr = NULL;
   }
   if (didDelete)
   {
      this->deleteNode(toBeDeletedNode);
   }
}
