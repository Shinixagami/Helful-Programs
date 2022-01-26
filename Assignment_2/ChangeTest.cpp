#include <iostream>

using namespace std;

const double QUARTER_AMOUNT = 0.25F;
const double DIME_AMOUNT = 0.10F;
const double NICKEL_AMOUNT = 0.05F;
const double CENT_AMOUNT = 0.01F;

int main()

{
    double change; //make a double
    cout<<"Enter the amount of change (in cents): ";
    cin>>change;

    double quarters  =  change / QUARTER_AMOUNT;
    change = change - quarters;

    double dimes = change / DIME_AMOUNT;
    change = change - dimes;

    double nickels = change / NICKEL_AMOUNT;
    change = change - nickels;

    double cents = change / CENT_AMOUNT;

    cout<<"quarters=  "<<quarters<<endl;

    cout<<"dimes=  "<<dimes<<endl;

    cout<<"nickels=  "<<nickels<<endl;

    cout<<  "cents=  "<<cents<<endl;

    system("pause");
    return 0;
}



