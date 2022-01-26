/*******************************************************************************
NAME: Vin Gabriel Fillon 10/21/2021 CompSci-165
TITLE: Lab Assignment 5a
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Program is a menu driven program for expenses.
    Takes inputs in array structs and searches for specific expenses.
    Inputs are not case sensitive.
    Using C strings
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

#include <string.h>

#include <string>
using std::getline; //get line for input
using std::string;

#include <algorithm>
using std::swap; //swap

#include <cctype> // for toupper and tolower
using std::tolower;
using std::toupper;

struct Calculate
{
    double cost;


    char desc[100];


    double arrayCost[100] ; //array struct



    char arrayDesc[100][30];



    int counter;  // count for array.
    int inputVal; //menu value
};

void function1(struct Calculate s);

Calculate function2(struct Calculate s); //struct to return a struct.

void function3(struct Calculate s);

void function4(struct Calculate s);

/*******************************************************************************
* Function : Main function
* Parameters : N/A
* Return : 0
* Description :
*       Uses while loop for menu
*       Uses array struct and functions for input and search.
********************************************************************************/
int main ()
{
    Calculate s;
    s.inputVal = 0;
    s.counter = 5 ;

    //s.arrayDesc[100];

    //temp storage
    Calculate strg;




    //TEST VALUES ------------------------------------------

    for (int i = 0; i < 5; i++)
    {
        //s.arrayDesc[i] = "awdawdawd";



        //char input[40] = "awdawd";


        strcpy(s.arrayDesc[i], "Hi there NIGGA"); //COPIES NEW DATA INSIDE.

        s.arrayCost[i] = 20.30;

        printf("--- array [ %d ] --- \n", i);

        printf("Desc: %s \n", s.arrayDesc[i]);

        cout << "Cost: " << s.arrayCost[i] << endl;



    }








   //TEST VALUES ------------------------------------------






    while (true)
    {
        cout << endl;

        cout << "Expense Tracking Menu: " << endl;
        cout << "   1. show all " << endl;
        cout << "   2. spend " << endl;
        cout << "   3. search expenses containing this string " << endl;
        cout << "   4. search expenses with greater than or equal to this amount" << endl;
        cout << "   5. exit" << endl;
        cout << "Enter your option: ";

        string buf; //string buf method
        cin >> buf; s.inputVal = atoi(buf.c_str());

        //input 1
        if (s.inputVal == 1)
        {
            function1(s);
        }

        //input 2
         if (s.inputVal == 2)
        {
            strg = function2(s);

            //mStorage has these values.
            //Return strg.cost
            //Return strg.desc
            //Return strg.counter   -it has the number of the empty array.

            //the only time when this is useful is if the data has to be returned and stored back
            swap (s.counter, strg.counter);

            s.arrayCost[s.counter] = strg.cost;


            //C string = c++ string.  ---------------------------------------------


             printf("STRING struct ONE: %s \n \n" , strg.desc);


            //COPIES NEW DATA
            strcpy(s.arrayDesc[s.counter], strg.desc ); //COPIES NEW DATA INSIDE.








            cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[s.counter] << ") " ;


            cout << "DESC (" << s.arrayDesc[s.counter] << ")" << endl;

            s.counter = s.counter +1;
        }

        //input 3
         if (s.inputVal == 3)
        {
            function3(s);
        }

        //input 4
         if (s.inputVal == 4)
        {
            function4(s);
        }

        //input 5
         if (s.inputVal == 5)
        {
            break;
        }

        //Input invalid
        if (s.inputVal <= 0 || s.inputVal >=6 )
        {
            cout << "try again!" << endl;
        }

    } //end of while loop

} //end of int main

/*******************************************************************************
* Function : function1
* Parameters : struct Calculate s (IN)
* Return : void
* Description :
*       1. show all
*       print out data in array struct.
*       uses counter print expenses.
********************************************************************************/
void function1(struct Calculate s)
{
    cout << endl;
    if(s.counter > 0)
    {
       cout << "Expenses: " << endl;
        for (int i = 0; i < s.counter; i++ )
        {
            cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[i] << ") " ;
            cout << "DESC (" << s.arrayDesc[i] << ")" << endl;
        }
    }

    if(s.counter == 0)
    {
        cout << "There is no expense entry available." << endl;
    }

}

