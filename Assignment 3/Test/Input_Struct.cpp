#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

struct Student
{
  int age;
  string name;
};

int main()
{

    string Iname1;

    cout << "please enter student name 1 :" << endl;
    cin >> Iname1;

  Student john; // declare the struct-based object

  john.age = 21; // assigning a value to an attribute
  john.name = Iname1;

  cout << "Here's our new student:\n";
  cout << "Name: " << john.name << endl;
  cout << "Age:  " << john.age << " years\n";


  // declare structure base object ( input age, input age);
  Student jane {19, "Jane Smith"};  // C++ 11 only

  // jane = {19, "Jane Smith"};      // C++ 11 only
  cout << "Name: " << jane.name << endl;
  cout << "Age:  " << jane.age << " years\n";


//try to understand this .

  Student joe = {23};   // incomplete initialization, it's OK

  Student matt = {45};  // What is it?

}
