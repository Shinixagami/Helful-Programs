#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double MAX_UNDER_DOLLAR = .99;
const int DOLLAR = 100;
double QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;

int main() {

    double moneyOwed = 0.0;
    double moneyPaid = 0.0;

    cout << "Customer owes: $";
    cin >> moneyOwed;

    cin.ignore(1);

    cout << "Customer pays: $";
    cin >> moneyPaid;
    cout << fixed << setprecision(2);

    //cin.ignore(1);

    //calculations

    double change = moneyPaid - moneyOwed; //what gets printed as changed
    double change1 = change; //change1 one is the same as change

    cout << "Change due: $" << change << '\n';
    cout << endl;

    int dollars = 0;
    if (change1 > MAX_UNDER_DOLLAR)
    {
        dollars = (int) (change1);                //turns change1 into integer
        cout << "Dollars: " << dollars << '\n';       //Print out dollars
        change1 -= dollars;                       //change1 = change1 - dollars

        //test
        cout << "Value of  Change1: " << change1 << endl ;
        cout << endl;
    }

    //tries puts tries to
    change1 *= DOLLAR;  // Change1 = Change1 * DOLLAR or 100

    //test
    cout << "Value of  Change1: " << change1 << endl ;
    cout << endl;

    int quarters = 0;   // quarters 0
    if (change1 > QUARTER)
    {
        quarters = change1 / QUARTER;    //.99 / .25

        cout << "since its an integer, decimals aren't included " << endl;
        cout <<  change1 << "/" << QUARTER << endl;
        cout <<  "result is: " << quarters << endl;

        cout << endl;
        cout << "OF Quarters: " << quarters << '\n';

        cout <<  "------------- "<< endl;

        cout << "Value of  Change1: " << change1 << endl ;
        cout << endl;

        cout <<  "change = " << change1 << "-" << quarters << "*" << QUARTER << endl;

        //99 - 3 * .25
        change1 -= quarters * QUARTER;   //subtracts left over amount  3.96 * .25

        cout << "Value of  Change1: " << change1 << endl ;
        cout << endl;
    }

    int dimes = 0;
    if (change1 > DIME)
    {
        dimes = change1 / DIME;           //divides

        cout << "Value of  DIME :" <<  DIME << endl ;
        cout << "Value of  DIME :" << dimes << endl ;

        cout << "output Dimes: " << dimes << '\n';


        change1 -= dimes * DIME;
        cout << "Value of  Change1: " << change1 << endl ;
        cout << endl;
    }


    int nickels = 0;
    if (change1 > NICKEL)
    {
        nickels = change1 / NICKEL;
        cout << "Nickels: " << nickels << '\n';
        change1 -= nickels * NICKEL;    //substracts nickle with
        cout << "Value of  Change1: " << change1 << endl ;
        cout << endl;
    }

    int pennies = 0;
    if (change1 > 0)
    {
        pennies = change1 +.001 ;   //has error not being precise.  added a .001 to be precise.

        cout << "Pennies: " << pennies << '\n';
        change1 = 0;
        cout << "Value of  Change1: " << change1 << endl ;
        cout << endl;


    }


    return 0;

}
