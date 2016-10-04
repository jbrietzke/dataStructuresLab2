#ifndef STUDENT_H
#define STUDENT_H

class Student
{
   public:
      Student();
      Student(char);
      ~Student();
      char getName();
      void setName(char);
   private:
      char name;
};
#endif
