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

#include<ctype.h>
#include <cstring>
#include<ctype.h>


struct CreateMovieNode
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

void toLowerCaseFunction(char menuInput[]);

void table();

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

		//A Add a movie
		if (menuInput == 'a')
		{
			funcChoiceA(head);
		}
		//U Update a movie

		if (menuInput == 'u')
		{
			funcChoiceU(head);
		}

		//E rEmove a movie
        if (menuInput == 'E' || menuInput == 'e')
		{
			funcChoiceEPop(head);
		}

		//L List all movies
		if (menuInput == 'l')
		{
			funcChoiceList(head);
		}

		//T arrange by Title
        if (menuInput == 't')
		{
			funcChoiceTitle(head);
		}


		//V arrange by year Viewed
		if (menuInput == 'v')
		{
			funcChoiceYearViewed(head);
		}


		//R arrange by Rating
        if (menuInput == 'r')
		{
			funcChoiceRating(head);
		}

		//Q Quit
		if (menuInput == 'q' )
		{
			break;
		}

	}
}


/*******************************************************************************
*Function: funcChoiceA
*
*Add movie
*
*Parameters:
*	CreateMovieNode* &head (IN): reference to the pointer head
*Return: NONE
********************************************************************************/


void funcChoiceA(CreateMovieNode*& head)
{
	//declare variables
	char movieNameInput[120];
	int yearViewed;
	char movieRating;

	//name of movie
	while (true)
	{
		cout << "Enter name of movie: ";
		cin.getline(movieNameInput, 120);
		if (movieNameInput != "")
            {
            break;
            }
		cout << "Please try again! " << endl;
	}

	//year of movie
	while (true)
	{
		cout << "Enter year viewed: ";
		cin >> yearViewed;
		break;
	}

	//movie rating
	while (true)
	{
		cout << "Enter the CreateMovieNode rating: ";
		cin >> movieRating;
		break;
	}

	//add movie to the beginning of the list
	if (head == nullptr)
	{
		//creates new node
		CreateMovieNode* nextMovie;

		//declares new node as part of CreateMovieNode structure / list

		nextMovie = new CreateMovieNode();

		//insert values into structure
		nextMovie -> movie = movieNameInput; //left side points to place. right side puts value in that place
		nextMovie -> yearViewed = yearViewed;
		nextMovie -> rating = movieRating;
		nextMovie -> next = nullptr;

		//add movie to list
		//links the temporary newMovie node
		head = nextMovie;

	}
	else
	{
		//construct new structure
		CreateMovieNode* nextMovie;

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

}

/*******************************************************************************
*Function: funcChoiceU
*
*Update expenses
*
*Parameters:
*	CreateMovieNode* &head (IN): reference to the pointer head
*Return: NONE


********************************************************************************/
void funcChoiceU(CreateMovieNode*& head)
{
	//declare variables
	int sequenceNumber;
	int index = 0;

	cout << "Which number movie do you want to update: " << endl;
	cin >> sequenceNumber;
	//cin.ignore(10, 1000);

	//create new temporary head to point to the beginning of head
	CreateMovieNode* temp = head;//left side pointer. put head there

	while (temp != nullptr)
	{
		//found requested location
		if (index + 1 == sequenceNumber)
		{
			//declare variables
			char newMovie[500];
			int yearViewed;
			char movieRating;

			while (true)
			{
				cout << "Enter name of movie: " << endl;
				cin.getline(newMovie, 500);
				if (newMovie != "")
					break;
			}

			while (true)
			{
				cout << "Enter year viewed: " << endl;
				cin >> yearViewed;
				break;
			}

			while (true)
			{
				cout << "Enter the CreateMovieNode rating: " << endl;
				cin >> movieRating;
				break;
			}

			//update info
			temp -> movie = newMovie;
			temp -> yearViewed = yearViewed;
			temp -> rating = movieRating;

			//exit function
			return;

		}

		//check next location
		else
		{
			temp = temp->next;
			index++;
		}

	}

	cout << "Did not find requested location." << endl;

}



/*******************************************************************************
*Function: funcChoiceEPop
*
*Deletes nodes
*
*Parameters:
*	CreateMovieNode* &head (IN):refernce to the pointer head
*Return: NONE
********************************************************************************/
void funcChoiceEPop(CreateMovieNode*& head)
{
    //The method is a copy transfer delete method---------

	CreateMovieNode* temp; //temporary hold for storage;

    temp = head; //copies values from head to temp;

	int counter = 1; //starts at one because it is going through the list;

	int sequenceNumber;

	//ask user what movie to delete
	cout << "Enter number of movie would you like to delete: " << endl;
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
}

/*******************************************************************************
Function: funcChoiceList
*
*List CreateMovieNode
*
*Parameters:
*	CreateMovieNode* &head (IN): reference to the pointer head
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
*Function: funcChoiceTitle
*
*Arrange by title
*
*Parameters:
*	CreateMovieNode*& head (IN): reference to pointer head
*Return: NONE
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
}

/*******************************************************************************
Function: funcChoiceYearViewed
*
*Arrange by year viewed
*
*Parameters:
*	CreateMovieNode* &head (IN): reference to pointer head
*Return: NONE
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
}

/*******************************************************************************
*Function: Rating
*
*Arrange by rating
*
*Parameters:
*	CreateMovieNode* &head (IN):
*Return: NONE
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
}
