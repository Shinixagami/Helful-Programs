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

#include <algorithm>
using std::swap;

#include <cctype> // for toupper and tolower
string toLowerCase(string); // these don't actually change the case of the parameter...
string toUpperCase(string); //...they return a changed version of the parameter.

struct Calculate
{
    double cost;
    string desc;

    double arrayCost[100]; //array struct
    string arrayDesc[100] ; //array struct

    int counter;  // count
    int inputVal; //menu value
};

void function1(struct Calculate s);

Calculate function2(struct Calculate s); //struct to return a struct.

void function3(struct Calculate s);

void function4(struct Calculate s);



int main ()
{
    Calculate s;
    s.inputVal = 0;



    s.counter = 4;  //ARRAY COUNT
    //array initialization
    for (int i = 0; i < s.counter; i++ )
    {

        double randNum = 0;

        randNum = randNum + i;

        s.arrayCost[i] = 20 + randNum;

        s.arrayDesc[i] = " TEST VALUE FOR NUM -WORKS ";
    }


    s.arrayCost[4] = 99.99;

    s.arrayDesc[4] = "DEX";

    s.counter = 5; //DELETE AFTER


    //end of TEST VAR ----------------------------------------------------------



    //temp storage
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
            //cout << "~s counter: " << s.counter << endl; //test

            s.arrayCost[s.counter] = strg.cost;
            s.arrayDesc[s.counter] = strg.desc;

            //ArrayCheck.arrayDesc[counter] =  mStorage
            //cout << "~~~~~~~~~~~~~~~~~~~ (INIT) " << endl;
           // cout << "ARRAY [ " <<  s.counter << " ] " << endl;
            cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[s.counter] << ") " ;
            cout << "DESC (" << s.arrayDesc[s.counter] << ")" << endl;
            //cout << "~~~~~~~~~~~~~~~~~~~ " << endl;

            s.counter = s.counter +1;
        }

         if (s.inputVal == 3)
        {

            function3(s);

        }



         if (s.inputVal == 4)
        {
            function4(s);
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

        //cout << "~~~~~~~~~~~~~~~~~~~ " << endl;
        //cout << "ARRAY [ " <<  i << " ] " << endl;

        cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[i] << ") " ;
        cout << "DESC (" << s.arrayDesc[i] << ")" << endl;
        //cout << "~~~~~~~~~~~~~~~~~~~ " << endl;

        //cout << "COUNTER VAL: " <<  s.counter << endl;
        //cout << "LOOP COUNT " <<  i << endl;
        //cout << "-------------" << endl << endl;

    }


}


Calculate function2(struct Calculate s)
{

    Calculate input;
    //input.cost
    //input.desc

    input.counter = 0;

    //cout << "s.counter: " << s.counter << endl;

    //the only time when this is useful is if the data has to be returned and stored back
    swap (s.counter, input.counter);

    //cout << "input.counter: " << input.counter << endl;

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
        //cout << "CHEC VAL STRG: " << fixed <<  setprecision(2) << temp << endl;


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


    //Return input.cost
    //Return input.desc
    //Return input.counter

    return input;

}

//3. search expenses containing this string
void function3(struct Calculate s)
{
    cout << endl;
    cout << "~Function 3 Executed~" << endl;

    string input;

    cout << "Please enter the search string: " ;



    cin.ignore(1000, 10); //problems with next line from function -keep this.

    getline (cin, input);




    //cin >> input;

    cout << endl;

    //cout << "s.counter : "<< s.counter << " (this is the empty array so -1)" <<endl; //test

    //cout << "input : "<<  input << endl << endl; //test


    //lower case the input so it wont be case sensitive;
    int n = input.length();
    //int n = input.length();  //input length
    for (int i = 0; i < n; i++)
        {
        input[i] = tolower(input[i]);
        }

    //cout << "input to lower case: "<< input << endl << endl; //test

    //an array for temporary storing description.
    Calculate store;

    //SORT FUNCTION HERE ----------------
    for (int n = 0; n < s.counter; n++ )
    {

        store.arrayDesc[n] = s.arrayDesc[n]; // values

        cout << endl;
        //cout << "--- Searching Array [ " <<  n << " ] --- "<< endl;


        //LOWER CASE FUNC
        int x = s.arrayDesc[n].length();

        //cout << "x val: " << x << endl ;
            //int n = input.length();  //input length
        for (int i = 0; i < x; i++)
            {
            //i = characters in string
            //n = array accessed number
            s.arrayDesc[n][i] = tolower(s.arrayDesc[n][i]);
            }



        int index;

        // cout << "DESC (" << s.arrayDesc[n] << ")" << endl;

        index = s.arrayDesc[n].find(input);

        //cout << "index find : " << index << endl;


        // Test for match
        // string::npos = -1   is NOT FOUND
        //  string::npos = 0 is FOUND
        if (index != string::npos){
          cout << "* (" << input << ") found * " << endl;

          cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[n] << ") " ;
          cout << "DESC (" << store.arrayDesc[n] << ")" << endl;
        }


        else
        {
            cout << input  << " not found" << endl;
        }

    }// end of for loop


    cout << endl;
    cout << "END 3"<< endl;
}


//4. search expenses with greater than or equal to this amount
void function4(struct Calculate s)
{
    cout << endl;
    cout << "~Function 4 Executed~" << endl;



    double input;

    while (true)
    {
        string buf1;
        double temp;
        cout << "Please enter the amount: ";

        cin >> buf1;
        temp = atof(buf1.c_str());

        cout << "CHEC VAL STRG: " << fixed <<  setprecision(2) << temp << endl;

         if (temp <= 0 )
         {
            cout << "Invalid amount. Amount cannot be negative or string. Please try it again." <<  endl;
         }

         if (temp > 0 )
         {
            cout << endl;
            input = temp;
            break;
         }

    } //END OF WHILE LOOP

    //cout << "input val: " << input << endl;
    //cout << "s.counter : "<< s.counter << " -this is the empty array so -1" <<endl; //test



    //SORT FUNCTION HERE ----------------

    for (int i = 0; i < s.counter; i++)
    {

        cout << endl;
        cout << "--- Searching Array [ " <<  i<< " ] --- "<< endl;


        if (s.arrayCost[i] >= input)
        {
            //cout << "* Found Arrays with >= " << input << " *" << endl;
            cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[i] << ") " ;
            cout << "DESC (" << s.arrayDesc[i] << ")" << endl;

        }

        /*else
        {
            cout << "Not Found"<< endl;
        }
        */

    }// end of for loop


    //cout << "END 4"<< endl;

}







