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

struct Calculation
{
    double value; //100 arrays
    double interestRate;
    int input;
    double interval;
    int op;
    double length;

    double valArray[100];
};

void functionNI(struct Calculation s);

void function1(struct Calculation s);

void function2(struct Calculation s);

void function3(struct Calculation s);


int main()
{
    Calculation s;
    //s.value
    //s.interestRate

    string buf;
    while (true)
        {

        cout << "please enter the starting value: " ;

        getline(cin, buf);

        s.value = atof(buf.c_str());


        if(s.value <= 0)
            {
            cout << "try again bitch." << endl;
            }


        if(s.value > 0)
            {
            cout << "GOOD: " << s.value << endl;
            break;
            }

        cout << endl;

        }


    string buf1;
    while (true)
        {

        cout << "please enter interest rate in percent: " ;

        getline(cin, buf1);


        s.interestRate= atof(buf1.c_str());

        if(s.interestRate <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.interestRate > 0)
            {
            cout << "GOOD: " << s.interestRate << endl;

            s.interestRate = (s.interestRate * 0.01) + 1;

            cout << "~CONVERTED: " << fixed <<  setprecision(4) << s.interestRate << "% "<< endl;


            break;
            }

        cout << endl;
        }


    cout << endl;


    string buf2;
    while (true)
        {

        cout << "Would you like intervals? " << endl ;
        cout << " 1. YES" << endl;
        cout << " 2. NO " << endl;
        cout << "please enter the input: ";
        getline(cin, buf2);

        s.op = atof(buf2.c_str());

        if(s.op <= 0 && s.op >= 3)
            {
            cout << "try again bitch." << endl;
            }

        if(s.op == 1)
            {
            cout << "YES: " << s.op << endl;

            //cout << " THERE'S NO WORKING FUNCTION YET BRUH... "<< endl;
            //s.op = 3;
            break;
            }

         if(s.op == 2)
            {
            cout << "NO: " << s.op << endl;
            break;
            }

        cout << endl;

        }

    cout << endl;


    string buf3;

    while (true && s.op == 1)
        {

        cout << "would you like daily, or monthly, or yearly intervals" << endl;
        cout << " 1. daily " << endl;
        cout << " 2. monthly " << endl;
        cout << " 3. yearly " << endl;
        cout << "please enter the input: ";
        getline(cin, buf3);

        cout << endl;

        s.input = atoi(buf3.c_str());

        if(s.input  <= 0)
            {
            cout << "try again bitch." << endl;
            }


        if(s.input  == 1)
            {
            //cout << "OPTION 1: " <<  s.input << endl;
            cout << "~FUNCTION1~" << endl;
            function1(s);
            break;
            }

        if(s.input  == 2)
            {
            //cout << "OPTION 2: " <<  s.input << endl;
            cout << "~FUNCTION2~" << endl;
            function2(s);
            break;
            }

         if(s.input  == 3)
            {
            //cout << "OPTION 3: " <<  s.input << endl;
            cout << "~FUNCTION3~" << endl;

            function3(s);
            break;
            }

        }


        if(s.op == 2)
            {
            cout << "~NO INTERVAL FUNC ~" << endl;
            functionNI(s);
            }

    cout << endl;
    cout << "RPOGRAM ENDED -BACK TO MENU" << endl;

}


void functionNI(struct Calculation s)
{
    cout << " ---- inside func ---- " << endl;

    //cout << "s.input: " << s.input << endl;

    cout << "s.value: " << s.value << endl;

    cout << "s.interestRate: " << s.interestRate << endl;


    s.interval = 1; //because theres not interval

    cout << "s.interval: " << s.interval << endl;

    cout << endl;

    string buf1;
    while (true)
        {

        cout << "length of compounding: ";

        getline(cin, buf1);

        s.length = atof(buf1.c_str());

        if(s.length <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.length > 0)
            {
            cout << "GOOD LENGTH: " << s.length << endl;
            break;
            }

        cout << endl;

        }

    cout << endl;

    s.valArray[0] = s.value;

    //first calculation for 2nd array
    double temp4 = s.value * s.interestRate;
    s.valArray[1] = temp4;


    cout << "Length :" << s.length << " | ";
    cout << "Interest rate :" << setprecision(2) << fixed << s.interestRate << endl;


    //starts at 2 for 3rd array
    for(int i = 2;  i < s.length; i++)
        {

        s.valArray[i] = s.valArray[i-1] * s.interestRate;

        }

    //cout << endl;


    cout << "-------------------------" << endl;
    cout << "START" << endl;

    cout << "Value : " << setprecision(2) << fixed << s.value << "  " << endl ;
    //cout << "DESC (" << s.arrayDesc[i] << ")" << endl;

    cout << "-------------------------" << endl;


    //starts at 1 because 0 is start
    for(int i = 1;  i < s.length; i++)
        {

        cout << "-------------------------" << endl;
         cout << "array [ " << i << " ]" << endl;

        cout << "Value : " << setprecision(2) << fixed << s.valArray[i] << "  " << endl ;
        //cout << "DESC (" << s.arrayDesc[i] << ")" << endl;

        cout << "-------------------------" << endl;

        }

}


