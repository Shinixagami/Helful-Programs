/*******************************************************************************
NAME: Vin Gabriel Fillon 11/09/2021 CompSci-165
TITLE: Lab Assignment 6
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

#include <string.h> //for char or C String

#include <string>
using std::getline; //get line for input
using std::string; //c++ string

#include <algorithm>
using std::swap; //swap

#include <cctype> // for toupper and tolower
using std::tolower;
using std::toupper;

struct CreateMovieNode //format of the one node
{
	string movie;

	int yearViewed;

	char rating;

	CreateMovieNode* next;
};

void funcChoiceA(CreateMovieNode*& head);

void funcChoiceU(CreateMovieNode*& head);

void funcChoiceEPop (CreateMovieNode*& head);

void funcChoiceList(CreateMovieNode*& head);

void funcChoiceTitle(CreateMovieNode*& head);

void funcChoiceYearViewed(CreateMovieNode*& head);

void funcChoiceRating(CreateMovieNode*& head);

/*******************************************************************************
* Function : Main Function
* Parameters :  CreateMovieNode*& head
* Return : int
* Description :
*       Uses link list and dynamically modifies data
*       ~a movie is  stored in each node
*       ~the main nodes first chain is called "head"
********************************************************************************/
int main()
{

	//CreateMovieNode - is the structure = will be used for the node
	//Head - is the start of the node = head like a snake
	CreateMovieNode* head;
	head = nullptr; //sets the address of next to nullptr - done


	char menuInput; //menu choices

	//head of options for user
	while (true)
	{

        cout << endl;
	    cout << "MENU~" << endl;
		cout << "A - Add Movie " << endl;
		cout << "U - Update a movie " << endl;
		cout << "E - Remove a movie " << endl;
		cout << "L - List all moves " << endl;
		cout << "T - Arrange by movie title " << endl;
		cout << "V - Arrange by year viewed " << endl;
		cout << "R - Arrange by rating " << endl;
		cout << "Q - Quit " << endl;
		cout << "Enter Input of your choice: ";

        cin >>  menuInput;
        cin.ignore(1000, 10); //problems with next line -keep this.

		//add movie -----------------------------------------
		if (menuInput == 'a' || menuInput == 'A')
		{
			funcChoiceA(head);
		}

		//update movie -----------------------------------------
		if (menuInput == 'u' || menuInput == 'U')
		{
			funcChoiceU(head);
		}

		//delete movie -----------------------------------------
        if (menuInput == 'e' || menuInput == 'E')
		{
			funcChoiceEPop(head);
		}

		//list movies -----------------------------------------
		if (menuInput == 'l' || menuInput == 'L')
		{
			funcChoiceList(head);
		}

		//arrange movies by title -----------------------------------------
        if (menuInput == 't' || menuInput == 'T')
		{
			funcChoiceTitle(head);
		}

		//arrange movies by date -----------------------------------------
		if (menuInput == 'v' || menuInput == 'V')
		{
			funcChoiceYearViewed(head);
		}

		//arrange movies by rating -----------------------------------------
        if (menuInput == 'r' || menuInput == 'R')
		{
			funcChoiceRating(head);
		}

		//end
		if (menuInput == 'q' || menuInput == 'Q')
		{
			break;
		}

	}

}

/*******************************************************************************
* Function : funcChoiceA
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       adds elements in node (node start is called head)
*       ~newNode is the add on node that will be linked on
********************************************************************************/
void funcChoiceA(CreateMovieNode*& head)
{
    cout << endl;
	char movieNameInput[120];
	int yearViewed;
	char movieRating[120];

    string buf1;
	while (true)
	{
		cout << "Enter name of movie: ";

        getline (cin, buf1);

		if (!buf1.empty())
            {
            //this will lead to the conversion of buf1
            break;
            }
		cout << "Invalid Input. Please try again! " << endl;
	}

	// ---------- turns buf1 into c string ----------
    char *cStringConversion;

    //tells the cStringConversion its new length.
    cStringConversion = new char[buf1.length()];

    for (int i = 0; i < buf1.length(); i++)
        {
            cStringConversion[i] = buf1[i];
        }

    cStringConversion[buf1.length()] = '\0' ; //add the null terminator at the end of the char array

    strcpy(movieNameInput, cStringConversion); //copies new data.

    //integer input ---------------
	while (true)
	{
		cout << "Enter year viewed: ";
		cin >> yearViewed;

		if (yearViewed > 0)
            {
            break;
            //this will lead to the conversion of buf1
            }

		cout << "Invalid Input. Please try again! " << endl;
	}

	//char input
	string buf2;
	while (true)
	{
		cout << "Enter the movie rating: ";;
		getline (cin, buf2);


		if (!buf2.empty())
            {
            break;
            }

		cout << "Invalid Input. Please try again! " << endl;
	}

	cin.ignore(1000, 10); //problems with next line -keep this.

	// ---------- turns buf2 into c string ----------
    char *cStringConversion1;

    //tells the cStringConversion its new length.
    cStringConversion1 = new char[buf2.length()];

    for (int i = 0; i < buf2.length(); i++)
        {
            cStringConversion1[i] = buf2[i];
        }

    cStringConversion1[buf2.length()] = '\0' ; //add the null terminator at the end of the char array

    strcpy(movieRating, cStringConversion1); //copies new data.

	//add movie to the beginning of the list
	if (head == nullptr)
	{
		//creates new node
		CreateMovieNode* nextMovie;

		//declares new node as part of CreateMovieNode structure / list
		nextMovie = new CreateMovieNode();

		//insert values into structure
		nextMovie -> movie = movieNameInput;
		nextMovie -> yearViewed = yearViewed;
		nextMovie -> rating = movieRating;
		nextMovie -> next = nullptr;

		//add movie to list
		//links the newMovie node to head
		head = nextMovie;

	}
	else
	{
		//construct new node structure
		CreateMovieNode* nextMovie;

		//tells compiler it is a a new CreateMovieNode
		nextMovie = new CreateMovieNode();

		//insert values into structure
		nextMovie->movie = movieNameInput;
		nextMovie->yearViewed = yearViewed;
		nextMovie->rating = movieRating;

		//update next movie to point to rest of the list
		nextMovie -> next = head;  //only difference in if else statement

		//add next movie at beginning of list
		head = nextMovie;
	}

}//End of function

