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
      Node *getNextPtr();
      void setNextPtr(Node *);
      Student *getStudent();
   private:
      Node *next;
      Student *studentPtr;
};
#endif

/* Now how we do it with private data member pointers
We need to use get and set methods to interact with them

*/
