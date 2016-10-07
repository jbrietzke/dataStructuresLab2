/* Creating the linkedList
To traverse a linkedList create a new pointer that is equal to head
Then do a while list with the curr pointer as the limit
We need to always create a separate pointer to traverse the list
Curr is industry best practice because it is clear
Prev is also important because keeps track of previous



In the deault constructor the Node's next pointer must be initialized to NULL
When creating the new Node is does not know what is pointing to

*/

#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "Student.cpp"
using namespace std;

int main()
{
   // This is a pointer to a Node and located on the stack undefined
   //So we set it to NULL so we know what is there
   // using  a prev pointer is very useful in implementation
   void display(Node *);
   Node *deleteNode(Node *, Student *);
   Node *append(Node *, Node *);
   Node *insertNode(Node *, Node *, string);
   Node *head = NULL;
   Node *nptr = NULL;
   Student *studentPtr = NULL;
   bool isDone = false;
   char item;
   string firstName, lastName, itemInsertBefore;

   // Creating our list
   do {
      cout << "Enter next student (first name then last name): ";
      cin >> firstName >> lastName;
      studentPtr = new Student(firstName, lastName);
      if (firstName == "*" || lastName == "*")
      {
         isDone = true;
      }else{
         nptr = new Node(studentPtr);
         head = append(head, nptr);
      }
   }while(!isDone);
   display(head);
   do
   {
      cout << "Would you like to delete('d') or insert('i') in the list or not('*'): ";
      cin >> item;
      if (item == 'd')
      {
         cout << "Enter the last name of the person you would like to delete: ";
         cin >> lastName;
         studentPtr = new Student(lastName);
         head = deleteNode(head, studentPtr);
         display(head);
      }else if (item == 'i')
      {
         cout << "Enter the last name you would like to insert before and then the person you would like to insert: ";
         cin >> itemInsertBefore >> firstName >> lastName;
         studentPtr = new Student(firstName, lastName);
         nptr = new Node(studentPtr);
         head = insertNode(head, nptr, itemInsertBefore);
         display(head);
      }
   }while(item != '*');
   cout << "Thank you for using the application, here is your final report\n";
   display(head);
   return 0;
}

// Curr is passed by value so we can mutilate it or not
void display(Node *head)
{
   Node *curr = head;
   while(curr)
   {
      curr->display();
      curr = curr->getNextPtr();
   }
}

//passing by reference or making it a global variable is a little more approprite
Node *append(Node *head, Node *nptr)
{
   Node *curr = head;
   if (head == NULL)
   {
      head = nptr;
   }else{
      curr = head;
      while(curr->getNextPtr() != NULL){
         curr = curr->getNextPtr();
      }
      curr->setNextPtr(nptr);
   }
   return head;
}

//delete by item type
Node *deleteNode(Node *head, Student *deleteableStudent)
{
   Node *curr = head;
   Node *prev = NULL;
   bool didDelete = false;
   while(curr)
   {
      if(deleteableStudent->getLastName() == curr->getStudent()->getLastName())
      {
         didDelete = true;
         break;
      }
      prev = curr;
      curr = curr->getNextPtr();
   }

   if(curr)
   {
      if(prev)
      {
         prev->setNextPtr(curr->getNextPtr());
      }else
      {
         head = curr->getNextPtr();
      }

      curr->setNextPtr(NULL);
      delete curr;
      curr = NULL;
   }
   if (didDelete)
   {
      head = deleteNode(head, deleteableStudent);
   }
   return head;
}
// We are inserting after this item
Node *insertNode(Node *head, Node *newNode, string name)
{
   Node *curr = head;
   Node *prev = NULL;
   while(curr)
   {
      if (curr->getStudent()->getLastName() == name)
      {
         break;
      }
      else
      {
         prev = curr;
         curr = curr->getNextPtr();
      }
   }
   if (curr)
   {
      if (curr == head)
      {
         prev = head;
         head = newNode;
         newNode->setNextPtr(prev);
      }
      else
      {
         prev->setNextPtr(newNode);
         newNode->setNextPtr(curr);
      }
   }
   return head;
}

