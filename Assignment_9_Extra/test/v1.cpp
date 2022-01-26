/*******************************************************************************
NAME: Vin Gabriel Fillon 11/20/2021 CompSci-165
TITLE: Extra Credit Lab Assignment
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Uses linked list with head and tail to traverse program
    ~able to edit linked list, and cut time complexity by saving addresses
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

     //open input file
	ifstream fin;
	fin.open ("password.txt");

    if(fin.good()) //if there is a file to be read
    {
        cout << "File Found ..." << endl;

        string bufS; //buf method for EOF
        int temp1;

        while (true)
        {

            getline(fin, bufS);

            if (bufS == "EOF") break;

            else
            {
            password = temp1;
            }

        fin.close();

        }

    fin.close();

    }









	//CreateMenuNode - is the structure = will be used for the node
	//Head - is the start of the node = head like a snake
	CreateMenuNode* head;
	head = nullptr; //nullptr is set to cut the node


	//CreateMenuNode - is the structure
	//tail - is the end of the node = tail of the snake
	//CreateMenuNode* tail;
	//head = nullptr; //nullptr is set to cut the node (in this case this will be the last input) -since we have a tail


	string menuInput; //menu choices

	//head of options for user
	while (true)
	{

//How to index or find the number of nodes
//------------------------------------------------------------- TEST

        int counter= 0; // Initialize counter
        CreateMenuNode* current; //new struct with node structure

        current = head; // current now contains the same address as head;

        while (current != nullptr) //if it is NOT NULLPTR / NULL
        {
            counter++; //counts the nodes
            current = current-> next; //moves through the list
        }

        cout << " COUNTER IS NOW: " << counter << endl;


//------------------------------------------------------------- TEST

        cout << endl;
	    cout << "Shopping Menu~" << endl;
		cout << "1. buy " << endl;
		cout << "2. show receipts " << endl;
		cout << "3. show summary " << endl;
		cout << "4. exit " << endl;
		cout << "Enter Input of your cption: ";
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


		//end
		if (inputVal == 4)
		{
			break;
		}



	}// end of if loop



    int count = 0; // Initialize count

    CreateMenuNode* current = head; // Initialize current

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    cout << " COUNTER IS NOW: " << count << endl;



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

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  cout << endl;
  cout << "CHECK IF LOOP DELETE THE DATA "<< endl;
  functionShowReceipts(head);


}// end of main

/*******************************************************************************
* Function : functionBuyItem
* Parameters :  CreateMenuNode*& head (IN)
* Return : void
* Description :
*       adds elements in node (node start is called head)
*       ~newNode is the add on node that will be linked on
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

		cout << "Please enter the quantity: " << endl;
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

	cout << "cost is: " << cost << endl;




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



void functionShowReceipts(CreateMenuNode*& head)
{
	CreateMenuNode* temp;  //new node with just structure

	temp = head; //initializses new temp node as the same thing as head. (which means they are linkable)

	cout << endl;
	cout << "-- Movies List ------------------" << endl;
	cout << "# Title           Viewed   Rating" << endl;
	cout << "- -------------  --------  ------" << endl;

	int counter = 1; //starts at one because we are displaying the list.

    bool cVal = true; //for printing no list of movies
	while (temp != nullptr)
	{
		cout.width(2);
		cout << std::left;
		cout << counter;
		cout.width(17);

		cout << setprecision(2) << fixed << temp-> itemName;
		cout.width(10);

		cout << setprecision(2) << fixed << temp-> quantity;
		cout.width(40);
		cout << setprecision(2) << fixed << temp-> price << endl;
		cout.width(10);
		cout << setprecision(2) << fixed << temp-> cost<< endl;
		counter++;

		temp = temp->next;
		cVal = false; //sets false once one list is filled
	}

	if (cVal)// If cval is true
        {
        cout << "List is empty.";
        cout << endl;
        }

}

void functionShowSummary(CreateMenuNode*& head)
{
	CreateMenuNode* temp;  //new node with just structure

	temp = head; //initializses new temp node as the same thing as head. (which means they are linkable)

	cout << endl;
	cout << "-- Movies List ------------------" << endl;
	cout << "# Title           Viewed   Rating" << endl;
	cout << "- -------------  --------  ------" << endl;

	int counter = 1; //starts at one because we are displaying the list.

    bool cVal = true; //for printing no list of movies
	while (temp != nullptr)
	{
		cout.width(2);
		cout << std::left;
		cout << counter;
		cout.width(17);
		cout << setprecision(2) << fixed << temp-> itemName;
		cout.width(10);
		cout << setprecision(2) << fixed << temp-> quantity;
		cout.width(40);
		cout << setprecision(2) << fixed << temp-> price << endl;

		cout << setprecision(2) << fixed << temp-> cost << endl;
		counter++;
		temp = temp->next;
		cVal = false; //sets false once one list is filled
	}

	if (cVal)// If cval is true
        {
        cout << "List is empty.";
        cout << endl;
        }

}



