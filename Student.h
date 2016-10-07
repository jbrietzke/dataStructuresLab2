#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
class Student
{
   public:
      Student();
      Student(char);
      Student(string, string);
      Student(string);
      ~Student();
      string getLastName();
      string getFirstName();
      void displayLastName();
      void displayFull();
   private:
      string firstName, lastName;
};
#endif
