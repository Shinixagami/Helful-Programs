#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string>
using std::getline;
using std::string;

#include <cstdlib> // for atoi and atof

//function prototypes for inside
int CallStudAge();
string CallStudName();
string CallStudCity();
double CallStudGPA();
string CallStudMajor();

// Create Text File inputs.
void CreateTxtFile (string name1, string name2, string name3, int age1,int age2,int age3, string city1,string city2, string city3, double gpa1,double gpa2, double gpa3, string major1, string major2, string major3);

struct Student
{
    string name;
    int age;
    string city;
    double gpa; // grade point average
    string major;
};

// function prototypes  FOR printing
void outputTableHeading();
void outputStudent(int, Student);



/*******************************************************************************
* Function : Main function
* Parameters : Name (IN), Age (IN),  City (IN),  GPA (IN),  Major (IN),
* Return : 0
* Description :
*       Gets inputs using functions
*       Functions gets inputs, which gets stored.
*       stored inputs gets printed on the table, and serialized to student.txt
*******************************************************************************/

int main()
{

 //storage variables for serialization and table.
    string StrgStudName1, StrgStudName2, StrgStudName3;
    int StrgStudAge1, StrgStudAge2, StrgStudAge3;
    string StrgStudCity1, StrgStudCity2, StrgStudCity3;
    double StrgStudGPA1, StrgStudGPA2, StrgStudGPA3;
    string StrgStudMajor1, StrgStudMajor2, StrgStudMajor3;

//--------------------------------------------------------------
//STUDENT 1

// calls function which returns a value.
// first part is storage
    StrgStudName1 = CallStudName();   // USE THIS - THIS IS THE BEST METHOD.
    StrgStudAge1 = CallStudAge();    //Calls age func and places it into storage
    StrgStudCity1 = CallStudCity();
    StrgStudGPA1 = CallStudGPA();  //returns int for some reasons
    StrgStudMajor1 = CallStudMajor();

//Structure of Student1;
    Student Student1;
    Student1.name = StrgStudName1;     //
    Student1.age = StrgStudAge1;
    Student1.city = StrgStudCity1;
    Student1.gpa = StrgStudGPA1;
    Student1.major = StrgStudMajor1;

//TEST LINES DELETE AFTER REAL PROGRAM~~~~~~~~~~~~~
    cout << "Tname: " << StrgStudName1 <<endl;
    cout << "Tage: " << StrgStudAge1 <<endl;
    cout << "Tcity: " << StrgStudCity1 <<endl;
    cout << "Tgpa: " << StrgStudGPA1 <<endl;
    cout << "Tmajor: " << StrgStudMajor1 <<endl << endl ;

//--------------------------------------------------------------
//STUDENT 2

//storage and Callfunction of student 2
    StrgStudName2 = CallStudName();
    StrgStudAge2 = CallStudAge();
    StrgStudCity2 = CallStudCity();
    StrgStudGPA2 = CallStudGPA();
    StrgStudMajor2 = CallStudMajor();

//Structure of Student2;
    Student Student2;
    Student2.name = StrgStudName2;
    Student2.age = StrgStudAge2;
    Student2.city = StrgStudCity2;
    Student2.gpa = StrgStudGPA2;
    Student2.major = StrgStudMajor2;

//--------------------------------------------------------------
//STUDENT 3

//storage and Callfunction of student 3
    StrgStudName3 = CallStudName();
    StrgStudAge3 = CallStudAge();
    StrgStudCity3 = CallStudCity();
    StrgStudGPA3 = CallStudGPA();
    StrgStudMajor3 = CallStudMajor();

//Structure of Student2;
    Student Student3;
    Student3.name = StrgStudName3;
    Student3.age = StrgStudAge3;
    Student3.city = StrgStudCity3;
    Student3.gpa = StrgStudGPA3;
    Student3.major = StrgStudMajor3;


//Output the three students in a nice table
    outputTableHeading();

    outputStudent(1, Student1);

    outputStudent(2, Student2);

    outputStudent(3, Student3);

  //CREATEs SERIALIZATION FUNCTION
  //THIS IS WHERE THE STORAGE INPUTS GO.
  CreateTxtFile (StrgStudName1, StrgStudName2, StrgStudName3, StrgStudAge1, StrgStudAge2, StrgStudAge3, StrgStudCity1 ,StrgStudCity2 , StrgStudCity3, StrgStudGPA1, StrgStudGPA2, StrgStudGPA3, StrgStudMajor1 , StrgStudMajor2 , StrgStudMajor3);

  return 0;
}

// THIS IS THE TABLE heading
void outputTableHeading()
{
  cout <<  endl;
  cout << "   # Name            AGE  GPA   CITY         MAJOR  \n";
  cout << "---- --------------- ---  ----  ----------- -------------\n";
}

//this can be printed out multiple times
void outputStudent(int sequenceNumber, Student anyStudent)
{
//sequence number
  cout.width(4); cout << sequenceNumber << ' ';
//name
  cout.setf(ios::left); cout.width(16); cout << anyStudent.name;
//age
  cout.width(5); cout << anyStudent.age;
//gpa
  cout.width(6); cout << anyStudent.gpa;
//City
  cout.width(12); cout << anyStudent.city;
//MAJOR
  cout.width(9); cout << anyStudent.major << endl;
  cout.unsetf(ios::left); cout.width(1);  //resets the next line

}

string CallStudName(){

    string name;

    cout << "~Func CallStudName()" << endl;

    cout << "Input the Students Name: ";
    getline (cin, name);

    return name;
}

//start of the edits you made
int CallStudAge () {

    int Age;

    cout << "~Func CallStudAge()" << endl;

    string buf ;
    cout << "input the age: ";
    cin >> buf; Age = atoi(buf.c_str());
    cin.ignore(1000, 10);

    return Age;
}

string CallStudCity () {

    string City;

    cout << "~Func CallStudCity()" << endl;

    cout << "What is the students City : " ;
    getline (cin, City);

    return City ;
}

double CallStudGPA (){

    double GPA;

    cout << "~Func CallStudGPA()" << endl;

    string buf ;
    cout << "input GPA: ";
    cin >> buf; GPA = atof(buf.c_str());
     cin.ignore(1000, 10);

    return GPA;
}

string CallStudMajor(){

    string Major;

    cout << "~Func CallStudMajor()" << endl;
    cout << "What is the students Major : " ;
    getline (cin, Major);

    return Major ;

}

void CreateTxtFile (string name1, string name2, string name3, int age1,int age2,int age3, string city1,string city2, string city3, double gpa1,double gpa2, double gpa3, string major1, string major2, string major3) {

  cout << endl << endl ;

  cout << "~Text File CreateOutput.txt has been created. " << endl << endl;

    // serialize down
  ofstream fout; // declares an object of type "ofstream"
  fout.open("CreateOutput.txt");


  fout <<  name1 << "\n" <<  age1 << "\n" <<  city1  << "\n" << gpa1 << "\n" << major1 << "\n";

  fout <<  name2 << "\n" <<  age2 << "\n" <<  city2  << "\n" << gpa2 << "\n" << major2 << "\n";

  fout <<  name3 << "\n" <<  age3 << "\n" <<  city3  << "\n" << gpa3 << "\n" << major3 << "\n";

  fout << "EOF\n"; // stands for end-of-file

  fout.close(); // done with the file

}




