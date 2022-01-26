/*******************************************************************************
MAIN TEST -
********************************************************************************/
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

struct Course
{
    string cName;
    int year;
    double units;
    string grade;
};

//struct prototypes -has to be declared below the struct
//Serialization down function inputs 3 student objects

void CreateTxtFile ();

// function prototypes for printing table layout
void outputTableHeading();
void outputTableBody();



Course input();


/*******************************************************************************
* Function : Main function
* Parameters : N/A
* Return : 0
* Description :
*       Gets inputs using structs/functions
*       Functions gets inputs, which gets stored using variables.
*       Stored inputs gets printed on the table, and serialized to student.txt
********************************************************************************/
int main()
{

 /*
const int STUDENTS = 4;    //4 students
const int TESTS = 3;         //3 test
void printScores(int testScores[][TESTS]); // must speficfy 2nd dimension

    int testScores[STUDENTS][TESTS ];

  // loop to enter all test scores
  string buf1; // input buffer
  for (int col = 0; col < TESTS ; col++)
  {

    cout << "\nEnter scores for exam #" << (col + 1) << ' ';
    for (int row = 0; row < STUDENTS; row++)
    {
      cout << " Enter score for student #" << (row + 1) << endl;
      cin >> buf1; testScores[row][col] = atoi(buf1.c_str( ));
    }
  }

  */

//---------------------------------------- other way with Q break.


const int CAPACITY = 100; // global variable
int scores [CAPACITY] = {}; // initalize all to 0
int size;


string buf1; // for using the string buffer method
size = 0;





string courseName [];

int courseYear[];

double courseUnits[];

string courseGrade[];




  while (true)  //break function will end this line
  {

    Course newCourse;   //creates newStudent object to return the values.

    //cout << "\n ~Please enter student information~\n";

    cout << "Enter course #1 [Q to exit] ";     //1  name
    getline (cin, newCourse.cName);

    if (newCourse.cName == "Q" || newCourse.cName == "q") break;

    string buf1 ;
    cout << "What year for "  << newCourse.cName << "? [e.g., 2016]: " ;
    cin >> buf1; newCourse.year = atoi(buf1.c_str());

    if (buf1 == "Q" || buf1 == "q") break;
    cin.ignore(1000, 10);


    //string buf1 ;
    cout << "How many units is "  << newCourse.cName <<  "?" ;    //4    gpa
    cin >> buf1; newCourse.units = atof(buf1.c_str());


    if (buf1 == "Q" || buf1 == "q") break;
    cin.ignore(1000, 10);


    //grade is a string because A-F  -can also be Char.
    cout << "And what was your grade [? for in-progress or planned]: ";  //5    major
    getline (cin, newCourse.grade);

    if (newCourse.grade == "Q" || newCourse.grade == "q") break;


    //score size = 0
    //IS NOT equal to capacity
    if (size != CAPACITY)  // Why check ?
    {

      //scores[size] = atoi(buf1.c_str());
      cout << "BUFF 1 IS " << buf1 << endl;
      size++;

    }



    cout << "size IS  1 IS " << size << endl;

  }














   // END OF while TRUE




    //Output the three students in a nice table
 //   outputTableHeading();

 //   outputStudent(1, strg1);   //prints stored student 1 on table

 //   outputStudent(2, strg2);   //prints stored student 2 on table

//    outputStudent(3, strg3);   //prints stored student 3 on table

    //Creates text file,  uses the 3 stored structs -serialization down.


//    CreateTxtFile (strg1, strg2, strg3);

  return 0;
}


/*******************************************************************************
* Struct Student : input
* Parameters : name(IN), age IN), city(IN), gpa(IN), major (IN)
* Return : newStudent
* Description :
*       Gets input of all struct object and stores their value into newStudent.
********************************************************************************/
Course input(){

    Course newCourse;   //creates newStudent object to return the values.

    //cout << "\n ~Please enter student information~\n";

    cout << "Enter course #1 [Q to exit] ";     //1  name
    getline (cin, newCourse.cName);

    string buf1 ;
    cout << "What year for "  << newCourse.cName << "? [e.g., 2016]: " ;
    cin >> buf1; newCourse.year = atoi(buf1.c_str());
    cin.ignore(1000, 10);


    string buf2 ;
    cout << "How many units is "  << newCourse.cName <<  "?" ;    //4    gpa
    cin >> buf2; newCourse.units = atof(buf2.c_str());
    cin.ignore(1000, 10);

    //grade is a string because A-F  -can also be Char.
    cout << "And what was your grade [? for in-progress or planned]: ";  //5    major
    getline (cin, newCourse.grade);

    return newCourse; //unlike normal functions struct can return multiple values.
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
void outputTableBody ()
{



}



/*******************************************************************************
* Function : CreateTextFile
* Parameters : 3 Student structs
* Return : void
* Description :
*       Takes in data from 3 students, total of 15 values
*       Serialized down to text file student.txt
********************************************************************************/
void CreateTxtFile ()  {

    cout << endl << "~Text File students.txt has been created. " << endl << endl;

   // serialize down
    ofstream fout; // declares an object of type "ofstream"
   fout.open("students.txt");

   /*
    fout <<  strg1.name << "\n" <<  strg1.age << "\n" <<  strg1.city  << "\n" << strg1.gpa << "\n" << strg1.major << "\n";

    fout <<  strg2.name << "\n" <<  strg2.age << "\n" <<  strg2.city  << "\n" << strg2.gpa << "\n" << strg2.major << "\n";

    fout <<  strg3.name << "\n" <<  strg3.age << "\n" <<  strg3.city  << "\n" << strg3.gpa << "\n" << strg3.major << "\n";

    */


    fout << "EOF\n"; // stands for end-of-file

    fout.close(); // done with the file
}
