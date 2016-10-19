/*
This driver is to get to understand how all of this file I/O works
*/

#include <iostream>
#include <fstream>
#include "Node.cpp"
#include "Student.cpp"
#include "List.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
   string fName, lName;
   int age;
   List mainList;
   Node *newNodePtr = NULL;
   Student *newStudentPtr = NULL;
   string fileName;
   cout << "Enter the file you want: ";
   cin >> fileName;


   ifstream readText(fileName);
   // Alternatively use a custom constructor to pass in file
   // This is just opening the file
   while(!readText.eof())
   {
      age = -9999;
      readText >> fName >> lName >> age;
      if (age != -9999)
      {
         newStudentPtr = new Student(fName, lName, age);
         newNodePtr = new Node(newStudentPtr);
         mainList.append(newNodePtr);
      }
   }
   readText.close();
   mainList.orderByAge();
   mainList.display();


   // Now outputting
   ofstream writeText("data.txt");
   newNodePtr = mainList.getHead();
   while(newNodePtr != NULL)
   {
      writeText << newNodePtr->getStudent()->getAllInformation() << endl;
      newNodePtr = newNodePtr->getNextPtr();
   }
   return 0;
}

/*
For our lab we will do a while loop and creates students and Nodes
if.eof() this means end of file so it is true when there is nothing else
It would be a good idea to look up all the methods of the class

When writing to the file, do you want to be new or append
*/
