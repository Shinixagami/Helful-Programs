#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double MAX_UNDER_DOLLAR = .99;
const int DOLLAR = 100;
const int QUARTER = 25;
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

    cin.ignore(1);
    //calculations

    double change = moneyPaid - moneyOwed;
    double change1 = change;


    cout << "Change due: $" << change << '\n';
    int dollars = 0;

    if (change1 > MAX_UNDER_DOLLAR)
    {
        dollars = (int) (change1);
        cout << "Dollars: " << dollars << '\n';
        change1 -= dollars;
    }

    change1 *= DOLLAR;

    int quarters = 0;
    if (change1 > QUARTER)
    {
        quarters = change1 / QUARTER;
        cout << "Quarters: " << quarters << '\n';
        change1 -= quarters * QUARTER;
    }

    int dimes = 0;
    if (change1 > DIME)
    {
        dimes = change1 / DIME;
        cout << "Dimes: " << dimes << '\n';
        change1 -= dimes * DIME;
    }


    int nickels = 0;
    if (change1 > NICKEL)
    {
        nickels = change1 / NICKEL;
        cout << "Nickels: " << nickels << '\n';
        change1 -= nickels * NICKEL;
    }

    int pennies = 0;
    if (change1 > 0)
    {
        pennies = change1;
        cout << "Pennies: " << pennies << '\n';
        change1 = 0;
    }


    return 0;

}
