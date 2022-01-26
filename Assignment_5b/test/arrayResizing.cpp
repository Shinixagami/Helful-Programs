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

#include <string.h>

#include <string>
using std::getline; //get line for input
using std::string;

#include <algorithm>
using std::swap; //swap

#include <cctype> // for toupper and tolower
using std::tolower;
using std::toupper;

#include <vector>

struct Calculate
{
    double cost;
    char desc[120]; //100 char

    //double arrayCost[100] ; //100 Arrays
    //char arrayDesc[100][120];   //100 Arrays, 120 Characters


    double arrayCost[]; //100 Arrays
    char arrayDesc[2][120];   //100 Arrays, 120 Characters

    int counter;  // count for array.
    int inputVal; //menu value
};


int main() {

    Calculate s;


  int arr[] = {10,20,30,40,50,60};


  int arrSize = *(&arr + 1) - arr;


  cout << "The length of the array is: " << arrSize;

//---------------------------------------


    s.arrayCost = new double[2];

    unsigned int arr_length = 0;


    if (s.arrayCost< 15)
        {
        //suppose to add number heree
        s.arrayCost[arr_length++] = 20;
        }
    else
        {
        // Handle a full array.
        }



 //-------------------------------------------------------------------THIS

                int arraySizeDesc =  *(&s.arrayDesc + 1) - s.arrayDesc ;            //sizeof(s.arrayDesc);
                int arraySizeCost =  *(&s.arrayCost + 1) - s.arrayCost   ;        // sizeof(s.arrayCost);


                cout << endl;

                cout << "~~~ array info ~~~ "<< endl;


                cout << "array size DESC:" << arraySizeDesc << endl;

                cout << "array size COST:" << arraySizeCost << endl;


                //cout << "~counter: " << s.counter << endl;


                cout << endl;





}