/*******************************************************************************
* Function : function2
* Parameters : struct Calculate s (IN)
* Return : returns struct -is a struct function.
* Description :
*       2. spend
*       ask for user input and returns user inputs
********************************************************************************/
Calculate function2(struct Calculate s)
{
    cout << endl;

    Calculate input;
    //input.cost
    //input.desc

    input.counter = 0; //will be returned -just init

    // this is useful is if the data has to be returned and stored back -no more temp var.
    swap (s.counter, input.counter);


    string buf;
    cin.ignore(1000, 10); //problems with next line from function -keep this.
    while (true)
    {

        //cin.ignore(1000, 10); //problems with next line from function -keep this.

        cout << "Please enter the description for the expense: ";
        getline (cin, buf);



        //if it is NOT empty set values
        if (!buf.empty()){
            //this will lead to the conversion of buf
            break;
        }

        cout << "Description cannot be empty. " << endl;

    } //End of while loop



    //turns buf into c string.
    char *cStringConversion;


    //tells the cStringConversion its new length.
    cStringConversion = new char[buf.length()];

    cout << "name.length : " << buf.length() << endl; //HOW to use string.length


    for (int i = 0; i < buf.length(); i++)
    {
        cStringConversion[i] = buf[i];
    }

    cStringConversion[buf.length()] = '\0';//add the null terminator at the end of
                                  // the char array






     printf("Cstring : %s \n \n" , cStringConversion);


     int x = strlen(cStringConversion);

     cout << "c string length : " << x << endl;



     strcpy(input.desc, cStringConversion); //COPIES NEW DATA INSIDE.






    cout << "cout desc: " << input.desc << endl;








    string buf1;
    while (true)
    {
        double temp;
        cout << "Please enter the amount: ";

        cin >> buf1;
        temp = atof(buf1.c_str());

         if (temp <= 0 )
         {
            cout << "Invalid amount. Amount cannot be negative or string. Please try it again." <<  endl;
         }

         if (temp > 0 )
         {
            input.cost = temp;
            break;
         }

    } //End of while loop





    return input;
    //Return input.cost
    //Return input.desc
    //Return input.counter
}

/*******************************************************************************
* Function : function3
* Parameters : struct Calculate s (IN)
* Return : void
* Description :
*       3. search expenses containing this string
*       Lower cases all inputs and arrays
*       searches for specific input using npos method
********************************************************************************/
void function3(struct Calculate s)
{
    cout << endl;

    string input;
    cout << "Please enter the search string: " ;
    cin.ignore(1000, 10); //problems with next line -keep this.

    getline (cin, input);

    cout << endl;

    //lower case the input so it wont be case sensitive;
    int n = input.length();
    //int n = input.length();  //input length
    for (int i = 0; i < n; i++)
        {
        input[i] = tolower(input[i]);
        }

    //an array for temporary storing description -it will be printed as lower case otherwise.
    Calculate store;

    //search function
    for (int n = 0; n < s.counter; n++ )
    {





        strcpy(store.arrayDesc[n], s.arrayDesc[n]); //COPIES NEW DATA INSIDE.


        cout << "DESC in storage: " << store.arrayDesc[n] << endl;



//lower cases description
        int x = strlen(s.arrayDesc[n]);
        cout << "string length : " << x << endl;


        for (int i = 0; i < x; i++)
            {
            //i = characters in string
            //n = array accessed number
            s.arrayDesc[n][i] = tolower(s.arrayDesc[n][i]);
            }



//converts string input to c char. -----------------------------

        char *cInput;


        //points here    //new char [name length]
            cInput = new char[input.length()];

                    cout << "input.length : " << input.length() << endl; //HOW to use string.length

            for (int index = 0; index < input.length(); index++)
                {
                cInput[index] = input[index];
                }

            cInput[input.length()] = '\0';//add the null terminator at the end of
                                          // the char array



            printf("c string : %s \n \n" , cInput);

            printf("ARRAY DESC : %s \n \n" , s.arrayDesc[n]);









//find function except C


            // null is similar to npos.
            //*output is a pointer telling it something
            char *output;




            //strstr will return 0 if the string a, contains, string b
            output = strstr(s.arrayDesc[n] , cInput);



            if(output != NULL)
                {

                cout << "string found in Array [ " << n <<  " ] " << endl;


                cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[n] << ") " ;
                cout << "DESC (" << store.arrayDesc[n] << ")" << endl;


                }

            else
                {
                printf("- string not found \n \n ");
                }
















    }//End of for loop

}//End of function

/*******************************************************************************
* Function : function4
* Parameters : struct Calculate s (IN)
* Return : void
* Description :
*       4. search expenses with greater than or equal to this amount
*       uses for loop to search through struct array.
********************************************************************************/
void function4(struct Calculate s)
{
    cout << endl;
    double input;

    while (true)
    {
        string buf1;
        double temp; //using temp to weed out invalid amounts

        cout << "Please enter the amount: ";
        cin >> buf1;
        temp = atof(buf1.c_str());

         if (temp <= 0 )
         {
            cout << "Invalid amount. Amount cannot be negative or string. Please try it again." <<  endl;
         }

         if (temp > 0 )
         {
            input = temp;
            break;
         }

    } //End of while loop

    //Search Function
    for (int i = 0; i < s.counter; i++)
    {

        if (s.arrayCost[i] >= input)
        {
            cout << "AMOUNT(" << setprecision(2) << fixed << s.arrayCost[i] << ") " ;
            cout << "DESC (" << s.arrayDesc[i] << ")" << endl;
        }

    }// End of for loop

}// end of Function 4







