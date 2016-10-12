#include <iostream>
#include "Student.h"
using namespace std;


Student::Student()
{
   firstName = new string("John");
   lastName = new string("Doe");
}

Student::Student(char newName)
{
   lastName = new string("Blah");
}

Student::Student(string fName, string lName)
{
   firstName = new string(fName);
   lastName = new string(lName);
}

Student::Student(string lName)
{
   firstName = new string("Blah");
   lastName = new string(lName);
}

Student::~Student()
{
   delete firstName;
   delete lastName;
   firstName = NULL;
   lastName = NULL;
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