void function1(struct Calculation s)
{
    cout << "Function is Daily... " << endl;

    cout << "s.input: " << s.input << endl;

    cout << "s.value: " << s.value << endl;

    cout << "s.interestRate: " << s.interestRate << endl;

    cout << endl;


    string buf;
    while (true)
        {

        cout << "how many days is the interval to compound: ";

        getline(cin, buf);

        s.interval = atof(buf.c_str());

        if(s.interval <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.interval > 0)
            {
            cout << "GOOD INTERVAL: " << s.interval << endl;
            break;
            }

        cout << endl;
        }


    string buf1;
    while (true)
        {

        cout << "What is the length of days:  ";

        getline(cin, buf1);

        s.length = atof(buf1.c_str());

        if(s.length <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.length > 0)
            {
            cout << "GOOD LENGTH: " << s.length << endl;
            break;
            }

        cout << endl;

        }

    cout << "Function is Daily... " << endl;

    cout << "s.input: " << s.input << endl;

    cout << "s.value: " << s.value << endl;

    cout << "s.interestRate: " << s.interestRate << endl;

    cout << "s.interval: " << s.interval << endl;

    cout << "s.length of days: " << s.length << endl;


    double intervalArray = s.length / s.interval;
    double intervalDays;

    cout << "num: " << intervalArray << endl;
    cout << endl;


//calculation function --------------------------------------------------------
    s.valArray[0] = s.value;

    //first calculation for 2nd array
    double temp4 = s.value * s.interestRate;
    s.valArray[1] = temp4;


    cout << "Length : " << s.length << " | ";

    cout << "Interval Every [ " << setprecision(0) << s.interval << " ] days" << endl;

    cout << "Interest rate : " << setprecision(2) << fixed << s.interestRate << endl;

    //starts at 2 for 3rd array
    for(int i = 2;  i < intervalArray+1; i++)
        {

        s.valArray[i] = s.valArray[i-1] * s.interestRate;

        }



//print function --------------------------------------------------------

    cout << "-------------------------" << endl;
    cout << "Array [ 0 ]" ;    cout << "    Day: [ 0 ]" << endl;

    cout << "Value : " << setprecision(2) << fixed << s.value << "  " << endl ;
    cout << "-------------------------" << endl;
    //starts at 1 because 0 is start
    for(int i = 1;  i < intervalArray+1; i++)
        {

        intervalDays = s.interval * i;

        cout << "-------------------------" << endl;
        cout << "Array [ "<< i << " ]" ;   cout << "    Day: [ " <<  setprecision(0) << intervalDays  << " ]" << endl;
        cout << "Value : " << setprecision(2) << fixed << s.valArray[i] << "  " << endl ;
        cout << "-------------------------" << endl;

        }


}//END OF FUNCTION 1

