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
    double price; //100 arrays
    double val;
    int rep;
    double priceApp;


    string bufNum;


    double increasedByArray[100];


    double valArray[100];
};


void function1priceApp(struct Calculation s);


int main()
{
    Calculation s;
    //s.value
    //s.interestRate

     string buf1;
    while (true)
        {

        cout << "please enter the amount of coins/shares: " ;

        getline(cin, buf1);

        s.val = atof(buf1.c_str());

        if(s.val <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.val > 0)
            {
            cout << "GOOD: " << s.val << endl;

            //cout << "~CONVERTED: " << fixed <<  setprecision(2) << s.interestRate << "% "<< endl;

            break;
            }

        cout << endl;

        }



   //bufNum
    while (true)
        {

        cout << "Please enter the price: " ;

        getline(cin, s.bufNum);

        s.price = atof(s.bufNum.c_str());


        if(s.price <= 0)
            {
            cout << "try again bitch." << endl;
            }


        if(s.price > 0)
            {
            cout << "GOOD price: " << s.price << endl;
            break;
            }

        cout << endl;

        }





    string buf2;
    while (true)
        {

        cout << "please enter the repetitions " ;

        getline(cin, buf2);

        s.rep = atoi(buf2.c_str());

        if(s.rep  <= 0)
            {
            cout << "try again bitch." << endl;
            }

        if(s.rep  > 0)
            {
            cout << "GOOD rep: " << s.rep  << endl;

            //cout << "~CONVERTED: " << fixed <<  setprecision(2) << s.interestRate << "% "<< endl;

            break;
            }

        cout << endl;

        }




    function1priceApp(s);



}

void function1priceApp(struct Calculation s)
{
    cout << "PRICE APP FUNCTION!" << endl;

    cout << "s.price: " << s.price << endl;

    cout << "s.val: " << s.val<< endl;

    cout << "s.rep: " << s.rep << endl;

    cout << endl;


    //.19


    //check .19 length = 2


    //double var = .19 + .01








    string tempS = s.bufNum;


    int var = tempS.length();


    cout << "length :" << var << endl;




    int addOne;

    addOne = var - 1;




//calculation function --------------------------------------------------------


    //s.valArray

    //s.priceApp
    //s.increasedBy

    //starts at 2 for 3rd array




    s.increasedByArray[0] = 0;

    double temp = 0;

    double temp2;

    for(int i = 0;  i < s.rep +1; i++)
        {



        temp2 = 0.01 * i;


        cout << "temp: " << temp;



        s.priceApp  s.price+i;


        s.valArray[i] = s.priceApp * s.val;




        cout << "----------------------------- "  << endl;

        cout << fixed << setprecision(2) << "s.valArray: " << s.valArray[i] << endl << endl;

/*

                    temp = s.valArray[i] - s.valArray[i-1];

                    //complex
                    s.increasedByArray[i] = temp;

                    cout << "temp: " << temp << endl ;
                    cout << "s.increasedByArray " << s.increasedByArray[i] << endl ;

*/


        }


 cout << endl;





 /*

//print function --------------------------------------------------------

    double increase;
    for(int i = 1; i < s.rep+1; i++)
        {

        cout << "-------------------------" << endl;

        cout << "Array [ "<< i << " ]  " ;

        cout << fixed  << setprecision(2) << s.val << " x " << s.price << " = ";

        cout << setprecision(2) << s.valArray[i] << "  " << endl ;






        increase = s.valArray[i] - s.valArray[i-1] ;


        cout << "increased by: " << setprecision(2) << increase << endl ;


        cout << "-------------------------" << endl;

        }


*/



}// END OF FUNCTION 3







