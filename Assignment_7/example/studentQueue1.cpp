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

void sortList(Student *);
void printStudents(Student *);

int main()
{
  Student *firstStudentPtr = NULL, // an empty linked list, C++11: nullptr
          *lastStudentPtr = NULL;
		   
  // Read student structs and create a stack
  ifstream fin;
  fin.open("students.txt");
  while (fin.good( ))
  {
    string buf;
    getline(fin, buf); // could be a name or could be EOF
    if (buf == "EOF") break;
 
    Student* temp = new Student; // buf's not EOF, so make a new node
    temp->name = buf; // if buf's not EOF, then it's a new name
    fin >> temp->idNumber; fin.ignore(1000, 10); // ...and so on, for each attribute

    temp->next = firstStudentPtr; // this is the "stack" part...
    firstStudentPtr = temp; //...putting the node at the head
  }
  fin.close( );
  
  
  // Traverse to end of list.  But doesn't work
  //Student* p;
  //for (p = firstStudentPtr; p; p = p->next);
  
  // Traverse to end of list
  Student *p, *prev; // yes, this is the correct way to declare two pointers
  int i = 0;
  for (p = firstStudentPtr, prev = 0; p; prev = p, p = p->next, i++)
	  if (i == 1) break;

  Student *temp = new Student;
  // Initialize data to temp
  // ...
  
  // Add a node at the end of the list (FIFO)
  temp->next = 0;
  if (prev) prev->next = temp;
  else firstStudentPtr = temp;
  
  // Keep track of the tail
  lastStudentPtr = temp;
  
  // Removing a node
  if (prev) prev->next = p->next; // skips over the node at p
  else firstStudentPtr = p->next; // there's a new head, possibly zero
  delete p; // we're done with this node
  if (p == lastStudentPtr) lastStudentPtr = prev; // that's the 1st if...
  
  return 0;
}

/*************************************************************************
* Purpose:  Sort the list in alphabetical order
* Parameter:
*   firstStudentPtr (IN) - pointer to the head of the list
*
* Return: None
**************************************************************************/
void sortList(Student *firstStudentPtr)
{
  for (Student *p = firstStudentPtr; p; p = p->next)
    for (Student* q = p->next; q; q = q->next)
      if (q->name < p->name)
	  {
        // swap entire content
		swap(*p, *q);
		
        // swap ptr to original value
		 swap(p->next, q->next);
	  }
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


