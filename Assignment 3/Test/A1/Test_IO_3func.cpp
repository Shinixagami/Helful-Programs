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

//Serealization down function inputs 3 student objects
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

    // storage struct is used to print on table and serelized down -they contain the values.
    Student strg1, strg2, strg3;

    strg1 = input();   //input() is a function that gets all the inputs
    strg2 = input();   //input() is a function that gets all the inputs
    strg3 = input();   //input() is a function that gets all the inputs

// TEST VALUES

    cout << " ~~~input 1~~~ " << endl << endl;
    cout << endl << "Collected the details of " << strg1.name << endl ;
    cout <<" student age: " << strg1.age << endl;
    cout <<" student city: " << strg1.city << endl;
    cout <<" student gpa: " << strg1.gpa << endl;
    cout <<" student major: " << strg1.major << endl << endl;

    cout << " ~~~input 2~~~ " << endl << endl;

    cout << endl << "Collected the details of " << strg2.name << endl;   //1
    cout <<" student age: " << strg2.age << endl;      //2
    cout <<" student city: " << strg2.city << endl;   //3
    cout <<" student gpa: " << strg2.gpa << endl;    //4
    cout <<" student major: " << strg2.major << endl << endl;  //5

    cout << " ~~~input 3~~~ " << endl << endl;

    cout << endl << "Collected the details of " << strg3.name << endl;   //1
    cout <<" student age: " << strg3.age << endl;      //2
    cout <<" student city: " << strg3.city << endl;   //3
    cout <<" student gpa: " << strg3.gpa << endl;    //4
    cout <<" student major: " << strg3.major << endl << endl;   //5

    //Output the three students in a nice table
    outputTableHeading();

    outputStudent(1, strg1);   //prints student 1 on table

    outputStudent(2, strg2);   //prints student 2 on table

    outputStudent(3, strg3);   //prints student 3 on table

    //CREATE SELIZATIONA FUNCTION
    //THIS IS WHERE THE STORAGE INPUTS GO.
    CreateTxtFile (strg1, strg2, strg3);

  return 0;
}

/*******************************************************************************
* Function : outputTableHeading()
* Parameters : N/A
* Return : void
* Description :
*       Table heading layout
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
*       Table data layout
********************************************************************************/
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

/*******************************************************************************
* Function : input
* Parameters : name(IN), age IN), city(IN), gpa(IN), majorIN)
* Return : newStudent
* Description :
*       Gets input of all struct object and stores their value into newStudent.
********************************************************************************/
Student input(){

    Student newStudent;   //the input new student layout for struct

    cout << "\nTHIS IS THE INPUT FUNCTION~: \n \n";
    cout << "\nPlease enter student information: \n";

    cout << "Input the students name: ";   //1  name
    getline (cin, newStudent.name);


    string buf1 ;
    cout << "What is the students age: ";    //2     age
    cin >> buf1; newStudent.age = atoi(buf1.c_str());
    cin.ignore(1000, 10);

    //cout << "Tage: " << newStudent.age << endl;

    cout << "What is the students City: " ;  //3    city
    getline (cin, newStudent.city);


    string buf2 ;
    cout << "What is the students GPA: ";   //4     gpa
    cin >> buf2; newStudent.gpa = atof(buf2.c_str());
    cin.ignore(1000, 10);


    cout << "What is the students Major: " ;  //5   majoir
    getline (cin, newStudent.major);


    cout << "Inside function~"<< endl;
    cout << "T name: " << newStudent.name << endl;
    cout << "T age : " << newStudent.age << endl;
    cout << "T city: " << newStudent.city << endl;
    cout << "T gpa: " << newStudent.gpa << endl;
    cout << "T major: " << newStudent.major << endl << endl;

    return newStudent;

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

    cout << endl  ;
    cout << "~Text File Test_student.txt has been created. " << endl << endl;

   // serialize down
    ofstream fout; // declares an object of type "ofstream"
    fout.open("Test_student.txt");

    fout <<  strg1.name << "\n" <<  strg1.age << "\n" <<  strg1.city  << "\n" << strg1.gpa << "\n" << strg1.major << "\n";

    fout <<  strg2.name << "\n" <<  strg2.age << "\n" <<  strg2.city  << "\n" << strg2.gpa << "\n" << strg2.major << "\n";

    fout <<  strg3.name << "\n" <<  strg3.age << "\n" <<  strg3.city  << "\n" << strg3.gpa << "\n" << strg3.major << "\n";

    fout << "EOF\n"; // stands for end-of-file

    fout.close(); // done with the file

}




