#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string>
using std::getline; //get line for input
using std::string;

#include <cstdlib> // for atoi and atof

//function prototype for file serializing down

struct Student
{
    string name;
    int age;
    string city;
    double gpa;
    string major;
};

//struct prototypes -has to be declared below the struct
Student input();

//Serialization down function inputs 3 student objects
void CreateTxtFile (Student strg1, Student strg2, Student strg3);

// function prototypes for printing table layout
void outputTableHeading();
void outputStudent(int, Student);

/*******************************************************************************
* Function : Main function
* Parameters : NA
* Return : 0
* Description :
*       Gets inputs using structs/functions
*       Functions gets inputs, which gets stored using variables.
*       Stored inputs gets printed on the table, and serialized to student.txt
********************************************************************************/
int main()
{

    //Storage struct is used to print on table and serialize down -they contain the values.
    //Storage is needed because input() changes values for each time its called.
    Student strg1, strg2, strg3;

    //Calls input() and stores values in strg
    strg1 = input();   //input() is a struct function that gets all the inputs
    strg2 = input();   //input() is a struct function that gets all the inputs
    strg3 = input();   //input() is a struct function that gets all the inputs

    //Output the three students in a nice table
    outputTableHeading();

    outputStudent(1, strg1);   //prints stored student 1 on table

    outputStudent(2, strg2);   //prints stored student 2 on table

    outputStudent(3, strg3);   //prints stored student 3 on table

    //Creates text file,  uses the 3 stored structs -serialization down.
    CreateTxtFile (strg1, strg2, strg3);

  return 0;
}

/*******************************************************************************
* Function : outputTableHeading()
* Parameters : N/A
* Return : void
* Description :
*       Prints table heading layout
********************************************************************************/
void outputTableHeading()
{
  cout <<  endl;
  cout << "   # Name            AGE  GPA   CITY         MAJOR  \n";
  cout << "---- --------------- ---  ----  ----------- -------------\n";
}

/*******************************************************************************
* Function : outputStudent
* Parameters : sequenceNumber (IN), anyStuden(IN)
* Return : void
* Description :
*       Prints table data layout
********************************************************************************/
void outputStudent(int sequenceNumber, Student anyStudent)
{
//Sequence number
  cout.width(4); cout << sequenceNumber << ' ';
//Name
  cout.setf(ios::left); cout.width(16); cout << anyStudent.name;
//Age
  cout.width(5); cout << anyStudent.age;
//Gpa
  cout.width(6); cout << anyStudent.gpa;
//City
  cout.width(12); cout << anyStudent.city;
//Major
  cout.width(9); cout << anyStudent.major << endl;
  cout.unsetf(ios::left); cout.width(1);  //resets the next line
}

/*******************************************************************************
* Struct Student : input
* Parameters : name(IN), age IN), city(IN), gpa(IN), major (IN)
* Return : newStudent
* Description :
*       Gets input of all struct object and stores their value into newStudent.
********************************************************************************/
Student input(){

    Student newStudent;   //creates newStudent object to return the values.

    cout << "\n ~Please enter student information~\n";

    cout << "Input the students name: ";     //1  name
    getline (cin, newStudent.name);

    string buf1 ;
    cout << "What is the students age: ";    //2    age
    cin >> buf1; newStudent.age = atoi(buf1.c_str());
    cin.ignore(1000, 10);

    cout << "What is the students City: " ;  //3    city
    getline (cin, newStudent.city);

    string buf2 ;
    cout << "What is the students GPA: ";    //4    gpa
    cin >> buf2; newStudent.gpa = atof(buf2.c_str());
    cin.ignore(1000, 10);

    cout << "What is the students Major: ";  //5    major
    getline (cin, newStudent.major);

    return newStudent; //unlike normal functions struct can return multiple values.

}

/*******************************************************************************
* Function : CreateTextFile
* Parameters : 3 Student structs
* Return : void
* Description :
*       Takes in data from 3 students, total of 15 values
*       Serealized down to text file student.txt
********************************************************************************/
void CreateTxtFile (Student strg1, Student strg2, Student strg3)  {

    cout << endl << "~Text File students.txt has been created. " << endl << endl;

   // serialize down
    ofstream fout; // declares an object of type "ofstream"
    fout.open("students.txt");

    fout <<  strg1.name << "\n" <<  strg1.age << "\n" <<  strg1.city  << "\n" << strg1.gpa << "\n" << strg1.major << "\n";

    fout <<  strg2.name << "\n" <<  strg2.age << "\n" <<  strg2.city  << "\n" << strg2.gpa << "\n" << strg2.major << "\n";

    fout <<  strg3.name << "\n" <<  strg3.age << "\n" <<  strg3.city  << "\n" << strg3.gpa << "\n" << strg3.major << "\n";

    fout << "EOF\n"; // stands for end-of-file

    fout.close(); // done with the file

}




