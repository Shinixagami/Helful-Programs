#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iomanip>

#include <algorithm>
using std::swap;

#include <string>
using std::string;

struct Student
{
  string  name;
  int     idNumber;
  float   gpa;
  Student *next;
};

void printStudents(Student *);

int main()
{
  Student *firstStudentPtr = 0, *lastStudentPtr = 0; // empty list with head and tail
  ifstream fin;
  fin.open("students.txt");
  while (fin.good())
  {
    string buf;
    getline(fin, buf); // could be the first attribute OR the "end-of-file" marker.
    if (fin.eof() || buf == "EOF") break;

    // use buf as the first attribute
    Student *temp = new Student;
    temp->name = buf;

    // read the remaining attributes
    fin >> temp->idNumber; fin.ignore(1000, 10);
    fin >> temp->gpa; fin.ignore(1000, 10);
    //...

    // link to the end of the list
    temp->next = 0;
    if (lastStudentPtr) lastStudentPtr->next = temp;
    else firstStudentPtr = temp;
    lastStudentPtr = temp;
  }
  fin.close( );
 
   // Print student list.  Note: list size is not required
  printStudents(firstStudentPtr);
  
  return 0;
}



/*************************************************************************
* Purpose:  Print student info in the linked list
* Parameter:
*   firstStudentPtr (IN) - pointer to the head of the list
*
* Return: None
**************************************************************************/
void printStudents(Student *firstStudentPtr)
{
  int index = 1;
  cout << "\nSeq.  Name             ID    GPA  " << endl;
  for (Student *nodePtr = firstStudentPtr; nodePtr; nodePtr = nodePtr->next, index++)
  {
   cout.width(5);
   cout << std::left << index;
   cout.width(18);
   cout << nodePtr->name; // (*nodePtr).name
   cout.width(6);
   cout << nodePtr->idNumber;
   cout.setf(ios::fixed); cout.precision(2);
   
   cout << nodePtr->gpa << endl;
  }
}


