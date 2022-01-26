/*******************************************************************************
NAME: Vin Gabriel Fillon 12/07/2021 CompSci-165
TITLE: Extra Credit Lab Assignment
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Extra credit program
    ~uses nodes to calculate the totals and prints our receipts through loops
********************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;  //input output stream -also where print functions are.

#include <sstream>
#include <iomanip>   //for setprecision
using std::fixed;
using std::setprecision;


#include <sstream>   //to allow format control when converting numbers to strings
using std::stringstream;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string.h> //for char or C String

#include <string>
using std::getline; //get line for input
using std::string; //c++ string

#include <algorithm>
using std::swap; //swap

#include <cctype> // for toupper and tolower
using std::tolower;
using std::toupper;

struct CreateMenuNode //format of the one node
{
    string itemName;
	int quantity;
	double price;
	double cost;
	CreateMenuNode* next;
};

void functionBuyItem(CreateMenuNode*& head);

void functionShowReceipts(CreateMenuNode*& head);

void functionShowSummary(CreateMenuNode*& head);

/*******************************************************************************
* Function : Main Function
* Parameters :  CreateMenuNode*& head
* Return : int
* Description :
*       Uses link list and dynamically modifies data
*       ~a movie is  stored in each node
*       ~the main nodes first chain is called "head"
********************************************************************************/
int main()
{

    int password;
    int password2 = 54321;

     //custom password file
	ifstream fin;
	fin.open ("password.txt");

    if(fin.good()) //if there is a file to be read
    {
        cout << "File Found ..." << endl;
        cout << "Custom access code set!" << endl;

        string bufS; //buf method for EOF

        while (true)
        {

            getline(fin, bufS);

            cout << "data taken: " << bufS << endl;

            int temp1 = atoi(bufS.c_str());

            password = temp1;

            password2 = temp1;

            break;

            fin.close();

        }

         cout << endl;

    }

     if(!fin.good()) //if there is a file to be read
    {
        cout << "Default access codes set!" << endl;
        password = 12345;
    }


    string bufp;
    while (true)
    {
        cout << "Please enter the access code: " ;

        getline(cin, bufp);

        int temp = atoi(bufp.c_str());

        //cout << temp << endl;

        //cout << password << endl;

        if(password == temp || password2 == temp)
            {
            cout << "Program Unlocked!" << endl;
            break;
            }

        cout << endl;
        cout << "Invalid access code! Try again! " << endl;
        cout << endl;

    }//end of while loop

	//CreateMenuNode - is the structure = will be used for the node
	//Head - is the start of the node = head like a snake
	CreateMenuNode* head;
	head = nullptr; //nullptr is set to cut the node

	string menuInput; //menu choices

	//head of options for user
	while (true)
	{

        cout << endl;
	    cout << "~~ Shopping Menu ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1. buy " << endl;
		cout << "2. show receipts " << endl;
		cout << "3. show summary " << endl;
		cout << "4. exit " << endl;
		cout << "Enter Input of your option: ";
        getline(cin, menuInput);

        int inputVal;
        inputVal = atoi(menuInput.c_str());

		//add movie -----------------------------------------
		if (inputVal == 1)
		{
			functionBuyItem(head);
		}

		//list movies -----------------------------------------
		if (inputVal == 2)
		{
			functionShowReceipts(head);
		}


		if (inputVal == 3)
		{
			functionShowSummary(head);
		}

		//end
		if (inputVal == 4)
		{
			break;
		}

	}// end of if loop

  // Deallocate all nodes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //while (true) -basically saying if it NOT NULLPTR / NULL
  while (head) // keep going as long as the list is not empty
  {
    //intialized placeHolder with same structure
    CreateMenuNode* placeHolder;

    placeHolder = head; // head now has the same address as place Holder

    //we basically add this to the front of the list - so the placeHolder gets inserted to the front of the node
    //head then gets pushed to to right and becomes the 2nd Node / next node
    head = head -> next; // because we're linking over it to its next

    //straight up deletes the first node deleting the whole node
    delete placeHolder; // now deallocate the old head

  }//end of while loop

}// end of main

