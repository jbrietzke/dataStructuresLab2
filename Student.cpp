#include <iostream>
#include "Student.h"
using namespace std;


Student::Student()
{
   cout << "We are in the Student default Constructor\n";
   firstName = new string("John");
   lastName = new string("Doe");
}

Student::Student(char newName)
{
   cout << "We are in the newName student Constructor\n";
   lastName = new string("Blah");
}

Student::Student(string fName, string lName)
{
   cout << "We are in the names student Constructor\n";
   firstName = new string(fName);
   lastName = new string(lName);
}

Student::Student(string lName)
{
   cout << "Only last name Constructor\n";
   firstName = new string("Blah");
   lastName = new string(lName);
}

string Student::getLastName()
{
   return *lastName;
}

string Student::getFirstName()
{
   return *firstName;
}

void Student::displayLastName()
{
   cout << *lastName << endl;
}

void Student::displayFull()
{
   cout << *firstName << ", " << *lastName << endl;
}
