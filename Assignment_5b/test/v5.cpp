/*******************************************************************************
NAME: Vin Gabriel Fillon 10/28/2021 CompSci-165
TITLE: Lab Assignment 5b
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Program is a menu driven program for expenses.
    Takes inputs in array structs and searches for specific expenses.
    Inputs are not case sensitive.
    ~Using C strings~
    ~Dynamic Array~
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
	char desc[120]; //120 characters
	double cost;
};

void function1(Calculate *structArray, int arrayCounter);

int function2(Calculate *structArray, int &maxArraySize, int arrayCounter);

void function3(Calculate *structArray, int arrayCounter);

void function4(Calculate *structArray, int arrayCounter);

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
    //structArray is dynamic allowing us to create and change version of structArray
    //Program uses array of structs. -Multiple Structs in an array.
    Calculate* structArray = new Calculate[2];

	int maxArraySize = 2;
	double arrayCounter = 0;
	int menuValue = 0;

    string buf; //string buf method
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

        getline(cin, buf);

        if(buf.empty()) //if buf is empty
            {
            cout << "input cannot be empty." << endl;
            }

        if(!buf.empty())  //If it is not empty
        {
             menuValue = atoi(buf.c_str()); //CONVERTS BUF INTO INTEGER.
             //ATOI A STRING TO INTEGER

            //input 1
            if (menuValue == 1)
                {
                function1(structArray, arrayCounter);
                }

            //input 2
             if (menuValue == 2)
                {
                //array counter will be changed inside function.
                //returns integer
                arrayCounter = function2(structArray, maxArraySize, arrayCounter);
                }

            //input 3
            if (menuValue == 3)
                {
                function3(structArray, arrayCounter);
                }

            //input 4
             if (menuValue == 4)
                {
                function4(structArray, arrayCounter);
                }

            //input 5
             if (menuValue == 5)
                {
                break;
                }

            //Input invalid
            if (menuValue <= 0 || menuValue >=6 )
                {
                cout << "try again!" << endl;
                }

        }// end of !Null

    } //end of while loop

} //end of int main

/*******************************************************************************
* Function : function1
* Parameters : struct Calculate *structArray, int arrayCounter
* Return : void
* Description :
*       1. show all
*       print out data in array struct.
*       uses counter print expenses.
********************************************************************************/
void function1(Calculate* structArray, int arrayCounter)
{
    cout << endl;
    if(arrayCounter > 0)
    {
       cout << "Expenses: " << endl;
        for (int i = 0; i < arrayCounter; i++ )
        {
            cout << "AMOUNT(" << setprecision(2) << fixed << structArray[i].cost << ") " ;
            cout << "DESC (" << structArray[i].desc << ")" << endl;
        }
    }

    if(arrayCounter == 0)
    {
        cout << "There is no expense entry available." << endl;
    }

}

/*******************************************************************************
* Function : function2
* Parameters : struct Calculate *structArray, int arraySize, int arrayCounter
* Return : int
* Description :
*       2. spend4
*       ask for user input and returns user inputs
********************************************************************************/
int function2(Calculate* structArray, int &maxArraySize, int arrayCounter)
{
    cout << endl;

    char tempDesc[120];
    double tempCost;

    string buf;

    while (true)
    {
        cout << "Please enter the description for the expense: ";
        getline (cin, buf);

        //if it is NOT empty set values
        if (!buf.empty())
            {
            //this will lead to the conversion of buf
            break;
            }

        cout << "Description cannot be empty. " << endl;

    } //End of while loop

    // ---------- turns buf into c string ----------
    char *cStringConversion;

    //tells the cStringConversion its new length.
    cStringConversion = new char[buf.length()];

    for (int i = 0; i < buf.length(); i++)
        {
            cStringConversion[i] = buf[i];
        }

    cStringConversion[buf.length()] = '\0' ; //add the null terminator at the end of the char array

    strcpy(structArray[arrayCounter].desc, cStringConversion); //copies new data.

    //Cost input --------------------
    string buf1;
    while (true)
    {
        double temp;
        cout << "Please enter the amount: ";

        getline (cin, buf1);

         if (!buf1.empty())
            {
                temp = atof(buf1.c_str());

                 if (temp <= 0 )
                 {
                    cout << "Invalid amount. Amount cannot be negative or string. Please try it again." <<  endl;
                 }

                 if (temp > 0 )
                 {
                    structArray[arrayCounter].cost = temp;
                    break;
                 }
            }

        if (buf1.empty())
            {
            cout << "Amount cannot be empty." << endl;
            }

    } //End of while loop

    cout << "AMOUNT(" << setprecision(2) << fixed << structArray[arrayCounter].cost << ") " ;
    cout << "DESC (" << structArray[arrayCounter].desc << ")" << endl;

    //moves array counter for new array.
    arrayCounter = arrayCounter +1;

    //Array of Structs Expansion -------------------------------------------------
    if(arrayCounter == maxArraySize)
        {

        //max Array Struct Size is doubled;
        maxArraySize = maxArraySize * 2;

        //newArraysize is TEMPORARY storage
        //this is a new struct with a new array size;
        Calculate* newArraySize = new Calculate[maxArraySize];

        for(int i=0; i < arrayCounter+1; i++)
            {
            //newArraySize is temporary and will store values;
            newArraySize[i] = structArray[i];

            //structArray is here
            structArray = newArraySize; //new array size moves values;
            }

        //deletes whole array of structs
        delete [] newArraySize; //releases data to open up space.

        }// END OF STRUCT ARRAY EXPANSION

    return arrayCounter ;

}

