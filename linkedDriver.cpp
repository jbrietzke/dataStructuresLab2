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
   Node *insertedStudent = NULL;
   bool isValid = true;
   char toDelete;
   int age;
   string fName, lName;
   do
   {
      cout << "Enter names of students, age,  and *'s when you're done: \n";
      cin >> fName >> lName >> age;
      if (fName == "*" || lName == "*")
      {
         isValid = false;
      }else{
         newStudentPtr = new Student(fName,lName, age);
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
         cout << "Enter students name and age you want to delete: ";
         cin >> fName >> lName >> age;
         newStudentPtr = new Student(fName, lName, age);
         nptr = new Node(newStudentPtr);
         mainList->deleteNode(nptr);
      }
   }while(toDelete == 'y');
   do{
      cout << "Do you want to insert any students (y/n): ";
      cin >> toDelete;
      if (toDelete == 'y')
      {
         cout << "Enter students you want to insert and the student to whom they go before: ";
         cin >> fName >> lName >> age;
         newStudentPtr = new Student(fName, lName, age);
         cin >> fName >> lName >> age;
         nptr = new Node(newStudentPtr);
         newStudentPtr = new Student(fName, lName, age);
         insertedStudent = new Node(newStudentPtr);
         mainList->insertNode(nptr, insertedStudent);
      }
   }while(toDelete == 'y');
   mainList->orderByAge();
   cout << "This is the new list:\n";
   mainList->display();
   cout << "This is the original list:\n";
   copyList->display();
   delete mainList;
   mainList = NULL;
   return 0;
}

/*
Learning about File I/O
Cin works pretty much the same way with files
There are Sequential files, but to process it starts at beginning of file
There are Random Access Files, where you can go to a position to start reading
Each entry in a file is a record, each record is composed of fields

With each file we have the file pointer, that points to the current location of file
We can move the file pointer to some byte location of the file (seek)
You need to know how to manipulate files

We can read and write to a file
There is an ifstream and ofstream and fstream
Application needs to open the files we want to deal with

*/
