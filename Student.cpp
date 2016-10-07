#include <iostream>
#include "Student.h"
using namespace std;


Student::Student()
{
   cout << "We are in the Student default Constructor\n";
   firstName = "John";
   lastName = "Doe";
}

Student::Student(char newName)
{
   cout << "We are in the newName student Constructor\n";
   lastName = "blah";
}

Student::Student(string fName, string lName)
{
   cout << "We are in the names student Constructor\n";
   firstName = fName;
   lastName = lName;
}

Student::Student(string lName)
{
   cout << "Only last name Constructor\n";
   firstName = "Blah";
   lastName = lName;
}

string Student::getLastName()
{
   return lastName;
}

string Student::getFirstName()
{
   return firstName;
}

void Student::displayLastName()
{
   cout << lastName << endl;
}

void Student::displayFull()
{
   cout << firstName << ", " << lastName << endl;
}
