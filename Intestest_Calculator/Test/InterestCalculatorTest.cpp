/*******************************************************************************
TITLE:  Interest Rate Calculator
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:


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

#include <cstdlib> // for atoi and atof


struct Calculations
{
    double price;
    double percentage;
    double stoploss;
    double subtotal;
    double total;
    string type;

};

Calculations InputStopLoss();
Calculations InputInterest();

// function prototypes for printing table layout
void outputTableStopLoss();
void outputTableInterest(string Type, Calculations anyCalc);


int main() {

    Calculations storeInterest, storeStopLoss; //store values for serialization, and table print.


    //loop function for inputs.
    for (int i = 0; i < 1;){

    string answer;

    cout <<"Which calculator would you like to use?" << endl;
    cout <<"Stop Loss or Interest (S/I)" << endl;


    getline(cin, answer);
    cout << "You entered: " << answer << endl;

    if ( answer == "I" ||  answer == "i" || answer == "Interest" ||  answer == "INTEREST" ||  answer == "interest"  ) {
        storeInterest = InputInterest();  //interest calculator func

        //print nice table
        //outputTableStopLoss();
        outputTableInterest(storeInterest.type, storeInterest);

        i += 1;
    }

    if ( answer == "S" ||  answer == "s" || answer == "Stop Loss" ||  answer == "STOP LOSS" ||  answer == "stop loss" ||  answer == "Stop" ||  answer == "STOP"  ||  answer == "Stop") {
        storeStopLoss = InputStopLoss();  //interest calculator func

        //outputTableStopLoss();
        i += 1;

    }

        if (i != 1) {
            cout << endl << "Invalid Input please try again! " << endl << endl;
        }
    }

    return 0;

}

Calculations InputStopLoss () {

    Calculations StopLoss;  //this struct is only for to get input and return values

    StopLoss.type = "Stop Loss";

    cout << endl << " ~Stop Loss Calculator Activated~ " << endl << endl ;

    cout << "Please enter the value: ";
    string buf1 ;
    cin >> buf1; StopLoss.price = atof (buf1.c_str());
    cin.ignore(1000, 10);


    cout << "Please enter the Stop Loss percentage you want (in whole numbers) : ";

    string buf2 ;
    cin >> buf2; StopLoss.percentage = atof(buf2.c_str());
    cin.ignore(1000, 10);


    StopLoss.percentage *= .01; //makes percentage into an actual multiple number

    StopLoss.stoploss = StopLoss.price * StopLoss.percentage;

    StopLoss.total = StopLoss.price - StopLoss.stoploss;

    cout << endl << endl ;

    cout << "Calculation Type: " << StopLoss.type  << endl ;

    cout << "Entry Value: " << StopLoss.price  << endl ;

    cout << "Percent: " << StopLoss.percentage <<"%" << " or " << StopLoss.percentage*100 << "%" << endl;

    cout << "Set your Stop Loss at " << StopLoss.total << endl << endl;

    return StopLoss;

}

Calculations InputInterest() {

    Calculations Interest;  //this struct is only for to get input and return values

    Interest.type = "Interest";



    cout << endl << " ~Interest Calculator Activated~ " << endl << endl ;

    cout << "Please enter the value : ";
    string buf1 ;
    cin >> buf1; Interest.price = atof (buf1.c_str());
    cin.ignore(1000, 10);

    cout << "Please enter the interest rate you want (in whole numbers) : ";
    string buf2 ;
    cin >> buf2; Interest.percentage = atof(buf2.c_str());
    cin.ignore(1000, 10);

    Interest.percentage *= .01; //makes percentage into an actual multiple number
    Interest.subtotal =  Interest.price * Interest.percentage;
    Interest.total = Interest.price + Interest.subtotal;

    cout << endl << endl ;

    cout << "Calculation Type: " << Interest.type  << endl ;

    cout << "Percent: " << Interest.percentage <<"%" << " or " << Interest.percentage*100 << "%" << endl;

    cout << "Interest is: $" << Interest.subtotal  << endl << endl;
    cout << "After Appreciation Value will be: $" << Interest.total  << endl << endl;

    return Interest;

}

void outputTableStopLoss () {
    cout <<  endl;
    cout << "Table unavailable. cus i didn't make one \n";
    cout << "---------  -------  ----------   ------------\n";
}


void outputTableInterest(string Type, Calculations anyCalc)
{
cout <<  endl;


    cout <<  endl;
    cout << "Start Val  Percent  Interest     Total w/ interest\n";
    cout << "---------  -------  ----------   ------------\n";

  //Sequence number
  cout.width(4); cout << anyCalc.price << ' ';
//Age

//cout.setf(ios::left);

  cout.width(8); cout << anyCalc.percentage*100 << "%" ;
//City
  cout.width(8); cout << anyCalc.subtotal;
//Major
  cout.width(11); cout << anyCalc.total << endl;
  cout.unsetf(ios::left); cout.width(1);  //resets the next line

}











