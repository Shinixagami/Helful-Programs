/*******************************************************************************
NAME: Vin Gabriel Fillon 10/15/2021 CompSci-165
TITLE: Lab Assignment 3
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:


********************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;  //input output stream -also where print functions are.

#include <iomanip>   //for setprecision
using std::fixed;
using std::setprecision;

#include <sstream>   //to allow format control when converting numbers to strings
using std::stringstream;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string>
using std::getline; //get line for input
using std::string;

#include <cstdlib> // for atoi and atof

#include <sstream> //important use check STRING STRING HERE !!


#include <algorithm>
using std::swap;


//POINTERS METHOD CUS IDK HOW to.


struct Calculate
{
    double cost;
    string desc;

    double arrayCost[100]; //array struct
    string arrayDesc[100] ; //array struct

    int arrayCounter; // this can also be menu value;
    int arraySearched; //return for sorted pick




    int counter;  // count

    //do no delete
    int inputVal;


};



void function1(struct Calculate s);  // DONE


Calculate function2(struct Calculate s); //FUNCTION 2




//3. search expenses containing this string
void function3(double arrayCost[], string arrayDesc[]);
//4. search price


void function4(double arrayCost[], string arrayDesc[]);

void function6(double arrayCost[], string arrayDesc[]);



int main ()

{



    Calculate s;
    s.inputVal = 0;

    //ArrayCheck.arrayCost[i]
    //ArrayCheck.arrayDesc[i]




    s.counter = 5;  //ARRAY COUNT
    //array initialization
    for (int i = 0; i < s.counter; i++ )
    {

        double randNum = 0;

        randNum = randNum + i;

        s.arrayCost[i] = 20 + randNum;

        s.arrayDesc[i] = " TEST VALUE FOR NUM -WORKS ";
    }




   Calculate strg;


    while (true )
    {
        cout << endl;

        cout << "MAIN~ COUNTER IS NOW: " << s.counter <<  endl ;
        cout << "EMPTY ARRAY [ " << s.counter << " ]" <<  endl << endl;

        cout << "Expense Tracking Menu: " << endl;
        cout << "   1. show all " << endl;
        cout << "   2. spend " << endl;
        cout << "   3. search expenses containing this string " << endl;
        cout << "   4. search expenses with greater than or equal to this amount" << endl;
        cout << "   5. exit" << endl;
        cout << "Enter your option: ";

        string buf; //string buf method
        cin >> buf; s.inputVal = atoi(buf.c_str());

        //cout << "inputted : " << buf << endl;



       //use this store values;




        if (s.inputVal == 1)
        {
            cout << endl;
            cout << "~Function 1 Executed~" << endl;

            //cost and desc, and array counter

            //STRUCT AND & MAKE PASS BY REFERENCE.

            function1(s);




        }


         if (s.inputVal == 2)
        {
            cout << endl;
            cout << "~Function 2 Executed~" << endl;

            strg = function2(s);

            //mStorage has these values.
            //Return strg.cost
            //Return strg.desc
            //Return strg.counter   -it has the number of the empty array.

            //the only time when this is useful is if the data has to be returned and stored back
            swap (s.counter, strg.counter);
            cout << "~s counter: " << s.counter << endl; //test

            strg.arrayCost[s.counter] = strg.cost;
            strg.arrayDesc[s.counter] = strg.desc;

            //ArrayCheck.arrayDesc[counter] =  mStorage
            cout << "~~~~~~~~~~~~~~~~~~~ (INIT) " << endl;
            cout << "ARRAY [ " <<  s.counter << " ] " << endl;
            cout << "AMOUNT(" << setprecision(2) << fixed << strg.arrayCost[s.counter] << ") " ;
            cout << "DESC (" << strg.arrayDesc[s.counter] << ")" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~ " << endl;

            s.counter = s.counter +1;

        }





         if (s.inputVal == 3)
        {
            cout << endl;
            cout << "~Function 3 Executed~" << endl;
            cout << "   3. search expenses containing this string " << endl;
        }



         if (s.inputVal == 4)
        {
            cout << endl;
            cout << "~Function 3 Executed~" << endl;
            cout << "   4. search expenses with greater than or equal to this amount" << endl;
        }




         if (s.inputVal == 5)
        {
            cout << "   5. exit" << endl;
            break;
        }


        if (s.inputVal <= 0 || s.inputVal >=6 )
        {
            cout  << endl;
            cout << "try again!" << endl;
        }




    } //end of while loop




} //end of int main

void function1(struct Calculate s)
{

    cout << "Check : " << s.counter << endl;

    for (int i = 0; i < s.counter; i++ )
    {

        cout << "~~~~~~~~~~~~~~~~~~~ " << endl;
        cout << "ARRAY [ " <<  i << " ] " << endl;

        cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[i] << ") " ;


        cout << "DESC (" << s.arrayDesc[i] << ")" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~ " << endl;

        cout << "COUNTER VAL: " <<  s.counter << endl;
        cout << "LOOP COUNT " <<  i << endl;
        cout << "-------------" << endl << endl;

    }


}


Calculate function2(struct Calculate s)
{

    Calculate input;
    //input.cost
    //input.desc

    input.counter = 0;

    cout << "s.counter: " << s.counter << endl;

    //the only time when this is useful is if the data has to be returned and stored back
    swap (s.counter, input.counter);

    cout << "input.counter: " << input.counter << endl;

    cin.ignore(1000, 10); //problems with next line from function -keep this.

    string buf;
    cout << "Please enter the description for the expense: ";     //1  name
    getline (cin, buf);

    input.desc = buf;

    string buf1;
    while (true)
    {
        double temp;
        cout << "Please enter the amount: ";

        cin >> buf1;
        temp = atof(buf1.c_str());

        //cout << "storage: " << strg << endl;
        cout << "CHEC VAL STRG: " << fixed <<  setprecision(2) << temp << endl;


         if (temp <= 0 )
         {
            cout << "Invalid amount. Amount cannot be negative or string. Please try it again." <<  endl;
         }


         if (temp > 0 )
         {
            cout << endl;

            input.cost = temp;

            break;

         }

    } //END OF WHILE LOOP


    cout << "input gained: " << endl;
    cout << "----------------------------------------" <<  endl;
    cout << "Cost: " << input.cost << " " << endl ;
    cout << "Desc: " << input.desc << endl;
    cout << "----------------------------------------" <<  endl;
    cout << "COUNTER VAL: " <<  input.counter << endl;

    //Return input.cost
    //Return input.desc
    //Return input.counter

    return input;

}



void function3(double arrayCost[], string arrayDesc[], int counter)
{
    //cout << "" << endl;
    cout << "~FUNMCTION THREE EXECUTED" << endl;
    cout << "   3. search expenses containing this string " << endl << endl;





}


void function4(double arrayCost[], string arrayDesc[], int counter)
{
    //cout << "" << endl;
    cout << "~FUNMCTION THREE EXECUTED" << endl;
    cout << "   4. search expenses with greater than or equal to this amount" << endl;





}







