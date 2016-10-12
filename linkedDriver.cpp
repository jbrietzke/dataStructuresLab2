/*
This is the driver program for the LinkedList
Here an initial list is created, added to, and then copied
It is a deep copy two separate instances of the lists
*/

#include <iostream>
#include "Node.cpp"
#include "Student.cpp"
#include "List.cpp"

int main(int argc, char const *argv[])
{
   List *mainList = new List();
   List *copyList = NULL;
   Node *nptr = NULL;
   Student *newStudentPtr = NULL;
   bool isValid = true;
   char toDelete;
   string fName, lName;
   do
   {
      cout << "Enter names of students and *'s when you're done: \n";
      cin >> fName >> lName;
      if (fName == "*" || lName == "*")
      {
         isValid = false;
      }else{
         newStudentPtr = new Student(fName,lName);
         nptr = new Node(newStudentPtr);
         mainList->append(nptr);
      }
   }while(isValid);
   mainList->display();
   copyList = new List(*mainList);
   do{
      cout << "Do you want to delete any students (y/n): ";
      cin >> toDelete;
      if (toDelete == 'y')
      {
         cout << "Enter students name you want to delete: ";
         cin >> fName >> lName;
         newStudentPtr = new Student(fName, lName);
         nptr = new Node(newStudentPtr);
         mainList->deleteNode(nptr);
      }
   }while(toDelete == 'y');

   cout << "This is the new list:\n";
   mainList->display();
   cout << "This is the original list:\n";
   copyList->display();
   delete mainList;
   mainList = NULL;
   return 0;
}
