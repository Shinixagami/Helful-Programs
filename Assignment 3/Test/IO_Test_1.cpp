#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output


#include <string>
using std::string;


//functions
void CallStudent (double age);

struct Student   //structure name
{
  int age;        // variables
  string name;    //variable
  double gpa;   //variable
  string major;   //M
  string year;    //Y
  //int grade;
};

int main()
{
    string Minput, Yinput, Ninput ;

    cout << "enter student name: " << endl;

    cin >> Ninput ;

    cout << "student name: " << Ninput << endl << endl ;


  Student StudentOne; // declare the struct-based object
  StudentOne.age = 21; // assigning a value to an attribute
  StudentOne.name = Ninput ;
  StudentOne.gpa = 3.8;

  cout << "Here's our new student:\n";
  cout << "Name: " << StudentOne.name << endl;
  cout << "Age:  " << StudentOne.age << " years\n";
  cout << "GPA:  " << StudentOne.gpa << endl << endl;

/*
  cout << "Student One \n";
  Student StudentTwo {21, "Aki", 3.5};
  cout << "Name: " << StudentTwo.name << endl;
  cout << "Age:  " << StudentTwo.age << " years\n";
  cout << "GPA:  " << StudentTwo.gpa << endl <<endl;

 cout << "Student Jane \n";
  Student jane {18, "Jane Smith", 3.4};  // C++ 11 only
  //jane = {19, "Jane Smith"};      // C++ 11 only
  cout << "Name: " << jane.name << endl;
  cout << "Age:  " << jane.age << " years\n";
  cout << "GPA:  " << jane.gpa << endl << endl;

*/
  CallStudent(2);

// serialize down
  ofstream fout; // declares an object of type "ofstream"
  fout.open("IO_Test_File.txt");
  fout << StudentOne.age << "\n" << StudentOne.name << "\n" << StudentOne.gpa << "\n \n";

  //fout << StudentTwo.age << "\n" << StudentTwo.name << "\n" << StudentTwo.gpa << "\n \n";
  //fout << jane.age << "\n" << jane.name << "\n" <<jane .gpa << "\n \n";

  fout << "EOF\n"; // stands for end-of-file

  fout.close(); // done with the file
}


void CallName (double age, double grade) {




}