void function2(struct Calculation s)
{
    cout << "FUNCTION 2 WORKS!" << endl;

    cout << "s.input: " << s.input << endl;

    cout << "s.value: " << s.value << endl;

    cout << "s.interestRate: " << s.interestRate << endl;

    cout << endl;


    string buf;
    while (true)
        {

        cout << "How many months:  ";

        getline(cin, buf);

        s.length = atof(buf.c_str());

        if(s.length <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.length > 0)
            {
            cout << "GOOD LENGTH: " << s.length << endl;
            break;
            }

        cout << endl;
        }


    cout << "Function is monthly " << endl;

    cout << "s.input: " << s.input << endl;

    cout << "s.value: " << s.value << endl;

    cout << "s.interestRate: " << s.interestRate << endl;

    cout << "s.interval: " << s.interval << endl;

    cout << "s.length of MONTHS: " << s.length << endl;


    double intervalArray = s.length / s.interval;
    double month;

    cout << "num: " << intervalArray << endl;
    cout << endl;


//calculation function --------------------------------------------------------
    s.valArray[0] = s.value;

    //first calculation for 2nd array
    double temp4 = s.value * s.interestRate;
    s.valArray[1] = temp4;


    cout << "Length : " << s.length << " | ";

    cout << "Interest rate : " << setprecision(2) << fixed << s.interestRate << endl;

    //starts at 2 for 3rd array
    for(int i = 2;  i < s.length+1; i++)
        {

        s.valArray[i] = s.valArray[i-1] * s.interestRate;

        }



//print function --------------------------------------------------------

    cout << "-------------------------" << endl;
    cout << "Array [ 0 ]" ;    cout << "    Month: [ 0 ]" << endl;

    cout << "Value : " << setprecision(2) << fixed << s.value << "  " << endl ;
    cout << "-------------------------" << endl;
    //starts at 1 because 0 is start
    for(int i = 1;  i < s.length+1; i++)
        {

        //month = s.interval * i;

        cout << "-------------------------" << endl;
        cout << "Array [ "<< i << " ]" ;   cout << "    Month:: [ " <<  setprecision(0) << i  << " ]" << endl;
        cout << "Value : " << setprecision(2) << fixed << s.valArray[i] << "  " << endl ;
        cout << "-------------------------" << endl;

        }

}// END 2ND FUNCTION



void function3(struct Calculation s)
{
    cout << "FUNCTION 3 WORKS!" << endl;

    cout << "s.input: " << s.input << endl;

    cout << "s.value: " << s.value << endl;

    cout << "s.interestRate: " << s.interestRate << endl;

    cout << endl;



    string buf;
    while (true)
        {

        cout << "How many years:  ";

        getline(cin, buf);

        s.length = atof(buf.c_str());

        if(s.length <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.length > 0)
            {
            cout << "GOOD LENGTH: " << s.length << endl;
            break;
            }

        cout << endl;
        }

    double year;
    string buf1;
    while (true)
        {

        cout << "What year is it:  ";

        getline(cin, buf1);

        year = atoi(buf1.c_str()); //ATOI FOR INTEGER

        if(year <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(year > 0)
            {
            cout << "GOOD YEAR: " << year << endl; //test
            break;
            }

        cout << endl;
        }



    cout << "Function is monthly " << endl;
    cout << "s.input: " << s.input << endl;

    cout << "s.value: " << s.value << endl;

    cout << "s.interestRate: " << s.interestRate << endl;

    cout << "s.interval: " << s.interval << endl;

    cout << "s.length of MONTHS: " << s.length << endl;


    double intervalArray = s.length / s.interval;
    double month;

    cout << "num: " << intervalArray << endl;
    cout << endl;


//calculation function --------------------------------------------------------
    s.valArray[0] = s.value;

    //first calculation for 2nd array
    double temp4 = s.value * s.interestRate;
    s.valArray[1] = temp4;


    cout << setprecision(0) << "Length : " << s.length << " | ";

    cout << "Interest rate : " << setprecision(2) << fixed << s.interestRate << endl;

    //starts at 2 for 3rd array
    for(int i = 2;  i < s.length+1; i++)
        {
        s.valArray[i] = s.valArray[i-1] * s.interestRate;
        }

//WHAT IS THE YEAR, 2021 + 1

//print function --------------------------------------------------------

    cout << "-------------------------" << endl;

    cout << "Year: " << setprecision(0) << year << endl ;

    cout << "Array [ 0 ]" ;    cout << "    Year: [ 0 ]" << endl;

    cout << "Value : " << setprecision(2) << fixed << s.value << "  " << endl ;
    cout << "-------------------------" << endl;
    //starts at 1 because 0 is start


    for(int i = 1; i < s.length+1; i++)
        {

        cout << "-------------------------" << endl;

        cout << "Year: " << setprecision(0) << year+i << endl ;

        cout << "Array [ "<< i << " ]" ;   cout << "    Year: [ " <<  setprecision(0) << i  << " ]" << endl;
        cout << "Value : " << setprecision(2) << fixed << s.valArray[i] << "  " << endl ;
        cout << "-------------------------" << endl;

        }






}// END OF FUNCTION 3







