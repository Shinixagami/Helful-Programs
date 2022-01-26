/**********************************************************
NAME: Vin Gabriel Fillon 09/16/2021 CompSci-165
TITLE: Lab Assignment 2a
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Cashier program
************************************************************/
#include <iostream>
#include <ctime>  //time
#include <string> //string

using std::string;
using std::cin;   //c input
using std::cout;   //c output
using std::endl;    //end line

string name, answer, EncoreR;

double change, cost, paid, encore = 0;   //encore is the loop for running the the code again.

float Bills, Hundred = 0, Fifty = 0, Twenty = 0, Ten = 0, Five = 0, One = 0;

/*using notations of x100 to get rid of decimal numbers. Will
use these numbers to divide and subtract from whats left over */
double OneHundredBill = 10000;
double FiftyBill = 5000 ;
double TwentyBill = 2000 ;
double TenBill =1000 ;
double FiveBill =500;
double OneBill =100;
double FiftyCent = 50 ;
double TwentyFiveCent = 25 ;
double TenCent = 10 ;
double FiveCent =5 ;
double OneCent = 1;

int main(){

    cout << "Welcome To My Change Program! " << endl;

    while (encore == 0) {

        time_t  currTime = time(NULL) ;
        cout << "The current date and time is: " << ctime(&currTime) << endl ;

        cout << "Would you like your change in a specific denomination bills? (Yes/No)" << endl;
        cin >> answer;

        // if no activates all the change denomination
        if (answer == "N" || answer == "n" || answer == "no" ||  answer == "NO" || answer == "No"  ) {
            Hundred = 1;
            Fifty = 1;
            Twenty = 1;
            Ten = 1;
            Five = 1;
            One = 1;
        }


        // if yes activates which bills to get rid off
        if (answer == "Y" || answer == "y" || answer == "yes" ||  answer == "YES" || answer == "Yes" ) {
                cout << "In which denomination of bills would you like them to be in?" << endl ;
                cout << "100, 50, 20, 10, 5, 1."  << endl;
                cin >> Bills;
                cout << endl;
        }

        //Lines below have a switch on and off switch method
        //$100 BILLS    0 = off       1 = ON
        if  (Bills == 100) {
            Hundred = 1;   //CONFUSING but if hundred = 1, 100 change is allowed
            Fifty = 1;
            Twenty = 1;
            Ten = 1;
            Five = 1;
            One = 1;
        }

        //$50 BILLS    0 = off       1 = ON
        if  (Bills == 50) {
            Hundred = 0;
            Fifty = 1;
            Twenty = 1;
            Ten = 1;
            Five = 1;
            One = 1;
        }

        //$20 BILLS    0 = off       1 = ON
        if  (Bills == 20 ) {
            Hundred = 0;
            Fifty = 0;
            Twenty = 1;
            Ten = 1;
            Five = 1;
            One = 1;
        }

        //$10 BILLS    0 = off       1 = ONN
          if  (Bills == 10 ) {
            Hundred = 0;
            Fifty = 0;
            Twenty = 0;
            Ten = 1;
            Five = 1;
            One = 1;
        }

        //$5 BILLS    0 = off       1 = ON
          if  (Bills == 5 ) {
            Hundred = 0;
            Fifty = 0;
            Twenty = 0;
            Ten = 0;
            Five = 1;
            One = 1;
        }

        //$1 BILLS    0 = off       1 = ON
          if  (Bills == 1 ) {
            Hundred = 0;
            Fifty = 0;
            Fifty = 0;
            Twenty = 0;
            Ten = 0;
            Five = 0;
            One = 1;
        }

        cout << "What was the cost of the purchase: $" ;
        cin >> cost ;

        cout << "How much money was tendered: $" ;
        cin >> paid ;

        cout << endl ; //drops line down

        change = paid - cost; //calculations for the change,

        cout << "Total Change: $" << change << endl ; // prints out change

        change *= 100; //to turn change into a whole number in order to make my life easier

        int Bill_100;   //integer to not display decimals when output is printed
        if (Hundred == 1 && change >= OneHundredBill ){   //1 is off

            Bill_100 = change / OneHundredBill;   //dividing to find the number of bills
            cout << Bill_100 << "x $100 bill"  << endl; //prints output in integer format
            change -= OneHundredBill * Bill_100;  //subtracting to get rid of the bills already counted
        }

        int Bill_50;   //integer to not display decimals when output is printed
        if (Fifty == 1 && change >= FiftyBill){

            Bill_50 = change / FiftyBill;
            cout << Bill_50 << "x $50 bills"  << endl; //prints output in integer format
            change -= FiftyBill * Bill_50; //subtracting to get rid of the bills already counted
        }

        int Bill_20; //integer to not display decimals when output is printed
        if (Twenty  == 1 && change >= TwentyBill){

            Bill_20 = change / TwentyBill; //dividing to find the number of bills
            cout << Bill_20 << "x $20 bills"  << endl; //prints output in integer format
            change -= TwentyBill * Bill_20; //subtracting to get rid of the bills already counted
        }

        int Bill_10; //integer to not display decimals when output is printed
        if (Ten == 1 && change >= TenBill){

            Bill_10 = change / TenBill; //dividing to find the number of bills
            cout << Bill_10 << "x $10 bills"  << endl; //prints output in integer format
            change -= TenBill * Bill_10; //subtracting to get rid of the bills already counted
        }

        int Bill_5; //integer to not display decimals when output is printed
        if (Five == 1 && change >= FiveBill){

            Bill_5 = change / FiveBill; //dividing to find the number of bills
            cout << Bill_5 << "x $5 bills"  << endl; //prints output in integer format
            change -= FiveBill * Bill_5; //subtracting to get rid of the bills already counted
        }

        int Bill_1; //integer to not display decimals when output is printed
        if (One == 1 && change >= OneBill){

            Bill_1 = change/ OneBill; //dividing to find the number of bills
            cout << Bill_1 << "x $1 bills"  << endl; //prints output in integer format
            change-= Bill_1 * OneBill; //subtracting to get rid of the bills already counted
        }

        int Cent_50; //integer to not display decimals when output is printed
        if (change >= FiftyCent){

            Cent_50 = change / FiftyCent; //dividing to find the number of bills
            cout << Cent_50 << "x 50-cent coin"  << endl; //prints output in integer format
            change-= FiftyCent * Cent_50; //subtracting to get rid of the bills already counted
        }

        int Cent_25; //integer to not display decimals when output is printed
        if (change >= TwentyFiveCent){

            Cent_25 = change / TwentyFiveCent; //dividing to find the number of bills
            cout << Cent_25 << "x 25-cent coin"  << endl; //prints output in integer format
            change -= TwentyFiveCent * Cent_25; //subtracting to get rid of the bills already counted
        }

        change += 0.001;  //to reset the round off error when dividing -there will be a remainder.

        int Cent_10; //integer to not display decimals when output is printed
        if (change >= TenCent) {

            Cent_10 = change / TenCent; //dividing to find the number of bills
            cout << Cent_10 << "x 10-cent coin"  << endl; //prints output in integer format
            change -= TenCent * Cent_10; //subtracting to get rid of the bills already counted

        }

        int Cent_05; //integer to not display decimals when output is printed
        if (change >= FiveCent) {

            Cent_05 = change / FiveCent; //dividing to find the number of bills
            cout << Cent_05 << "x 5-cent coin"  << endl; //prints output in integer format
            change -= FiveCent * Cent_05; //subtracting to get rid of the bills already counted
        }

        int Cent_01; //integer to not display decimals when output is printed
        if (change >= OneCent) {

            Cent_01 = change / OneCent; //dividing to find the number of bills
            cout << Cent_01 << "x 1-cent coin"  << endl; //prints output in integer format
            change -= OneCent * Cent_01; //subtracting to get rid of the bills already counted

        }

        cout << endl;
        cout << "Would you like to do a new transaction? (Yes/No)" << endl;
        cin >> EncoreR;
        cout << endl;

        if (EncoreR == "Y" || EncoreR == "y" || EncoreR == "yes" ||  EncoreR == "YES" || EncoreR == "Yes" ) {

            encore = 0;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            change = 0;

            }

        else {
            encore = 1;
            cout << "Program Terminated." << endl;
            }

    }

    return 0;

}



