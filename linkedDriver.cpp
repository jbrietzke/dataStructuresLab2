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
   bool empty;
   mainList = new List();
   nptr = new Node();
   empty = mainList->isEmpty();
   cout << empty << endl;
   mainList->append(nptr);
   mainList->display();
   newStudentPtr = new Student("John", "Doe");
   nptr = new Node(newStudentPtr);
   mainList->display();
   empty = mainList->isEmpty();
   cout << empty << endl;
   delete mainList;
   mainList = NULL;
   return 0;
}
