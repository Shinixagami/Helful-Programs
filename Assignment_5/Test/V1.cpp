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


//POINTERS METHOD CUS IDK HOW to.


struct Calculate
{
    double cost;
    string desc;


    double arrayCost[100]; //array struct
    string arrayDesc[100] ; //array struct

    int arrayCounter; // this can also be menu value;
    int arraySearched; //return for sorted pick


    int counter;


    //do no delete
    int inputVal;
};




//void showAll (double arrayCost[]);

void function1(double arrayCost[], string arrayDesc[], int counter);  //done




//ARRAY REFERENCE SYNTAX  -   data_type (&name)[size] = array;

void function2(double arrayCost[], string arrayDesc[], int &counter);  //done



//3. search expenses containing this string

void function3(double arrayCost[], string arrayDesc[]);

void function4(double arrayCost[], string arrayDesc[]);

void function6(double arrayCost[], string arrayDesc[]);



int main ()

{






    Calculate input;


    input.inputVal = 0;

    int CAPACITY = 100; //mac cap
    double arrayCost[CAPACITY] = {}; //cost for expenses
    string arrayDesc[CAPACITY] = {};



    for (int i = 0; i < 5; i++ )
    {

        double randNum = 0;

        randNum = randNum + i;



        arrayCost[i] = 20 + randNum;
        arrayDesc[i] = " TEST VALUE FOR NUM -WORKS ";

    }


   //int couter = 0;
   int counter = 5;        //- for test purposes 5 arrays init.



    while (true )
    {
        cout << endl;

        cout << "MAIN~ COUNTER IS NOW: " << counter <<  endl ;
        cout << "EMPTY ARRAY [ " << counter << " ]" <<  endl << endl;

        cout << "Expense Tracking Menu: " << endl;
        cout << "   1. show all " << endl;
        cout << "   2. spend " << endl;
        cout << "   3. search expenses containing this string " << endl;
        cout << "   4. search expenses with greater than or equal to this amount" << endl;
        cout << "   5. exit" << endl;
        cout << "Enter your option: ";

        string buf; //string buf method
        cin >> buf; input.inputVal = atoi(buf.c_str());

        //cout << "inputted : " << buf << endl;

        //storage varaibles
        int storage1 = 0;



        if (input.inputVal == 1)
        {
            cout << endl;
            cout << "~Function 1 Executed~" << endl;

            //cost and desc, and array counter
            function1(arrayCost,arrayDesc, counter);


        }


         if (input.inputVal == 2)
        {
            cout << endl;
            cout << "~Function 2 Executed~" << endl;

            function2 (arrayCost, arrayDesc, counter);



        }


         if (input.inputVal == 3)
        {
            cout << endl;
            cout << "~Function 3 Executed~" << endl;
            cout << "   3. search expenses containing this string " << endl;
        }



         if (input.inputVal == 4)
        {
            cout << endl;
            cout << "~Function 3 Executed~" << endl;
            cout << "   4. search expenses with greater than or equal to this amount" << endl;
        }




         if (input.inputVal == 5)
        {
            cout << "   5. exit" << endl;
            break;
        }


        if (input.inputVal <= 0 || input.inputVal >=6 )
        {
            cout  << endl;
            cout << "try again!" << endl;
        }




    } //end of while loop




} //end of int main



void function1(double arrayCost[], string arrayDesc[], int counter)
{
    cout << "" << endl;

    stringstream printLayout_ss;


    if (counter == 0)
    {
        cout << "NO VALUES FOUND" << endl;
    }


    if (counter > 0)
    {
        //take out "+1" after because its showing an extra ARRAY.
        for (int n = 0; n < counter; n++)
        {

            cout << "~~~~~~~~~~~~~~~~~~~ " << endl;
            cout << "ARRAY [ " <<  n << " ] " << endl;

            cout << "AMOUNT(" << setprecision(2) << fixed << arrayCost[n] << ") " ;


            cout << "DESC (" << arrayDesc[n] << ")" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~ " << endl;

            cout << "COUNTER VAL: " <<  counter << endl;
            cout << "LOOP COUNT " <<  n << endl;
            cout << "-------------" << endl << endl;



           // printLayout_ss  << "AMOUNT(" << fixed << setprecision(2) << arrayCost[n] << ")  DESC(" << arrayDesc[n]<< ")" << endl;

            //cout << printLayout_ss.str() << endl;


        }


    cout << "~~~END 1" << endl;

    }


}

            //NEEDS TO BE REFERENCED RETURNED int* lets to pass the value back;
void function2(double arrayCost[], string arrayDesc[], int &counter)
{

    cin.ignore(1000, 10); //problems with next line from function -keep this.

    string buf;
    cout << "Please enter the description for the expense: ";     //1  name
    getline (cin, buf);

    arrayDesc[counter] = buf;

    // cout << "Array data staored: " << desc << endl; -TAEST VAL
    cout << "Array data stored: " << arrayDesc[counter] << endl;




    string buf1;
    while (true)
    {


        double strg;
        cout << "Please enter the amount: ";

        cin >> buf1;
        strg = atof(buf1.c_str());

        cout << "storage: " << strg << endl;
        cout << "CHEC VAL STRG: " << fixed <<  setprecision(2) << strg << endl;


         if (strg <= 0 )
         {
            cout << "Invalid amount. Amount cannot be negative or string. Please try it again." <<  endl;
         }


         if (strg > 0 )
         {
            cout << endl;
            arrayCost[counter] = strg;
            cout << "DATA IN ARRAY COST : " <<  arrayCost[counter]  << endl;

            counter = counter+1;
            break;

         }


    } //END OF WHILE LOOP



    cout <<   endl ;
    cout << "COUNTER IS NOW: " << counter <<  endl;


    cout << "Data Initialized in Array [ " << counter-1 << " ] " <<  endl;

    cout << "----------------------------------------" <<  endl;
    cout << "Cost: " << arrayCost[counter-1] << " " << endl ;
    cout << "Desc: " << arrayDesc[counter-1] << endl;
    cout << "----------------------------------------" <<  endl;






    //STRUCT

   /* Expenses N;

    N.arrayCounter = counter+1;

    cout <<"array counter +1:" << N.arrayCounter << endl;



    return N; */


}


/*
while (true)
    {

        string buf;
        cout << "Please enter the description for the expense: ";
        getline (cin, buf); //input.desc = buf;


        arrayDesc[N] = buf;

        cin.ignore(1000, 10);


        while (true )
        {

            cin.ignore(1000, 10);
            cout << "Please enter the amount: ";
            cin >> cost;

            if (cost < 0)
            {
                cout << "Invalid amount. Amount cannot be negative or string. Please try it again. " << endl;
            }

            if (cost >0)
            {

                arrayCost[N] = cost;
                //break;

            }

        }


       //break;


    }


*/


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







