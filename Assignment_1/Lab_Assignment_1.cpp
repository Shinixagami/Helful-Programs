/**********************************************************
NAME: Vin Gabriel Fillon 08/28/2021 CompSci-165
TITLE: Lab Assignment 1
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Feedback program.
************************************************************/

#include <iostream>
#include <cstdlib>

using std::cin;   //  C input
using std::cout;  // C output
using std::endl;  // End line

#include <string>
using std::string;  //string variable
using std::getline;  //get full line

#include <cmath> //round function is in here.

int main() {

    double YourAge, DegreeF, TwoYears, DegreeC, RoundTenthsPlace ;
    string YourName, YourCity, StrngAge, StrngDegreeF;

    cout << "Enter your age: " <<  endl;
    cin >> StrngAge; //standard input
    YourAge = atof(StrngAge.c_str()); //converts string into double, double for more precision.

    cin.ignore();  //clears storage of cin OR buffer(segment of memory reserved for data)

    cout << "Enter Your Name: " <<  endl;
    getline(cin, YourName);  //grabs whole line input

    cout << "Enter the temperature outside in Degrees Fahrenheit: " << endl;
    cin >> StrngDegreeF;
    DegreeF = atof(StrngDegreeF.c_str());   //converts string into double

    cin.ignore();  //clears storage of cin OR buffer, cuts it so you can input more cin

    cout << "What city are you in right now? " << endl;
    getline(cin, YourCity);

    cout << endl;  //next line

    TwoYears = YourAge + 2; //+2 years

    DegreeC = (DegreeF - 32) * 5/9 ;  // 1 Celsius = 33.8 Fahrenheit

    RoundTenthsPlace = round(DegreeC*10)/10; //rounding 10th places using round function from cmath

    cout << endl;  //next line

    cout << YourName << " is " << YourAge <<  " years old now, and will be "  <<  TwoYears << " two years from now. " << endl;
    cout << "It's " << DegreeF << " degrees F in "  << YourCity << " -- that's "  << RoundTenthsPlace << " degrees C. " << endl;

    return 0;

}







