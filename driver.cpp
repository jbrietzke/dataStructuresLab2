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
   Node *head = NULL;
   Node *nptr = NULL;
   Node *prev = NULL;
   Node *curr = NULL;
   Node *newPointer;
   bool isDone = false;
   char item;
   newPointer = NULL;
   // Creating our list
   do {
      cout << "Enter next item: ";
      cin >> item;
      if (item == '*')
      {
         isDone = true;
      }else{
         nptr = new Node(item);
         if (head == NULL)
         {
            head = nptr;
         }else{
            curr = head;
            while(curr->next != NULL){
               curr = curr->next;
            }
            curr->next = nptr;
         }
      }
   }while(!isDone);

   // displaying list
   curr = head;
   while(curr != NULL)
   {
      curr->display();
      curr = curr->next;
   }
   return 0;
}


/*
Node curr;
   char item;
   // This will create a new Node on the heap that head points to
   nptr = new Node('A');
   head = nptr;
   prev = nptr;
   prev.next = nptr;
   nptr = new Node('B');
   prev = nptr;
   prev.next = nptr;
   nptr = new Node('C');

   do {
      cout << "Enter next item: ";
      cin >> item;
      if (item == '*')
      {
         done = false;
      }else{
         nptr = new Node(item);
         if (head == NULL)
         {
            head = nptr;
         }else{
            curr = head;
            while(curr->next != NULL){
               curr = curr->next;
            }
            curr->next = nptr;
         }
      }
   }
*/
