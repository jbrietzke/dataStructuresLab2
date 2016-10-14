/*
This is the List Class Header File
Here the declarations are made for the List class
*/
#ifndef LIST_H
#define LIST_H

#include "Node.h"
class List
{
public:
   List();
   List(List const &);
   ~List();
   void append(Node *);
   void display();
   void deleteNode(Node *);
   void insertNode(Node *, Node *);
   Node *getHead() const;
   int getNumNodes();
   bool isEmpty();
private:
   Node *head;
   int numNodes;
};

#endif
