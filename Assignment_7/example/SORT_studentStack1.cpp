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
  Student *firstStudentPtr = NULL; // an empty linked list, C++11: nullptr
  
  // Read student structs and create a stack
  ifstream fin;
  fin.open("students.txt");
  while (fin.good( ))
  {
    string buf;
    getline(fin, buf); // could be a name or could be EOF
    if (buf == "EOF" || fin.eof()) break;
 
    Student* temp = new Student; // buf's not EOF, so make a new node
    temp->name = buf;  // (*temp).name  // if buf's not EOF, then it's a new name
    fin >> temp->idNumber; fin.ignore(1000, 10); // ...and so on, for each attribute

    temp->next = firstStudentPtr; // this is the "stack" part...
    firstStudentPtr = temp; //...putting the node at the head
  }
  fin.close( );
  
  
  // Output student stack to file
  ofstream fout;
  fout.open("students2.txt");
  for (Student *p = firstStudentPtr; p; p = p->next)
  {
    // output each attribute on its own line
    fout << p->name << '\n';
    fout << p->idNumber << '\n';
  }
  fout << "EOF\n"; // mark the end of the list
  fout.close( );
  
  

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


