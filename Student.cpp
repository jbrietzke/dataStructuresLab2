#include <iostream>
#include "Student.h"
using namespace std;


Student::Student()
{
   cout << "We are in the Student default Constructor\n";
   name = '&';
}

Student::Student(char newName)
{
   cout << "We are in the newName student Constructor\n";
   name = newName;
}
