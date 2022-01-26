#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output
using std::fstream;

#include <iostream>
using std::ios;

#include <string>
using std::string;

#include <cstring> // need it for strcpy


#define NAME_LENGTH  32

struct Student
{
  int age;
  char name[NAME_LENGTH];
  double gpa;
};

int main()
{
  int capacity = 2;
  Student *students = new Student[capacity]; // allocate memory for Student array
  int index = 0;
  int size = 0;
  Student *myClass; // pointer for dynamic array to read back data
  
  students[index].age = 21; 
  students[index].gpa = 3.80;
  // strncpy place null-termincated char at the end if source < length
  strncpy((students[index]).name, "Jane Smith", NAME_LENGTH-1);
  //strcpy((char *)&students[index].name, "Jane Smith");

  cout << "Here's our new student:\n";
  cout << "Name: " << students[index].name << endl;
  cout << "Age:  " << students[index].age << " years\n";
  cout << "GPA:  " << students[index].gpa << endl;
  
  index++;
  students[index].age = 19;
  students[index].gpa = 2.80;
  strncpy(students[index].name, "Joe Doe", NAME_LENGTH-1);
  
  cout << "Here's another new student:\n";
  cout << "Name: " << students[index].name << endl;
  cout << "Age:  " << students[index].age << " years\n";
  cout << "GPA:  " << students[index].gpa << endl;
  
  fstream fout;
  fout.open("studentList.dat", ios::binary|ios::out);
  // Write the array index
  // Cast to count the number of bytes
  size = index + 1;
  fout.write(reinterpret_cast<char*>(&size), sizeof(int));
  // Write data, cast tells write() to treat the next param as number of bytes
  fout.write(reinterpret_cast<char*>(students), (size) * sizeof(Student));
  fout.close(); // done with the file
  
  // Open the file for reading
  fstream fin;
  fin.open("studentList.dat", ios::binary|ios::in);
  if (fin.good())
  { 
    // Read the size of array
    fin.read(reinterpret_cast<char*>(&size), sizeof(int));
	myClass = new Student[size]; // allocate enough memory
	
	// Read entire file & save into Student array 
    fin.read(reinterpret_cast<char*>(myClass), (size) * sizeof(Student));
  }
  fin.close();
  
  cout << "\n---------Data from the binary file: \n";
  for (int i=0; i < size; i++)
  {
	cout << "Name: " << myClass[i].name << endl;
    cout << "Age:  " << myClass[i].age << " years\n";
    cout << "GPA:  " << myClass[i].gpa << endl;
	cout << endl;
  }
  
  return 0;
}