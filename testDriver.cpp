/*
This driver is to get to understand how all of this file I/O works
*/

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
   string fName;
   ifstream readText("data.txt");
   // Alternatively use a custom constructor to pass in file
   // This is just opening the file
   readText >> fName;
   cout << fName << endl;
   readText.close();

   // Now outputting
   ofstream writeText("data.txt");
   // This is appending
   writeText << "Brooms";
   return 0;
}

/*
For our lab we will do a while loop and creates students and Nodes
if.eof() this means end of file so it is true when there is nothing else
It would be a good idea to look up all the methods of the class

When writing to the file, do you want to be new or append
*/
