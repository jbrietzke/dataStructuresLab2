#ifndef LIST_H
#define LIST_H

#include "Node.h"
class List
{
public:
   List();
   List(List copyingList);
   ~List();
   void append();
   void display();
private:
   Node *head;
   int numNodes;
};

#endif

/*
   The driver for this class will create a List than append Nodes to list
   List l;
   do {
      nptr = new Node()
      l.append(nptr)
   }
   l.display

   We need to think about Destructors now

   The Destructors of the Node class only delete the items they are pointing to

   Now lets think if we were copying a list.
   We need to create a different address location for head and different
      student objects for each student objects
      We need a deep copy

*/

