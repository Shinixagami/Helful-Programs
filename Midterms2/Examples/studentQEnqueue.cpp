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
void enqueue(Student *&head, Student *&tail, Student *nodePtr);
Student *dequeue(Student *&head, Student *&tail);

int main()
{
  Student *firstStudentPtr = nullptr,
          *lastStudentPtr = nullptr;
  
  // Read student structs and create a queue
  ifstream fin;
  fin.open("students.txt");
  while (fin.good( ))
  {
    string buf;
    getline(fin, buf); // could be a name or could be EOF
    if (buf == "EOF") break;
 
    Student* temp = new Student; // buf's not EOF, so make a new node
    temp->name = buf; // if buf's not EOF, then it's a new name
    fin >> temp->idNumber; fin.ignore(200, '\n');
    fin >> temp->gpa; fin.ignore(200, '\n'); 
	temp->next = nullptr;
	
    if (!firstStudentPtr) firstStudentPtr = temp;
	
	// Update the tail
    if (lastStudentPtr) lastStudentPtr->next = temp;
	lastStudentPtr = temp;
  }
  fin.close( );
  
  printStudents(firstStudentPtr);
  
  // Add node at the end
  Student alexa {"Alexa Amazon", 9898, 3.5f};
  
  enqueue(firstStudentPtr, lastStudentPtr, &alexa);
  
  cout << "\n After enqueue:";
  printStudents(firstStudentPtr);
  
  Student *node;
  node = dequeue(firstStudentPtr, lastStudentPtr);
  
  cout << "dequeue student: " << node->name << ", " << node->idNumber << endl;
  
  cout << "\n After dequeue:";
  printStudents(firstStudentPtr);
	
  return 0;
}


/************************************************************
*  Purpose: Place the new node at the end of the queue
*  Parameters:
*      head - address of the head of the queue
*      tail - address of the tail of the queue
*      nodePtr - address of the new node containing data
*  Return: none
**********************************************************/
void enqueue(Student *&head, Student *&tail, Student *nodePtr)
{
  Student *temp = new Student;
  temp->name = nodePtr->name;
  temp->idNumber = nodePtr->idNumber;
  temp->gpa = nodePtr->gpa;
  temp->next = 0;
  
  // Why?
  if (head == nullptr)
  {
	  head = temp;
	  tail = temp;
  }
  else 
  {
	  tail->next = temp; // link old tail to new node
	  tail = temp;   // set tail to new node
  }
}


/************************************************************
*  Purpose: Remove the head of the queue
*  Parameters:
*      head - address of the head of the queue
*      tail - address of the tail of the queue
*
*  Return: the address of the head of the queue
**********************************************************/
Student *dequeue(Student *&head, Student *&tail)
{
	Student *temp;
	
	// Why/what do we check for this?
	if (!head || !tail)
		return nullptr;
	
	temp = head;

	// Why?
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
	}
    
	return temp;
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


