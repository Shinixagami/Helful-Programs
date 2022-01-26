/*******************************************************************************
 TEST V3
********************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;  //input output stream


#include <iomanip>
using std::setw; //needed for table -makes life easier.

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



const int CAPACITY = 100; // global variable w
//int Courses [CAPACITY] = {}; // init all to 0

//arrays for storage
string courseName[CAPACITY] = {};    //will have to create a loop to print data to fout
int courseYear[CAPACITY] = {};
double courseUnits[CAPACITY] = {};
string courseGrade[CAPACITY] = {};



// default in case TXT file does not yet exist
//Student a = {0, "unknown", 0};


int NS = 0;  // this is the official starting number

  // serialize up
ifstream fin; // declares an object

  fin.open("coursesInput.txt");
  if (fin.good()) // only read from the file if it exists!
  {

    string bufS;

        while (true || bufS != "EOF") {

            cout << endl << endl;

            cout << "~SERIALIZATION" << endl;

            cout <<  "NS = " << NS << endl; //test serialization up value


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


fin.close(); // done with the file -- for input.



//for loop to check data that was serialized up. -delete in official program
   for (int Na = 0; Na < NS; Na++) {

    cout << endl << endl;

    cout << "~~Serialization Up~" <<endl;

    cout << "Initialized on array: [ " << Na << " ]" <<endl;

    cout << "Array data Name: " << courseName[Na] << endl;

    cout << "Array data Year: " << courseYear[Na] << endl;

    cout << "Array data Units: " << courseUnits[Na] << endl;

    cout << "Array data Grade: " << courseGrade[Na] << endl;

   }



cout << endl << endl;

//Array check
cout <<  "~THIS IS THE END OF SERIALIZATION  "  << endl;

cout <<  "NS = " << NS << endl << endl;

cout <<  "This number is the number of the EMPTY ARRAY [ " << NS << " ]" <<  endl;

cout << "Array Data Initialized up to Array [ " << NS-1 << " ]" << endl;

cout << "Total Arrays filled with data : " << NS <<  endl;





//----------------------------------------------------

    //How many while loops have ran
    int counter1 = 0;  //counter is used to to see how much times the while loop for input is ran.

    int N;  //N IS THE ARRAY NUMBER

    //You can use one Value but it's easier to tell but its easier to debug with two.
    N = NS; // THIS WILL TURN N AND S AS EQUALS. SO THE ARRAYS DONT GET FILLED UP

    cout << endl << endl;

    Course newCourse;   //creates newStudent object to return the values.
    cout << "~ loop counter : " << counter1 << endl;

    string buf; //buf method -is declared outside because it is also part of the while loop.

        while (true || buf != "Q" || buf != "q")  //break function will end this line
        {

        cout << endl << endl;
        cout << "~counter1 val: " << counter1 << " (this is just the number of loops for input)" << endl;

        cout << "Enter course #" << N+1 << "[Q to exit] ";     //1  name
        getline (cin, buf);

        cout << "N val: " << N << endl;
        if (buf != "Q" && buf != "q" ) newCourse.cName = buf;
        if (buf == "Q" || buf == "q") break;


        if (newCourse.cName == "Q" || newCourse.cName == "q") break;

        cout << "What year for "  << newCourse.cName << "? [e.g., 2016]: " ;
        cin >> buf; newCourse.year = atoi(buf.c_str());
        if (buf == "Q" || buf == "q") break;

        cin.ignore(1000, 10);


        cout << "How many units is "  << newCourse.cName <<  "? " ;    //4    gpa
        cin >> buf; newCourse.units = atof(buf.c_str());
        if (buf == "Q" || buf == "q") break;

        cin.ignore(1000, 10);

        //grade is a string because A-F  -can also be Char.
        cout << "And what was your grade [? for in-progress or planned]: ";  //5    major
        getline (cin, buf);

        if (buf != "Q" && buf != "q" ) newCourse.grade = buf;
        if (buf == "Q" || buf == "q") break;

        //counter for how many loops has beeen ran
        counter1 = counter1+1;


        //struct for data movement -------------------------------------------------
        Course strg;

        //storage of new course
        strg = newCourse;


        cout << endl ;
        cout << "inside struct for data movement" << endl << endl;

        //test values
        cout << "Name:  " << strg.cName<< endl;
        cout << "year:  " << strg.year << endl ;
        cout << "units:  " << strg.units << endl;
        cout << "grade:  " << strg.grade << endl << endl;

        cout << "-----data stored-----  WHILE LOOP" << endl;


        cout << "Initialized on array: [ " << N << " ]" <<endl;
        courseName[N] = strg.cName;   //strg is now stored inside an array.
        courseYear[N] = strg.year;
        courseUnits[N] = strg.units;
        courseGrade[N] = strg.grade;

        cout << "Array data Name: " << courseName[N] << endl;  //prints out array data for check -delete after

        cout << "Array data Year: " << courseYear[N] << endl;

        cout << "Array data Units: " << courseUnits[N] << endl;

        cout << "Array data Grade: " << courseGrade[N] << endl;


        cout <<"~ value of N: " << N << endl ;   //value of N for the first time

        cout <<"----------------" << endl << endl;


        N = N+1;

        cout <<"~ value of N: " << N << endl ;    //value of N after the first loop and inputs.

        outputTableHeading();  //function which prints out table heading
        outputTableBody(courseName,  courseYear,   courseUnits, courseGrade,  N); //function which prints out array data -formats it in table.

        } //WHILE LOPP END -------------------------------------------------



cout <<"~~~~WHILE LOOP ENDED~~~~ " << N << endl << endl ;


outputTableHeading();
outputTableBody(courseName,  courseYear,   courseUnits, courseGrade,  N);


//these are whole arrays getting moved
//FOUT TEXTFILE FUNCTION
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

    cout << " " << setw(12) << "Course" << " " <<  setw(9) << "Year" << " " <<setw(9) << "Units" << " " << setw(9) << "Grade" << endl ;
    cout << "-------------------------------------------------\n" << endl;

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


        cout.setf(ios::left);

        cout << "Accessing data on array: [ " << ND << " ]" <<endl;

                    //12 CHAR FOR name                     char for year                   char for units                              char for grade
        cout << " " << setw(12) << courseName[ND] << " " <<  setw(9) << courseYear[ND] << " " <<setw(9) << courseUnits[ND] << " " << setw(9) << courseGrade[ND] << endl << endl;

        cout.unsetf(ios::left);

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


    cout << endl << "~Text File coursesOutput.txt has been created. " << endl << endl;


    // serialize down
    ofstream fout; // declares an object of type "ofstream"
    fout.open("coursesOutput.txt");

    cout << "Array Data Initialized up to Array [ " << N-1 << " ]" << endl;

    cout << "Total Arrays Initialized: " << N << endl;




       for (int ND = 0; ND < N; ND++) {

            cout << endl << endl;

            cout << "Initialized on array: [ " << ND << " ]" <<endl;

            cout << "Array data Name: " << courseName[ND] << endl;

            cout << "Array data Year: " << courseYear[ND] << endl;

            cout << "Array data Units: " << courseUnits[ND] << endl;

            cout << "Array data Grade: " << courseGrade[ND] << endl;

            fout <<  courseName[ND] << "\n";
            fout  <<  courseYear[ND] << "\n";
            fout <<  courseUnits[ND] << "\n";
            fout << courseGrade[ND] << "\n";

        }


    fout << "EOF\n"; // stands for end-of-file

    fout.close(); // done with the file

}