/*******************************************************************************
* Function : funcChoiceU
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       modifies (updates) elements in the node.
*       ~creates a temp node that is linked to head
********************************************************************************/
void funcChoiceU(CreateMovieNode*& head)
{
    cout << endl;

	//declare variables
	int sequenceNumber;
	int index = 0;

	cout << "Which number movie do you want to update: ";
	cin >> sequenceNumber;

	//creates a temp node that is linked to head
	CreateMovieNode* temp = head;

	while (temp != nullptr)
	{
		//found requested location
		if (index + 1 == sequenceNumber)
		{
			//declare variables
			char newMovie[120];
			int yearViewed;
			char movieRating;

			while (true)
			{
				cout << "Enter name of the movie: " ;

				cin.getline(newMovie, 120);

				if (newMovie != "")
                    {
                    break;
                    }
			}
            cin.ignore(1000, 10); //problems with next line -keep this.

			while (true)
			{
				cout << "Enter year viewed: " << endl;
				cin >> yearViewed;
				break;
			}

			while (true)
			{
				cout << "Enter the movie rating: " << endl;
				cin >> movieRating;
				break;
			}

			//inserts new info
			temp -> movie = newMovie;
			temp -> yearViewed = yearViewed;
			temp -> rating = movieRating;

			return; //returns to main once done -does NOT go through code below

		}

		//check next location
		else
		{
			temp = temp->next;
			index++;
		}
	}

}// End of function

/*******************************************************************************
* Function : funcChoiceEPop
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       deletes a whole node by deleting address linking nodes together
********************************************************************************/
void funcChoiceEPop(CreateMovieNode*& head)
{
    //The method is a copy transfer delete method---------
	CreateMovieNode* temp; //temporary hold for storage;

    temp = head; //copies values from head to temp;

	int counter = 1; //starts at one because it is going through the list;

	int sequenceNumber;

	//ask user what movie to delete
	cout << "Enter number of list number you would you like to delete: ";
	cin >> sequenceNumber;

	//remove first value from list -----------------------------
	if (sequenceNumber == 1)
	{
		head = temp -> next;//shift list to the left
		return;
	}

	//searching values in list to find value we want to delete ------
	while (temp->next != nullptr)
	{
		//check if next value is our target
		if (counter + 1 == sequenceNumber)
		{
			//saving replacement location
			CreateMovieNode* temp2 = temp -> next -> next;

			//restructure list
			temp -> next = temp2;
            counter++;
			return;
		}
		else
		{
			temp = temp -> next;
            counter++;
		}

	}

}//End of function

/*******************************************************************************
* Function : funcChoiceList
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       Prints table of movies through while loop.
********************************************************************************/
void funcChoiceList(CreateMovieNode*& head)
{
	CreateMovieNode* temp;
	temp = head; //new temp linked list -which data is copied from head

	cout << "# Title           Viewed   Rating" << endl;
	cout << "- -------------  --------  ------" << endl;

	int counter = 1; //starts at one because we are displaying the list.

	while (temp != nullptr)
	{
		cout.width(2);
		cout << std::left;
		cout << counter;
		cout.width(17);
		cout << temp->movie;
		cout.width(10);
		cout << temp->yearViewed;
		cout.width(40);
		cout << temp->rating << endl;
		counter++;
		temp = temp->next;
	}

}

/*******************************************************************************
* Function : funcChoiceList
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       Sorts Linked List by Movie Title
********************************************************************************/
void funcChoiceTitle(CreateMovieNode*& head)
{

	//go through all values of list
	for (CreateMovieNode* p = head; p; p = p->next)
        {
		//find the smallest value to the right of p
		for (CreateMovieNode* q = p -> next; q; q = q->next)
            {
			//if value if smaller swap
			if (q->movie < p->movie)
                {
				swap(*p, *q);
				swap(p->next, q->next);
                }
            }
        }

    cout << "~Movies now arranged by titles!~" << endl;
}

/*******************************************************************************
* Function : funcChoiceYearViewed
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       Sorts Linked List by year viewed
********************************************************************************/
void funcChoiceYearViewed(CreateMovieNode*& head)
{
	for (CreateMovieNode* p = head; p; p = p->next)
        {

		for (CreateMovieNode* q = p  -> next; q; q = q->next)
            {

			if (q->yearViewed < p->yearViewed)
                {
				swap(*p, *q);
				swap(p->next, q->next);
                }
            }
        }

    cout << "~Movies now arranged by year viewed!~" << endl;
}

/*******************************************************************************
* Function : funcChoiceRating
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       Sorts Linked List by year viewed
********************************************************************************/
void funcChoiceRating(CreateMovieNode*& head)
{
	for (CreateMovieNode* p = head; p; p = p->next)
	{
		for (CreateMovieNode* q = p->next; q; q = q->next)
		{
			if (q->rating < p->rating)
			{
				swap(*p, *q);
				swap(p->next, q->next);
			}
		}
	}

	 cout << "~Movies now arranged by rating!~" << endl;
}
