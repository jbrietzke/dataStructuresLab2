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
   Student *newStudentPtr = NULL;
   mainList = new List();
   nptr = new Node();
   mainList->append(nptr);
   mainList->display();
   newStudentPtr = new Student("John", "Doe");
   nptr = new Node(newStudentPtr);
   mainList->deleteNode(nptr);
   mainList->display();
   return 0;
}
