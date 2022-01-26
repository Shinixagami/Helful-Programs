/*******************************************************************************
NAME: Vin Gabriel Fillon 10/08/2021 CompSci-165
TITLE: Lab Assignment 4
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Course Input through Serialization Up, and use of Arrays.
    then Serialization Down using stored Array data.
********************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;  //input output stream -also where print functions are.

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

// function prototypes

//table heading
void outputTableHeading();

//Table data using arrays.
void outputTableBody(string courseName[], int courseYear[],  double courseUnits[], string courseGrade[], int N);

//creates text file by moving data into the FUNCTION
void CreateTxtFile(string courseName[], int courseYear[],  double courseUnits[], string courseGrade[], int NS);


/*******************************************************************************
* Function : Main function
* Parameters : N/A
* Return : 0
* Description :
*       Serialization up and stores data into arrays.
*       Gets input in main function
*           -While loops have breaks to stop inputting
*       stores input in arrays
*       Uses array data to print through while/for loops.
********************************************************************************/
int main()
{

    int *ptr;

    ptr = 100;

    ptr++;

    int CAPACITY = 100; //CAPACITY VARIABLE. -makes life easier.

    //arrays for storage
    string courseName[CAPACITY] = {};    //will have to create a loop to print data to fout
    int courseYear[CAPACITY] = {};
    double courseUnits[CAPACITY] = {};
    string courseGrade[CAPACITY] = {};


    int NS = 0;  // this is the official starting number

    // serialize up
    ifstream fin; // declares an object

    fin.open("courses.txt");
    if (fin.good()) // only read from the file if it exists!
        {

        string bufS;
        while (true || bufS != "EOF")
            {
            //Course Name ----------------
            getline(fin, bufS);  //FOR COURSE NAME

            if (bufS == "EOF") break;
            else {courseName[NS] = bufS; }

            //YEAR ----------------
            fin >>  bufS;      // FOR YEAR int

            if (bufS == "EOF") break;

            else
            {
                courseYear[NS] = atoi(bufS.c_str());  //ATOI FOR INT
            }

            //UNITS ----------------
            fin.ignore(1000, 10); //fin ignore

            fin >>  bufS;      // FOR UNITS
            if (bufS == "EOF") break;
            else
            {
                courseUnits[NS] = atof(bufS.c_str());  //ATOF FOR FLOAT
            }

            //GRADE ----------------
            fin.ignore(1000, 10); //fin ignore

            getline(fin, bufS);   // FOR GRADE
            if (bufS == "EOF") break;
            else
            {
                courseGrade[NS] = bufS;  //ATOF FOR FLOAT
            }

            //NS is how much data was serialized up to Arrays.
            NS = NS+1;  //moves on to next set of data.

            }   //END OF WHILE LOOP FOR SER UP

        } //END OF SER UP


    if (fin.good()) // only read from the file if it exists!
        {
        outputTableHeading();
        outputTableBody(courseName,  courseYear,   courseUnits, courseGrade,  NS);
        }

    fin.close(); // closes file

    int N;  //N will the the value of the arrays!

    //You can use one Value but it's easier to tell which section to debug with two.
    N = NS; // Turn as equal so the initialized Arrays DONT get filled up.

    Course newCourse;   //creates newStudent struct to take in inputs.

    string buf; //buf method -is declared outside because it is also part of the while loop.

        while (true || buf != "Q" || buf != "q")  //break function will end this line
        {
            cout << endl;
            cout << "Enter course #" << N+1 << "[Q to exit] ";
            getline (cin, buf);

            if (buf != "Q" && buf != "q" ) newCourse.cName = buf;
            if (buf == "Q" || buf == "q") break;

            if (newCourse.cName == "Q" || newCourse.cName == "q") break;

            cout << "What year for "  << newCourse.cName << "? [e.g., 2016]: " ;
            cin >> buf; newCourse.year = atoi(buf.c_str());
            if (buf == "Q" || buf == "q") break;

            cin.ignore(1000, 10);

            cout << "How many units is "  << newCourse.cName <<  "? " ;
            cin >> buf; newCourse.units = atof(buf.c_str());
            if (buf == "Q" || buf == "q") break;

            cin.ignore(1000, 10);

            cout << "And what was your grade [? for in-progress or planned]: ";
            getline (cin, buf);

            if (buf != "Q" && buf != "q" ) newCourse.grade = buf;
            if (buf == "Q" || buf == "q") break;

            courseName[N] = newCourse.cName;   //strg is now stored inside an array.
            courseYear[N] = newCourse.year;  //strg is now stored inside an array.
            courseUnits[N] = newCourse.units;  //strg is now stored inside an array.
            courseGrade[N] = newCourse.grade;   //strg is now stored inside an array.

            N = N+1; //to move on to next array inputs.

            outputTableHeading();  //function which prints out table heading
            outputTableBody(courseName,  courseYear,   courseUnits, courseGrade,  N); //function which prints out array data -formats it in table.
        } //while loop end


//Prints table heading and data.
outputTableHeading();
outputTableBody(courseName,  courseYear,   courseUnits, courseGrade,  N);

//Fout Creates Text File.
CreateTxtFile(courseName,  courseYear,   courseUnits, courseGrade,  N);

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

    cout.setf(ios::left);

       //12 CHAR FOR name
    cout <<  " "; cout.width(12); cout << "Course";
        //  9 char for year
    cout <<  " "; cout.width(9); cout  << "Year";
        //  9 char for year
    cout << " "; cout.width(9); cout << "Units";
        //  9 char for year
    cout << " "; cout.width(9); cout <<  "Grade";
    cout << endl;

    cout << "-------------------------------------------------\n";

    cout.unsetf(ios::left);
}

/*******************************************************************************
* Function : OutputTableBody
* Parameters :   string courseName[], int courseYear[],  double courseUnits[], string courseGrade[], int N
* Return : void
* Description :
*       Prints table data data through loop grabbing information from arrays.
********************************************************************************/
void outputTableBody (string courseName[], int courseYear[],  double courseUnits[], string courseGrade[], int N)
{

    for (int ND = 0; ND < N; ND++)
        {
        cout.setf(ios::left); //sets alignment to left.

        //12 CHAR FOR name
        cout <<  " "; cout.width(12); cout << courseName[ND];
        //  9 char for year
        cout <<  " "; cout.width(9); cout  << courseYear[ND];
        //  9 char for year
        cout << " "; cout.width(9); cout << courseUnits[ND];
        //  9 char for year
        cout << " "; cout.width(9); cout <<  courseGrade[ND];

        cout << endl;

        cout.unsetf(ios::left);  //unsets alignment to left.
        }

}


/*******************************************************************************
* Function : CreateTextFile
* Parameters : string courseName[], int courseYear[],  double courseUnits[], string courseGrade[], int N
* Return : void
* Description :
*       Takes in data from arrays
*       Serialized down to text file coursesOutput.txt
********************************************************************************/
void CreateTxtFile (string courseName[], int courseYear[],  double courseUnits[], string courseGrade[], int N)  {

    // serialize down
    ofstream fout; // declares an object of type "ofstream"
    fout.open("courses.txt");

        // Delete not needed for program
       for (int ND = 0; ND < N; ND++)
       {
            fout <<  courseName[ND] << "\n";
            fout  <<  courseYear[ND] << "\n";
            fout <<  courseUnits[ND] << "\n";
            fout << courseGrade[ND] << "\n";
        }

    fout << "EOF\n"; // stands for end-of-file

    fout.close(); // done with the file

}




