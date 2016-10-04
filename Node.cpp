#include "Node.h"
#include <iostream>
using namespace std;

Node::Node()
{
   cout << "We are in the default constructor";
   next = NULL;
   item = '&';
   studentPtr = new Student();
}

Node::Node(char x)
{
   cout << "We are in the Node character constructor: " << x << endl;
   next = NULL;
   item = x;
   studentPtr = new Student(x);
}

Node::~Node()
{
   cout << "We are being destroyed\n";
   next = NULL;
}

void Node::display()
{
   //cout << "We are displaying the student name: " << studentPtr->getName() << endl;
   cout << "We are displaying the item: " << item << endl;
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

char Node::getItem()
{
   return item;
}
