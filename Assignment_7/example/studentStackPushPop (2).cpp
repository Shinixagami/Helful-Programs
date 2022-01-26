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
void push(Student *&head, Student *nodePtr);
Student *pop(Student *&head);
Student *peek(Student *);
bool isEmpty(Student *);

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
    fin >> temp->idNumber; fin.ignore(1000, '\n'); // ...and so on, for each attribute
    fin >> temp->gpa; fin.ignore(1000, '\n'); // ...and so on, for each attribute

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

  cout << "Before push(): ";
  printStudents(firstStudentPtr);

  Student jane {"Jane Smith", 47652, (float)3.85}; // or 3.85f

  push(firstStudentPtr, &jane);

  cout << "\n After push 1: ";
  printStudents(firstStudentPtr);

  Student alexa {"Alexa Amazon", 9898, (float)3.5};

  push(firstStudentPtr, &alexa);

  cout << "\n After push 2: ";
  printStudents(firstStudentPtr);

  Student *node = peek(firstStudentPtr);
  cout << "\nPeek top node data: ";
  cout << node->name << "\t" << node->idNumber << endl;

  Student *popNode = pop(firstStudentPtr);
  cout << "\nPopNode data: ";
  cout << popNode->name << "\t" << popNode->idNumber << endl;
  delete popNode;

  cout << "\n After pop 1: ";
  printStudents(firstStudentPtr);

  popNode = pop(firstStudentPtr);
  cout << "\nPopNode data: ";
  cout << popNode->name << "\t" << popNode->idNumber << endl;
  delete popNode;

  cout << "\n After pop 2: ";
  printStudents(firstStudentPtr);

  return 0;
}


// Add a new node to the beginning of the list
void push(Student *&head, Student *nodePtr)
{
  Student* temp = new Student; // why allocate new node?

  temp->name = nodePtr->name;

  temp->idNumber = nodePtr->idNumber;
  temp->gpa = nodePtr->gpa;

  // link the new node into the list
  temp->next = head;
  head = temp;
}


/*************************************************************************
* Purpose:  Remove the top element of the stack
* Parameter:
*   head (IN) - pointer to the head of the list
*
* Return: address of the top element
**************************************************************************/
Student *pop(Student *&head)
{
   Student *temp;

   temp = head;

   //delete head;
   head = head->next;

   return temp;
}


/*************************************************************************
* Purpose:  Return top element of the stack
* Parameter:
*   head (IN) - pointer to the head of the list
*
* Return: address of the top element
**************************************************************************/
Student *peek(Student *head)
{
   if (head)
      return head;
   else
      return nullptr;
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