/*******************************************************************************
* Function : functionBuyItem
* Parameters :  CreateMenuNode*& head (IN)
* Return : void
* Description :
*       adds elements in node (node start is called head)
*       ~newNode is the add on node that will be linked on
*       Adds a purchase (for buy)
********************************************************************************/
void functionBuyItem(CreateMenuNode*& head)
{
    cout << endl;

    string itemName;
	int quantity;
	double price;

    string buf1;
	while (true)
	{
		cout << "Please enter the description: ";

        getline (cin, buf1);

		if (!buf1.empty())
            {
            itemName = buf1;
            break;
            }

		cout << "Invalid Input. Please try again! " << endl;
	}

    //int input
    string buf2;
	while (true)
	{

		cout << "Please enter the quantity: ";
		getline (cin, buf2);

		int temp = atoi(buf2.c_str());

		if (temp > 0)
            {
            quantity = temp;
            break;
            }

		cout << "Invalid quantity. Quantity cannot be negative or string. Please try it again. " << endl;
	}

	//float input
	string buf3;
	while (true)
	{
		cout << "Please enter the price for each item: ";

		getline (cin, buf3);

		double temp = atof(buf3.c_str());

		if (temp > 0)
            {
            price = temp;
            break;
            }

		cout << "Invalid price. Price cannot be negative or string. Please try it again. " << endl;
	}

	//calculate cost ------------------------------------------------
	double cost;
	cost = quantity * price;

	//print table ------------------------------------------------------------
	cout << std::right;

    cout << " ITEM( " << fixed << itemName << " ) " ;

    cout << "QUANTITY( " << setprecision(2) << fixed << quantity << " ) " ;

    cout << "PRICE( $" << setprecision(2) << fixed << price << " ) " ;

    cout << "COST( $" << setprecision(2) << fixed << cost << " ) " << endl;

	//--------- add movie to the beginning of the list ---------
	if (head == nullptr)
	{

		//creates new node
		CreateMenuNode* nextNode;

		//declares new node as part of CreateMenuNode structure / list
		nextNode = new CreateMenuNode();

		//insert values into structure

		nextNode -> price = price;
		nextNode -> quantity = quantity;
		nextNode -> itemName = itemName;
		nextNode -> cost = cost;

		nextNode -> next = nullptr;

		//add movie to list
		//links the newMovie node to head
		head = nextNode;


		//add movie to list

		//links the newMovie node to head
		head = nextNode;

	}
	else
	{
		//construct new node structure
		CreateMenuNode* nextNode;

		//tells compiler it is a a new CreateMenuNode
		nextNode = new CreateMenuNode();

		//insert values into structure
        nextNode -> price = price;
		nextNode -> quantity = quantity;
		nextNode -> itemName = itemName;
		nextNode -> cost = cost;

		//update next movie to point to rest of the list
		nextNode -> next = head;  //only difference in if else statement

		//add next movie at beginning of list
		head = nextNode;

	}

}//End of function

/*******************************************************************************
* Function : functionShowReceipts
* Parameters :  CreateMenuNode*& head (IN)
* Return : void
* Description :
*       prints table of receipts
********************************************************************************/
void functionShowReceipts(CreateMenuNode*& head)
{
	CreateMenuNode* temp;  //new node with just structure

	temp = head; //initializes new temp node as the same thing as head. (which means they are linkable)

	cout << endl;
	cout << "-- Receipt --------------------------------------" << endl;

	int counter = 1; //starts at one because we are displaying the list.

    bool cVal = true; //for printing no list of movies
	while (temp != nullptr)
	{
		cout << std::right;

        cout << " ITEM( " << fixed << temp -> itemName << " ) " ;

        cout << "QUANTITY( " << setprecision(2) << fixed << temp -> quantity << " ) " ;

        cout << "PRICE( " << setprecision(2) << fixed << temp -> price << " ) " ;

        cout << "COST( " << setprecision(2) << fixed << temp -> cost << " ) " << endl;

		temp = temp->next;
		cVal = false; //sets false once one list is filled
	}

	if (cVal)// If cval is true
        {
        cout << "List is empty.";
        cout << endl;
        }

}
/*******************************************************************************
* Function : functionShowSummary
* Parameters :  CreateMenuNode*& head (IN)
* Return : void
* Description :
*       totals all purchase and counts how many items purchased.
********************************************************************************/
void functionShowSummary(CreateMenuNode*& head)
{
    double total = 0;

	CreateMenuNode* temp;  //new node with just structure

	temp = head; //initialize new temp node as the same thing as head. (which means they are linkable)

	cout << endl;
	cout << "-- Summary --------------------------------------" << endl;

	int counter = 0;

    bool cVal = true; //for printing no list of movies
	while (temp != nullptr)
	{

        total = total + temp -> cost;

        counter = counter + 1;

		temp = temp->next;
		cVal = false; //sets false once one list is filled
	}

	if(!cVal)
    {
        cout << "PURCHASES( " << fixed << counter << " ) " ;
        cout << "TOTAL COST( $" << setprecision(2) << fixed << total << " ) " << endl;
    }

	if (cVal)// If cval is true
        {
        cout << "List is empty." << endl;
        cout << "No items to summarize!";
        cout << endl;
        }

}



