/**********************************************************
NAME: Vin Gabriel Fillon 09/04/2021 CompSci-165
TITLE: Lab Assignment 2
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Cashier program
************************************************************/
#include <iostream>

using std::cin;   //c input
using std::cout;   //c output
using std::endl;    //end line

#include <string> //string

double change, cost, paid;

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

    cout << "What was the cost of the purchase: $" ;
	cin >> cost ;

	cout << "How much money was tendered: $" ;
    cin >> paid ;

    cout << endl ; //drops line down

    change = paid - cost; //calculations for the change,

    cout << "Total Change: $" << change << endl ; // prints out change

    change *= 100; //to turn change into a whole number in order to make my life easier

    int Bill_100;   //integer to not display decimals when output is printed
    if (change >= OneHundredBill){

        Bill_100 = change / OneHundredBill;   //dividing to find the number of bills

        cout << Bill_100 << "x $100 bill"  << endl; //prints output in integer format

        change -= OneHundredBill * Bill_100;  //subtracting to get rid of the bills already counted
    }

    int Bill_50;   //integer to not display decimals when output is printed
    if (change >= FiftyBill){

        Bill_50 = change / FiftyBill;

        cout << Bill_50 << "x $50 bills"  << endl; //prints output in integer format

        change -= FiftyBill * Bill_50; //subtracting to get rid of the bills already counted
    }

    int Bill_20; //integer to not display decimals when output is printed
    if (change >= TwentyBill){

        Bill_20 = change / TwentyBill; //dividing to find the number of bills

        cout << Bill_20 << "x $20 bills"  << endl; //prints output in integer format

        change -= TwentyBill * Bill_20; //subtracting to get rid of the bills already counted
    }

    int Bill_10; //integer to not display decimals when output is printed
    if (change >= TenBill){

        Bill_10 = change / TenBill; //dividing to find the number of bills

        cout << Bill_10 << "x $10 bills"  << endl; //prints output in integer format

        change -= TenBill * Bill_10; //subtracting to get rid of the bills already counted
    }

    int Bill_5; //integer to not display decimals when output is printed
    if (change >= FiveBill){

        Bill_5 = change / FiveBill; //dividing to find the number of bills

        cout << Bill_5 << "x $5 bills"  << endl; //prints output in integer format

        change -= FiveBill * Bill_5; //subtracting to get rid of the bills already counted
    }

    int Bill_1; //integer to not display decimals when output is printed
    if (change >= OneBill){

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

    return 0;

}



