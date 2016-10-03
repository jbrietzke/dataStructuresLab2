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
   void deleteNode(Node *, char);
   Node *append(Node *, Node *);
   Node *head = NULL;
   Node *nptr = NULL;
   bool isDone = false;
   char item;

   // Creating our list
   do {
      cout << "Enter next item: ";
      cin >> item;
      if (item == '*')
      {
         isDone = true;
      }else{
         nptr = new Node(item);
         head = append(head, nptr);
      }
   }while(!isDone);
   display(head);
   deleteNode(head, 'b');
   // displaying list

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
void deleteNode(Node *head, char item)
{
   Node *curr = head;
   while(curr)
   {
      cout << "This is what is student: \n" << curr->getStudent() << endl;
      curr = curr->getNextPtr();
   }
}

/*
We will need to return head or pass by reference once again
Node *curr = head;
*prev = NULL;
while(curr){
   if(item == curr->getItem()){
   break;
   }
   prev = curr;
   curr = curr -> getNextPtr();
}

if(curr){
   if(prev){
      prev->setNextPtr(curr ->getNextPtr());
   }else{
      head = curr->getNextPtr();
   }

   curr -> nextPtr(NULL);
   delete curr;
   curr = NULL;
}

Make Head global possibly
Don't worry about student class
*/
