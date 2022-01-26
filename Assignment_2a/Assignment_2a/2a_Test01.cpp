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
    cin >> deno;

    cout << endl;

    double ReturnValTotal = 0 , ReturnValDeno = 0 ;


// 100 ---------------------------------------------------------------------
    if (total >= 100 && deno >= 100) {

    if  (total >= 100 && deno >= 100) {
        cout << endl;
        ReturnValDeno = CallDenomination(total, 100);
        ReturnValTotal = ReturnValDeno;
        cout << "1st wave : return value: "<< ReturnValTotal << endl << endl;
    }

    // 50
    if (ReturnValTotal >= 50 && deno >= 51 ) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 50); //RETURN DENO
         cout << "2nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }

    // 20
    if (ReturnValTotal >= 20 && deno > 51) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 20); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //10
    if (ReturnValTotal >= 10 && deno > 51) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 10); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //5
    if (ReturnValTotal >= 5 && deno > 51) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 5); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //1
    if (ReturnValTotal >= 1 && deno > .01) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 1); //RETURN DENO
         cout << "Finale Return Value : "<< ReturnValTotal << endl;
         cout << endl;
    }
    }

// 50 ---------------------------------------------------------------------
    if (total >= 50 && deno >= 50 && deno <= 99) {
    if (total >= 50) {
         ReturnValTotal = CallDenomination(total, 50); //RETURN DENO
         cout << "1st wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    // 20
    if (ReturnValTotal >= 20) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 20); //RETURN DENO
         cout << "2nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //10
    if (ReturnValTotal >= 10 ) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 10); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //5
    if (ReturnValTotal >= 5) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 5); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //1
    if (ReturnValTotal >= 1) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 1); //RETURN DENO
         cout << "Finale Return Value : "<< ReturnValTotal << endl;
         cout << endl;
    }
    }

// 20 ---------------------------------------------------------------------
    if (total >= 20 && deno >= 20 && deno <= 49) {
    if (total >= 20) {

         ReturnValTotal = CallDenomination(total, 20); //RETURN DENO
         cout << "1st wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //10
    if (ReturnValTotal >= 10) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 10); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //5
    if (ReturnValTotal >= 5) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 5); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //1
    if (ReturnValTotal >= 1) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 1); //RETURN DENO
         cout << "Finale Return Value : "<< ReturnValTotal << endl;
         cout << endl;
    }
    }

// 10 ---------------------------------------------------------------------
    if (total >= 10 && deno >= 10 && deno <= 19) {
    if (total >= 10) {

         ReturnValTotal = CallDenomination(total, 10); //RETURN DENO
         cout << "1st wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //5
    if (ReturnValTotal >= 5) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 5); //RETURN DENO
         cout << "3nd wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //1
    if (ReturnValTotal >= 1) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 1); //RETURN DENO
         cout << "Finale Return Value : "<< ReturnValTotal << endl;
         cout << endl;
    }
    }

// 5 ---------------------------------------------------------------------
    if (total >= 5 && deno >= 5 && deno <= 9) {
    if (total >= 5) {

         ReturnValTotal = CallDenomination(total, 5); //RETURN DENO
         cout << "1st wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
    //1

    if (ReturnValTotal >= 1) {
         ReturnValTotal = CallDenomination(ReturnValTotal, 1); //RETURN DENO
         cout << "Finale Return Value : "<< ReturnValTotal << endl;
         cout << endl;
    }
    }

// 1 ---------------------------------------------------------------------
    if (total >= 1 && deno >= 1 && deno <= 4) {
    if (total >= 1) {

         ReturnValTotal = CallDenomination(total, 1); //RETURN DENO
         cout << "1st wave return deno : "<< ReturnValTotal << endl;
         cout << endl;
    }
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

            //cout << "Remainder: ";  // makes it look like the remainder is the return func.

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
