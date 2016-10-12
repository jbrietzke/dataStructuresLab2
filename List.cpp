#include "List.h"

List::List()
{
   head = NULL;
   numNodes = 0;
}

List::List(List const &copyingList)
{

   Node *holder = NULL;
   Node *curr = copyingList.getHead();
   Student *newStudent = NULL;
   while(curr != NULL)
   {
      newStudent = new Student(curr->getStudent()->getFirstName(), curr->getStudent()->getLastName());
      holder = new Node(newStudent);
      append(holder);
      curr = curr->getNextPtr();
   }

   // traverse list copyingList
   // create a copyof each node
   // append new node to new list
}

List::~List()
{
   delete head;
   head = NULL;
}

void List::append(Node *newNode)
{
   Node *curr = NULL;
   curr = head;
   if (head == NULL)
   {
      head = newNode;
   }else{
      //curr = head;
      while(curr->getNextPtr() != NULL){
         curr = curr->getNextPtr();
      }
      curr->setNextPtr(newNode);
   }
   numNodes++;
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
      deleteNode(toBeDeletedNode);
   }
}

int List::getNumNodes()
{
   return numNodes;
}

bool List::isEmpty()
{
   return (head == NULL) ? true:false;
}

Node *List::getHead() const
{
   return head;
}
