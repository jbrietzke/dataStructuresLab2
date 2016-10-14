/*
Here are the List Class' Method Definitions
*/

#include "List.h"

List::List()
{
   head = NULL;
   numNodes = 0;
}
// Makes a deap copy of the list passed to it
List::List(List const &copyingList)
{
   head = NULL;
   numNodes = 0;
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
}
// Clears Node on the heap
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

void List::insertNode(Node *nodeToBeInsertedBefore, Node *nodeAfter)
{
   cout << "insertingNode";
   Node *curr = head;
   Node *prev = NULL;
   while(curr)
   {
      if (curr->getStudent()->getLastName() == nodeAfter->getStudent()->getLastName())
      {
         break;
      }
      else
      {
         prev = curr;
         curr = curr->getNextPtr();
      }
   }
   if (curr)
   {
      if (curr == head)
      {
         prev = head;
         head = nodeToBeInsertedBefore;
         nodeToBeInsertedBefore->setNextPtr(prev);
      }
      else
      {
         prev->setNextPtr(nodeToBeInsertedBefore);
         nodeToBeInsertedBefore->setNextPtr(curr);
      }
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
