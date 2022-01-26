/*******************************************************************************
TITLE: Percentage Calculator
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    finds the percentage of a move up or down
    Programs takes input of prices or percentage of a move
********************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string>
using std::getline; //get line for input
using std::string;

#include <algorithm>
using std::swap;

#include <cstdlib> // for atoi and atof

struct Calculations
{
    double price;
    double price2;
    double percentage;
    double stoploss;
    double subtotal;
    double total;
    string type;

};

Calculations InputPercentage();
Calculations InputValue();

int main () {
    double input;

    cout << "Would you input a value or a percent \n";
    cout << "~~~~~~~~~~~~~~~~~~ \n \n" ;

    InputPercentage();
    InputValue();

    return 0;
}

Calculations InputPercentage() {

    Calculations funcPercentage;

    string type = "Move up/down ~Percentage" ;
    double outputPerc;

    cout << "~Percent Confirmed.  \n ";

    string buf1;
    cout << "1. Input the starting price: ";
    cin >> buf1; funcPercentage.price = atoi(buf1.c_str());
    cin.ignore(1000, 10);

    string buf2;
    cout << "2. Input the percentage up or down (+/-) : ";
    cin >> buf1; funcPercentage.percentage = atoi(buf1.c_str());
    cin.ignore(1000, 10);

    outputPerc = funcPercentage.percentage;

    funcPercentage.percentage *= 0.01;

    funcPercentage.subtotal = funcPercentage.percentage * funcPercentage.price;

    funcPercentage.total = funcPercentage.subtotal + funcPercentage.price;

    cout << "type:  " << funcPercentage.type << endl;
    cout << "percentage:  " << outputPerc << "% \n";
    cout << "subtotal: " << funcPercentage.subtotal << endl;
    cout << "total: " << funcPercentage.total << endl;

    funcPercentage.total = funcPercentage.price;

    return funcPercentage;
}

Calculations InputValue() {

    Calculations funcValue;

    string type = "Move up/down ~Value" ;
    double num1, num2, outputPercent;

    cout << "~Value Confirmed.  \n";

    string buf1;
    cout << "(do not input negatives) \n";
    cout << "1. Input the starting price: ";
    cin >> buf1; funcValue.price = atoi(buf1.c_str());
    cin.ignore(1000, 10);

    string buf2;
    cout << "(do not input negatives) \n";
    cout << "2. Input the second value: ";
    cin >> buf1; funcValue.price2 = atoi(buf1.c_str());
    cin.ignore(1000, 10);

    cout << endl ;


    cout << "(num1 = value2 - value 1)" << endl;

    cout << "(num 2  price )" << endl;

    cout << "(num1 / num 2)" << endl;


    if (funcValue.price >  funcValue.price2) {

        cout << "~Value of second price depreciated(-) " << endl;

        num1 = funcValue.price2 -  funcValue.price;
        //cout << "num1 : " << num1 << endl << endl ;

        num2 = funcValue.price ;   //c
        //cout << "Num2: " << num2 << endl << endl ;

        funcValue.total = num1 / num2;

        //cout << "inside func. Percent : " << funcValue.total << endl;

        outputPercent = funcValue.total * 100;

        cout << "Output percent: " << outputPercent << "% " << endl;
    }

     if (funcValue.price <  funcValue.price2) {

        cout << "~Value of first price appreciated(+) " << endl;

        num1 = funcValue.price2 -  funcValue.price;
        //cout << "num1 : " << num1 << endl << endl ;

        num2 = funcValue.price ;
        //cout << "Num2: " << num2 << endl << endl ;

        funcValue.total = num1 / num2;

        cout << "inside func. Percent : " << funcValue.total << endl;

        outputPercent = funcValue.total * 100;

        cout << "Output percent: " << outputPercent << "% " << endl;
    }

    return funcValue;

}









