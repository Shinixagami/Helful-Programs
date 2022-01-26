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

void CallWelcome ();
void  CallTime ();
double CallDenomination (double change, int Bill);

/*******************************************************************************
* Function : Main function
* Parameters :  Total (IN) , Denomination (IN)
* Return : 0
* Description :
*       Prints Welcome Message - Function
*       Prints Date & Time - Function
*       Calculates denomination of bills -Function
*
*******************************************************************************/

int main () {

    CallWelcome ();
    CallTime ();

    double total, deno;

    cout << "Enter Total Change : ";
    cin >> total; //total becomes change for CallDenomination Func.

    cout << endl;

    cout << "In which denomination of bills would you like them to be in?" << endl ;
    cout << "(100, 50, 20, 10, 5, 1)"  << endl;
    cin >> deno;  //deno switches if statements ON/OF

    cout << endl;


    // activates CallDenomination Func with input 100
    if  (total >= 100 && deno >= 51) {
        cout << CallDenomination(total, 100);
        cout << endl;
    }

    // activates CallDenomination Func with input 50
    if (total >= 50 && deno >= 21 && deno <= 50 ) {
        cout << CallDenomination(total, 50);
        cout << endl;
    }

    // activates CallDenomination Func with input 20
    if (total >= 20 && deno >= 11 && deno <= 20) {
        cout << CallDenomination(total, 20);
        cout << endl;
    }

    // activates CallDenomination Func with input 10
    if (total >= 10 && deno >= 6 && deno <= 10) {
        cout << CallDenomination(total, 10);
        cout << endl;
    }

    // activates CallDenomination Func with input 5
    if (total >= 5 && deno >= 2 && deno <= 5) {
        cout << CallDenomination(total, 5);
        cout << endl;
    }

    // activates CallDenomination Func with input 1
     if (total >= 1 && deno <= 1) {
        cout << CallDenomination(total, 1);
        cout << endl;
    }


    //end of program
    return 0;

}


/*******************************************************************************
* Function : Call Denomination
* Parameters :  Change (IN) , Bill (IN)
* Return : change
* Description :
*       Takes Change, and Bill Notation
*       and prints out Denotation,
*       then remainder
*******************************************************************************/

// input change , and bill denomination
double CallDenomination (double change, int Bill){

    if ( change >= Bill){

            cout << "Bill denomination ($" << Bill<< ")" <<endl;

            using std::cout;   //c output
            int DenotationOut;   // integer that prints out bills.

            DenotationOut = change / Bill; //dividing to find the number of bills
            cout << DenotationOut << "x $" << Bill << " bills"  << endl; //prints output in integer format
            change -= Bill * DenotationOut; //subtracting to get rid of the bills already counted

            cout << "Remainder: " ; // makes it look like the remainder is the return func.

            //returns change or remainder
            return change;

    }


}

/*******************************************************************************
* Function :  Call Welcome
* Parameters :  N/A
* Description :
* Return : void
*       Prints welcome message.
*******************************************************************************/

void CallWelcome (){

    cout << "Welcome to my Program! " <<  endl;
}
/*******************************************************************************
* Function :  Call Time
* Parameters :  N/A
* Return : void
* Description :
*       Prints current date and time.
*******************************************************************************/

void CallTime (){

    time_t  currTime = time(NULL) ;
    cout << "The current date and time is: " << ctime(&currTime) << endl ;

}



