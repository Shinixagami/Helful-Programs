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




void function1(struct Calculate s);


Calculate functionA();





//ARRAY REFERENCE SYNTAX  -   data_type (&name)[size] = array;

void function2(struct Calculate *s, int &counter);  //done



//3. search expenses containing this string

void function3(double arrayCost[], string arrayDesc[]);

void function4(double arrayCost[], string arrayDesc[]);

void function6(double arrayCost[], string arrayDesc[]);



int main ()

{



    Calculate s;
    s.inputVal = 0;


    //ArrayCheck.arrayCost[i]

    //ArrayCheck.arrayDesc[i]


    //array initialization
    for (int i = 0; i < 5; i++ )
    {

        double randNum = 0;

        randNum = randNum + i;

        s.arrayCost[i] = 20 + randNum;

        s.arrayDesc[i] = " TEST VALUE FOR NUM -WORKS ";


    }



   s.counter = 5;  //ARRAY COUNT


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

       Calculate mStorage;



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



                     function2(s);



           // mStorage = functionA();

            //  ArrayCheck.counter return.

            //  ArrayCheck.desc return.

            //  ArrayCheck.cost return.

            //struct STRG = Function2()




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





            //NEEDS TO BE REFERENCED RETURNED int* lets to pass the value back;
void function2(struct Calculate ArrayCheck, int &counter)
{

    Calculate input;


    input.cost;

    input.desc;


    cin.ignore(1000, 10); //problems with next line from function -keep this.

    string buf;
    cout << "Please enter the description for the expense: ";     //1  name
    getline (cin, buf);



     input.desc = buf;

    // cout << "Array data staored: " << desc << endl; -TAEST VAL
    cout << "Array data stored: " << input.desc << endl;


    ArrayCheck.arrayDesc[counter] = input.desc;


    string buf1;
    while (true)
    {


        cout << "Please enter the amount: ";

        cin >> buf1;
        input.cost = atof(buf1.c_str());


        ArrayCheck.arrayCost[counter] = input.cost;


        //cout << "storage: " << strg << endl;
        cout << "CHEC VAL STRG: " << fixed <<  setprecision(2) << input.cost << endl;


         if (input.cost <= 0 )
         {
            cout << "Invalid amount. Amount cannot be negative or string. Please try it again." <<  endl;
         }


         if (input.cost > 0 )
         {
            cout << endl;
            //ArrayCheck.cost[counter] = strg;



            cout << "DESC (" << ArrayCheck.arrayCost[counter] << ")" << endl;


            counter = counter+1;
            break;

         }


    } //END OF WHILE LOOP





    cout <<   endl ;
    cout << "COUNTER IS NOW: " << counter <<  endl;


    cout << "Data Initialized in Array [ " << counter-1 << " ] " <<  endl;

    cout << "----------------------------------------" <<  endl;
    cout << "Cost: " << ArrayCheck.arrayCost[counter-1] << " " << endl ;
    cout << "Desc: " << ArrayCheck.arrayDesc[counter-1] << endl;
    cout << "----------------------------------------" <<  endl;




    //return ArrayCheck;


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







