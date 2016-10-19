#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
class Student
{
   public:
      Student();
      Student(char);
      Student(string, string, int);
      Student(string);
      ~Student();
      string getLastName();
      string getFirstName();
      int getAge();
      void displayLastName();
      void displayFull();
   private:
      string *firstName, *lastName;
      int *age;
};
#endif
