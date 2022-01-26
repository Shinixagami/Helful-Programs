/*
* How to use stringstream to format outpu
*/

#include <iomanip>   //for setprecision
using std::fixed;
using std::setprecision;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>   //to allow format control when converting numbers to strings
using std::stringstream;

#include <string>
using std::string;

int main(int argc, char argv[])
{
	stringstream cost_ss;        //format control of cost variable


    float cost = 5.837652; // ITEM COST


	cost_ss.clear();


	cout << "cost: " << cost << endl; //test


	string desc = "item desc."; // ITEM DESCRIPPTION

    cost_ss << "AMOUNT(" << fixed << setprecision(2) << cost << ")  DESC(" << desc << ")" << endl;



    cout << " cost = " << fixed << setprecision(2) << cost << endl;

	cout << cost_ss.str() << endl;

    //cout <<	   content of cost_ss:  cost = 5.84

	return 0;
}
