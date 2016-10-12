#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "Student.h"
#include "Student.cpp"
#include "List.h"
#include "List.cpp"

int main(int argc, char const *argv[])
{
   List *mainList = NULL;
   Node *nptr = NULL;
   mainList = new List();
   nptr = new Node();
   mainList->append(nptr);
   mainList->display();
   return 0;
}
