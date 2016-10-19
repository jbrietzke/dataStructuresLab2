/*
This is the driver program for the LinkedList
Here an initial list is created, added to, and then copied
It is a deep copy two separate instances of the lists
*/

#include <iostream>
#include <fstream>
#include "Node.cpp"
#include "Student.cpp"
#include "List.cpp"

int main(int argc, char const *argv[])
{
   List *mainList = new List();
   List *copyList = NULL;
   Node *newNodePtr = NULL;
   Student *newStudentPtr = NULL;
   Node *insertedStudent = NULL;
   bool isValid = true;
   char toChange, haveFile;
   int age;
   string fName, lName, fileName;

   cout << "Do you have a file to build your list from(y/n)?: ";
   cin >> haveFile;
   if (haveFile == 'y')
   {
      cout << "Enter the file you want: ";
      cin >> fileName;
      ifstream readText(fileName);
      while(!readText.eof())
      {
         age = -9999;
         readText >> fName >> lName >> age;
         if (age != -9999)
         {
            newStudentPtr = new Student(fName, lName, age);
            newNodePtr = new Node(newStudentPtr);
            mainList->append(newNodePtr);
         }
      }
   }else
   {
      do
      {
         cout << "Enter names of students, age,  and *'s when you're done: \n";
         cin >> fName >> lName >> age;
         if (fName == "*" || lName == "*")
         {
            isValid = false;
         }else{
            newStudentPtr = new Student(fName,lName, age);
            newNodePtr = new Node(newStudentPtr);
            mainList->append(newNodePtr);
         }
      }while(isValid);
   }
   mainList->orderByAge();
   mainList->display();
   copyList = new List(*mainList);
   do{
      cout << "Do you want to delete any students (y/n): ";
      cin >> toChange;
      if (toChange == 'y')
      {
         cout << "Enter students name and age you want to delete: ";
         cin >> fName >> lName >> age;
         newStudentPtr = new Student(fName, lName, age);
         newNodePtr = new Node(newStudentPtr);
         mainList->deleteNode(newNodePtr);
      }
   }while(toChange == 'y');
   do{
      cout << "Do you want to insert any students (y/n): ";
      cin >> toChange;
      if (toChange == 'y')
      {
         cout << "Enter students you want to insert and the student to whom they go before: ";
         cin >> fName >> lName >> age;
         newStudentPtr = new Student(fName, lName, age);
         cin >> fName >> lName >> age;
         newNodePtr = new Node(newStudentPtr);
         newStudentPtr = new Student(fName, lName, age);
         insertedStudent = new Node(newStudentPtr);
         mainList->insertNode(newNodePtr, insertedStudent);
      }
   }while(toChange == 'y');
   mainList->orderByAge();
   cout << "This is the new list:\n";
   mainList->display();
   cout << "This is the original list:\n";
   copyList->display();
   ofstream writeText(fileName);
   newNodePtr = mainList->getHead();
   cout << "The file you inputted is being adjusted\n";
   while(newNodePtr != NULL)
   {
      writeText << newNodePtr->getStudent()->getAllInformation() << endl;
      newNodePtr = newNodePtr->getNextPtr();
   }
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