/*******************************************************************************
* Function : function3
* Parameters :  struct Calculate *structArray, int arrayCounter
* Return : void
* Description :
*       3. search expenses containing this string
*       Lower cases all inputs and arrays
*       searches for specific input using null strstr method.
********************************************************************************/
void function3(Calculate* structArray, int arrayCounter)
{
    cout << endl;

    string buf;
    string input;

    while (true)
    {

        cout << "Please enter the search string: ";
        getline (cin, buf);

        //if it is NOT empty set values
        if (!buf.empty())
            {
            input = buf;  //sets description.
            break;
            }

        cout << "Search cannot be empty." << endl;

    } //End of while loop

    //---------- Lower case the input so it wont be case sensitive ----------
    int n = input.length();

    //int n = input.length();  //input length
    for (int i = 0; i < n; i++)
        {
        input[i] = tolower(input[i]);
        }

    //---------- Converts string input to c char. ----------
    char *cInput;

    //points here    //new char [name length]
        cInput = new char[input.length()];

    // cout << "input.length : " << input.length() << endl; //HOW to use string.length

    for (int index = 0; index < input.length(); index++)
        {
        cInput[index] = input[index];
        }

    cInput[input.length()] = '\0';//add the null terminator at the end of array


    //search function ----------------------------------------------------
    char tempDesc[120];//temp desk for lower casing
    int cVal = 0; //counter for printing no search matching

    for (int n = 0; n < arrayCounter; n++ )
    {
        strcpy(tempDesc ,structArray[n].desc);

        //---- lower cases description ----
        int x = strlen(tempDesc);

        for (int i = 0; i < x; i++)
            {
            //i = characters in string
            tempDesc[i] = tolower(tempDesc[i]);
            }

        //--------- Search specific characters in the array -similar to npos ---------

        //*output is a pointer telling it to do something
        char *output;

        //strstr will return 0 if the string a, contains, string b
        output = strstr(tempDesc, cInput);

        //if output is not -1, then do this.
        // output = 0 FOUD
        // output = -1 NOT OFUND
        if(output != NULL && n < arrayCounter)
            {
            cout << "AMOUNT(" << setprecision(2) << fixed << structArray[n].cost << ") " ;
            cout << "DESC (" << structArray[n].desc << ")" << endl;
            cVal = cVal + 1; //counts how many searches match
            }

    }//End of for loop

    if (cVal <= 0)
        {
        cout << "No strings found.";
        cout << endl;
        }

}//End of function

/*******************************************************************************
* Function : function4
* Parameters :  struct Calculate *structArray, int arrayCounter
* Return : void
* Description :
*       4. search expenses with greater than or equal to this amount
*       uses for loop to search through struct array.
********************************************************************************/
void function4(Calculate *structArray, int arrayCounter)
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

    //Search Function ---------------------------
    int cVal = 0; //counter for printing no search matching ##
    for (int i = 0; i < arrayCounter; i++)
    {

        if (structArray[i].cost >= input)
            {
            cout << "AMOUNT(" << setprecision(2) << fixed << structArray[i].cost << ") " ;
            cout << "DESC (" << structArray[i].desc << ")" << endl;
            cVal = cVal +1; //counts how many searches match
            }

    }// End of for loop

    if (cVal <= 0)
        {
        cout << "No values found.";
        cout << endl;
        }

    cin.ignore(1000, 10); //problems with next line -keep this.

}// end of Function 4


