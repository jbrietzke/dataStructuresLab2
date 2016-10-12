#include "Node.h"
#include <iostream>
using namespace std;

Node::Node()
{
   next = NULL;
   studentPtr = new Student();
}

Node::Node(char x)
{
   next = NULL;
   studentPtr = new Student(x);
}

Node::Node(Student *newStudent)
{
   next = NULL;
   studentPtr = newStudent;
}

Node::~Node()
{
   cout << "We are in the Node destructor\n";
   delete next;
   delete studentPtr;
   next = NULL;
   studentPtr = NULL;
}

void Node::display()
{
   studentPtr->displayFull();
}

Node *Node::getNextPtr()
{
   return next;
}

void Node::setNextPtr(Node *theNextPtr)
{
   next = theNextPtr;
}

Student * Node::getStudent()
{
   return studentPtr;
}
