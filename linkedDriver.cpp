#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "Student.h"
#include "Student.cpp"
#include "List.h"
#include "List.cpp"

int main(int argc, char const *argv[])
{
   List *mainList = new List();
   List *copyList = NULL;
   Node *nptr = NULL;
   Student *newStudentPtr = NULL;
   int counter = 0;
   string fName, lName;
   while(counter < 3)
   {
      cin >> fName >> lName;
      newStudentPtr = new Student(fName,lName);
      nptr = new Node(newStudentPtr);
      mainList->append(nptr);
      counter++;
   }
   newStudentPtr = new Student("Jackson", "Brooms");
   nptr = new Node(newStudentPtr);
   copyList = new List(*mainList);
   mainList->deleteNode(nptr);
   mainList->display();
   copyList->display();
   // copyList = new List(*mainList);
   // copyList->display();
   // mainList->display();
   // newStudentPtr = new Student("Jackson", "Brooms");
   // nptr = new Node(newStudentPtr);
   // mainList->deleteNode(nptr);
   // copyList->display();
   // mainList->display();
   delete mainList;
   mainList = NULL;
   return 0;
}
