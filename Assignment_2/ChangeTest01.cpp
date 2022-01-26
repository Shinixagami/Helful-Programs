/**********************************************************
NAME: Vin Gabriel Fillon 09/04/2021 CompSci-165
TITLE: Lab Assignment 2
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Cashier program
************************************************************/

#include <iostream>

using std::cin; //c input
using std::cout; //c output
using std::endl; //end line

#include <string> //string
using std::getline;  //get line

double change1, cost = 0.0, paid = 0.0;

double OneHundredBill = 10000 ;
double FiftyBill = 5000 ;
double TwentyBill = 2000 ;
double TenBill =1000 ;
double FiveBill = 500;
double OneBill =100;
double FiftyCent = 50;
double TwentyFiveCent = 25;
double TenCent = 10 ;
double FiveCent =5 ;
double OneCent = 1;

int main() {

    cout << "How much money did it cost: $" ;
    cin >> cost ;

    cout << "you entered: " << cost << endl;

    cout << "How much money did they give: $" ;
    cin >> paid ;

    cout << "you entered: " << paid << endl ;

    cout << endl;
    change1 = paid - cost;    //change calculations
    cout << "The total Change is: $" << change1 << endl;

    change1 *= 100; // sets double into integer -so no more decimal problems.
    cout << "TChange = " << change1 << endl << endl;


    //Calculations using if and else statements

    int Bill_100;  //this is for printing the output and calculations
    if (change1 >= OneHundredBill) {
        cout << "~Calculations for $100 Bills " << endl;
        Bill_100 = change1 / OneHundredBill;

        cout << "How Many $100 bills: " << Bill_100 << endl ;

        change1 -= OneHundredBill * Bill_100; // Subtracts the calculated portion above.
        cout << "TChange = " << change1 << endl << endl ;

    }


    int Bill_50;  //this is for printing the output and calculations
    if (change1 >= FiftyBill) {
        cout << "~Calculations for $50 Bills " << endl;
        Bill_50 = change1 / FiftyBill;

        cout << "How Many $50 bills: " << Bill_50 << endl ;

        change1 -= FiftyBill * Bill_50; // Subtracts the calculated portion above.
        cout << "TChange = " << change1 << endl << endl;

    }


    int Bill_20;  //this is for printing the output and calculations
    if (change1 >= TwentyBill) {
        cout << "~Calculations for $20 Bills " << endl;
        Bill_20 = change1 / TwentyBill;

        cout << "How Many $20 bills: " << Bill_20 << endl ;

        change1 -= TwentyBill * Bill_20; // Subtracts the calculated portion above.
        cout << "TChange = " << change1 << endl << endl ;
    }

    int Bill_10;  //this is for printing the output and calculations
    if (change1 >= TenBill) {
        cout << "~Calculations for $10 Bills " << endl;
        Bill_10 = change1 / TenBill;

        cout << "How Many $10 bills: " << Bill_10 << endl ;

        change1 -= TenBill * Bill_10; // Subtracts the calculated portion above.
        cout << "TChange = " << change1 << endl << endl ;
    }

    int Bill_5;  //this is for printing the output and calculations
    if (change1 >= FiveBill) {
        cout << "~Calculations for $5 Bills " << endl;
        Bill_5 = change1 / FiveBill;

        cout << "How Many $5 bills: " << Bill_5 << endl ;

        change1 -= FiveBill * Bill_5; // Subtracts the calculated portion above.
        cout << "TChange = " << change1 << endl << endl ;
    }

    //dollar bill   -------------------------------------------------------
    int Bill_1 ;    //this is for printing the output and calculations
    if (change1 >=  OneBill ) {
        cout << "~Calculations for $1 Bills " << endl;
        Bill_1 = change1 / OneBill;  // 100 / 100

        cout << "How Many $1 bills: " <<  Bill_1 << endl ;

         change1 -= Bill_1 * OneBill;

        cout << "TChang = " <<  change1 << endl << endl ;
    }

    // CENTS CALCULATIONS
    int Cent_50;  //this is for printing the output and calculations
    if (change1 >= FiftyCent) {
        cout << "~Calculations for $0.50 cents " << endl;
        Cent_50 = change1 / FiftyCent;

        cout << "How Many $0.50 cents: " << Cent_50 << endl ;

        change1 -= FiftyCent * Cent_50; // Subtracts the calculated portion above.
        cout << "TChange = " << change1 << endl << endl ;
    }

    int Cent_25;  //this is for printing the output and calculations
    if (change1 >= TwentyFiveCent) {
        cout << "~Calculations for $0.25 cents " << endl;
        Cent_25 = change1 / TwentyFiveCent;

        cout << "How Many $0.25 cents: " << Cent_25 << endl ;

        change1 -= TwentyFiveCent * Cent_25; // Subtracts the calculated portion above.
        cout << "TChange = " << change1 << endl << endl ;
    }

    int Cent_10;
    if (change1 >= TenCent) {

        cout << "~Calculations for $0.10 cents " << endl;
        Cent_10 = change1 / TenCent;

        cout << "How Many $0.10 cents: " << Cent_10 << endl ;

        change1 -= TenCent * Cent_10;
        cout << "TChange = " << change1 << endl << endl ;
    }

    int Cent_5;
    if (change1 >= FiveCent) {

        cout << "~Calculations for $0.05 cents " << endl;
        Cent_5 = change1 / FiveCent;

        cout << "How Many $0.05 cents: " << Cent_5 << endl ;

        change1 -= FiveCent * Cent_5;
        cout << "TChange = " << change1 << endl << endl ;
    }

    int Cent_01;
    if (change1 >= OneCent) {

        cout << "~Calculations for $0.01 cents " << endl;
        Cent_01 = change1 / OneCent;

        cout << "How Many $0.01 cents: " << Cent_01 << endl ;

        change1 -= OneCent * Cent_01;
        cout << "TChange = " << change1 << endl << endl ;
}

    cout << "~~~FINAL TChange OR remainded ##.##RR = " << change1 << endl ;
    return 0;

}


