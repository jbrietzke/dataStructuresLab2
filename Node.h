#ifndef NODE_H
#define NODE_H
#include "Student.h"
class Node
{
   public:
      Node();
      Node(char);
      ~Node();
      void display();
      Node *next;
      Student *studentPtr;
   private:

};
#endif
