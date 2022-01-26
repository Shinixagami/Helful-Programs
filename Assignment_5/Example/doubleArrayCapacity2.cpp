#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <string>
using std::string;

struct Student
{
  char grade;
  char course[13];
  int unit;
};

// Using C++ pass-by-refewnce
void doubleArrayCapacity(Student *&, int&); // the prototype

int main()
{
  int capacity = 3;
  Student *myClass = new Student[capacity];

  // Double the array capacity
  doubleArrayCapacity(myClass, capacity);
}

void doubleArrayCapacity(Student *&studentArray, int &capacity)
{
  Student *temp = new Student[2 * capacity]; // new, temporary array
  for (int i = 0; i < capacity; i++) // copy from the original array...
    temp[i] = studentArray[i]; // ...to the new, temporary array

  delete [] studentArray; // release the original array back to the system
  studentArray = temp; // forget where the original was -- remember the new...
  capacity *= 2; // ...and its capacity
}

