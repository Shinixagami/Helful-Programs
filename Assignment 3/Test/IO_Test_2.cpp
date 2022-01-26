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
void CallStudentAge (double age);
void CallStudentName (string name);

void CallE();

struct Student   //structure name
{
  int age;        // variables
  string name;    //variable
  double gpa;
  string major;
  string year;
};

int main()
{

int age = 21 ;        // variables
string name = "aKI" ;    //variable
double gpa = 2.3 ;
string major = "coMPSCI" ;
string year = "2023" ;


   cout <<" enter student ones attributes: " << endl;


   cout <<"AGE (INT), NAME (STRING), GPA (double), MAJOR (string), Year (string) " << endl << endl;

   //cin >> age >> name >> gpa >>  major >> year ;

  Student StudentOne; // declare the struct-based object
  StudentOne.age = age ; // assigning a value to an attribute
  StudentOne.name = name ;
  StudentOne.gpa = gpa ;
  StudentOne.major = major;
  StudentOne.year = year;

  cout << "Info for student one :\n";
  cout << "Name: " << StudentOne.name << endl;
  cout << "Age:  " << StudentOne.age << " years\n";
  cout << "GPA:  " << StudentOne.gpa << endl << endl;
  cout << "Major: " << StudentOne.name << endl;
  cout << "Year:  " << StudentOne.age << " years\n";


//PRINTS TEXT FILE / SERLIZAITON

  ofstream fout; // declares an object of type "ofstream"
  fout.open("IO_Test_File3.txt");

  fout << StudentOne.age << "\n" << StudentOne.name << "\n" << StudentOne.gpa << "\n" << StudentOne.major << "\n"  << StudentOne.year  <<  "\n \n";

  fout << "two" << "\n" << "two"  << "\n" << "two"  << "\n \n";

  fout << "two"  << "\n" << "two"  << "\n" << "two" << "\n \n";

  fout << "EOF\n"; // stands for end-of-file

  fout.close(); // done with the file


  // this does not work it will change the whole file.
  fout.open("IO_Test_File3.txt");

  fout << "ADDITION";

  fout.close(); // done with the file


}


void CallStudentAge (double age) {

    cout << "Student age is " << age << endl;

}

void CallStudentName (string name) {

    cout << "Student name : " << name << endl;

}

void CallE () {


    // serialize down
  ofstream fout; // declares an object of type "ofstream"
  fout.open("IO_Test_File3.txt");

  Student StudentOne; // declare the struct-based object
  StudentOne.age = 69; // assigning a value to an attribute
  StudentOne.name = "beelzabub" ;
  StudentOne.gpa = 4.6;

  fout << StudentOne.age << "\n" << StudentOne.name << "\n" << StudentOne.gpa << "\n \n";

  fout << "EOF\n"; // stands for end-of-file

  //fout.close(); // done with the file

}













