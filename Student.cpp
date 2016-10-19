#include <iostream>
#include "Student.h"
using namespace std;


Student::Student()
{
   firstName = new string("John");
   lastName = new string("Doe");
   age = new int(99);
}

Student::Student(char newName)
{
   lastName = new string("Blah");
}

Student::Student(string fName, string lName, int theirAge)
{
   firstName = new string(fName);
   lastName = new string(lName);
   age = new int(theirAge);
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
   cout << *firstName << ", " << *lastName << "," << *age << endl;
}

int Student::getAge()
{
   return *age;
}

string Student::getAllInformation()
{
   string stringAge = to_string(*age);
   string total = *firstName + " " + *lastName + " " + stringAge + " ";
   return total;
}
