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


#include <cmath>  // pow(a,b);

struct Calculation
{
    double val;

    double valFound;

    int bufLength;


    double valArray[100];
};




int main()
{
    Calculation s;



    string buf1;
    while (true)
        {

        cout << "please enter the decimal place: " ;

        getline(cin, buf1);

        s.val = atof(buf1.c_str());

        if(s.val <= 0)
            {
            cout << "try again." << endl;
            }

        //even if its decimal its still greater than 0
        if(s.val > 0)
            {
            cout << "Input is good." << endl;
            break;
            }

        cout << endl;

        }


    //Example
    //1 / 10 = .10
    //1 / 100 = .001
    //1 / 1000 = .0001


    //function will only work for decimals
    if(s.val < 1)
        {

                                //-1 to get rid of point character  #.##
        s.bufLength = buf1.length()-1 ;
        cout << "buf Length: " << s.bufLength <<endl;


        cout << endl;
        cout << "s.val Value: " << fixed << setprecision(s.bufLength) << s.val <<endl;


        //calculations ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        double powerD ; //for power
        double num1;  //division to make the the value go down a decimal place
        double numCounter = 0; //just a simple counter.

        cout << endl;

         for (int i = 0; i < 20; i++)
            {
            cout << "--------------------------" << endl;
            cout << "i:  " << i <<endl;


            //1 to the power of i
            //powerDown  powers 10 using i
            //pow(a,b) is the power function.
            powerD = pow(10, i);

            cout << "power : " << fixed << setprecision(0) << powerD <<endl;

            //num1 moves a decimal place down each iteration.
            //for each time powerDown grows the division gets smaller and smaller
            //this causes num1 to move down a decimal point.
            num1 = 1 / powerD;


            cout << "1 / " << fixed << powerD <<" = " << fixed << setprecision(s.bufLength) << num1 << endl;

            cout  << "num1 [ " << fixed << setprecision(s.bufLength) << num1 << " ] "<<endl;


            //counter
            numCounter = i;

            cout << "numcounter : "<< fixed << setprecision(0) << numCounter <<endl;



            if(num1 == s.val)
                {
                cout <<" ~ RIGHT VALUE FOUND e~" << endl;
                cout << "--------------------------" << endl;

                s.valFound = num1; //stores value
                break;
                }

            //remember num1 goes down a decimal point each turn
            // if num1 <=  .0001
            if(num1 <= s.val)
                {
                cout <<" ~ RIGHT VALUE FOUND l~" << endl;
                cout << "--------------------------" << endl;

                s.valFound = num1; //stores value
                break;
                }

            cout << "--------------------------" << endl;


            }//END OF FOR LOOP

        cout << endl;

        cout  << "Decimal Place for iteration:  " << fixed << setprecision(s.bufLength) << num1 <<endl;

        cout << endl;


        }//END OF if



//if input > DPFI








//IN: .0034


//val 0 = 0.0034
//val 1 = 0.0044
//val 2 = 0.0054



// num1 =  array 2 - array 0

    //num 1 = .0020

//if  num 1  > .0010   //take it from correct iteration

//THEN TURN ON REBALANCE ~~~~~~~




//--------------------------

//IN: .003


//val 0 = 0.003
//val 1 = 0.004
//val 2 = 0.005


// num1 =  array [2] - array [1]

    //num 1 = .001    <take it from correct iteration

//if num1 = .003

//THEN TURN OFF REBALANCE ~~~~~~~

double num1 = s.val;

s.valFound  = num1 / 10;


    cout << endl;
    //---------------------------------------------------------------


    double eValF = s.valFound;
    double eVal = s.val;

    double temp;
    double printNum;
    if(eValF != eVal)
    {
    cout << " --- REBALANCING B --- " << endl;

        for (int i = 0; i < 10; i++)
        {
        cout << "*--------------------------*" << endl;
        //addition to iteration.
        temp = eValF * i;

        printNum = eVal + temp;



        cout  << "Value [ " << i << " ] : " << fixed << setprecision(s.bufLength) << printNum <<endl;
        cout << "*--------------------------*" << endl;

        }



    }














    double temp2;
    double opOn = 0;



    //everytime you subtract one will always be greater than the other.
    temp2 = s.val - s.valFound ;

    cout << "      TEMP2 : " << fixed << setprecision(s.bufLength+1) << temp2 << endl;
    //IF  TEMP2 > .0010 THEN DO THIS




    //IF ABOVE 10 GO




        if (temp2 >= s.valFound && opOn == 1)
            {
            double temp1;

            cout << " --- REBALANCING B --- " << endl;

            temp1  = s.valFound / 10; //decimal down

            cout << " correct 2 F : " << fixed << setprecision(s.bufLength+1)  << temp1 << endl;

            cout << endl;

            }










//this portion works.




    cout << endl;

    //print values ----------------------- for loop
    if (s.val < 1)
        {
        double printNum;
        double temp;

        for(int n = 0; n < 5; n++)
            {
            cout << "*--------------------------*" << endl;
            //addition to iteration.
            temp = s.valFound * n;

            printNum = s.val + temp;


            cout  << "Value [ " << n << " ] : " << fixed << setprecision(s.bufLength) << printNum <<endl;
            cout << "*--------------------------*" << endl;
            }

        }


    if (s.val >= 1)
        {
        cout << "No need to find decimal places" << endl;
        }







}



