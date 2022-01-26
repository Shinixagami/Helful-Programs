#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;  //input output stream -also where print functions are.

#include <iomanip>   //for setprecision
using std::fixed;
using std::setprecision;

#include <sstream>   //to allow format control when converting numbers to strings
using std::stringstream;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string.h> //C string or Char

#include <string>
using std::getline; //get line for input
using std::string;

#include <algorithm>
using std::swap; //swap

#include <cctype> // for toupper and tolower
using std::tolower;
using std::toupper;

char * cConversion (string input); //Func prototype I put * because idk.

int main()
{


    string input = "Hello World.";
    cout << "This is a regular C++ string: " << input << endl << endl;


    //Convert
    char * cInputB; //idk i just put a pointer thing there cus error.

    cInputB = cConversion(input); //FUNCTION HERE --------

    cout << "C String outside function: " << cInputB << endl;


    char store

    strcpy(c, cInputB);




    return 0;
}


char * cConversion(string input)
{

    //---------- Converts string input to c char. ----------
    char * cInput;

    //points here    //new char [name length]
        cInput = new char[input.length()];

    // cout << "input.length : " << input.length() << endl; //HOW to use string.length

    for (int index = 0; index < input.length(); index++)
        {
        cInput[index] = input[index];
        }
    cInput[input.length()] = '\0';//add the null terminator at the end of array


    cout << "C String inside function: " << cInput << endl;

    return cInput;
}
