/*******************************************************************************
NAME: Vin Gabriel Fillon 12/07/2021 CompSci-165
TITLE: Extra Credit Lab Assignment
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
	Linked List program
********************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <algorithm>
using std::swap;

#include<iomanip>

#include <cstring>
#include<string.h>
#include<ctype.h>

struct Movies
{
	string movie;
	int yearViewed;
	char rating;
	Movies* next;
};

//declare function prototypes
void userChoiceA(Movies*& menu);
void userChoiceU(Movies*& menu);
void userChoiceEPop(Movies*& menu);
void userChoiceL(Movies*& menu);
void userChoiceT(Movies*& menu);
void userChoiceV(Movies*& menu);
void userChoiceR(Movies*& menu);
void print_id(string lab_desc);
void table();



int main()
{
	//declare variables
	Movies* menu = nullptr; //holds start of our list
	char userChoice;
	char buf;

	//menu of options for user
	while (true)
	{
		cout << "Press A to add a movie: " << endl;
		cout << "Press U to update a movie: " << endl;
		cout << "Press E to remove a movie: " << endl;
		cout << "Press L to list all movies: " << endl;
		cout << "Press T to arrange by title: " << endl;
		cout << "Press V to arrange by year viewed: " << endl;
		cout << "Press R to arrange by rating: " << endl;
		cout << "Press Q for quit: " << endl;
		cout << "Enter your choice: " << endl;
		cin >> userChoice;
		cin.ignore(1000, 10);

		//user choice a: add movie
		if (userChoice == 'A' || userChoice == 'a')
		{
			userChoiceA(menu);
		}
		//user choice u: update movie
		else if (userChoice == 'U' || userChoice == 'u')
		{
			userChoiceU(menu);
		}
		//user choice e: delete movie
		else if (userChoice == 'E' || userChoice == 'e')
		{
			userChoiceEPop(menu);
		}
		//user choice l: list movies
		else if (userChoice == 'L' || userChoice == 'l')
		{
			userChoiceL(menu);
		}
		//user choice t: arrange by title
		else if (userChoice == 'T' || userChoice == 't')
		{
			userChoiceT(menu);
		}
		//user choice v: arrange by date
		else if (userChoice == 'V' || userChoice == 'v')
		{
			userChoiceV(menu);
		}
		//user choice r: arrange by rating
		else if (userChoice == 'R' || userChoice == 'r')
		{
			userChoiceR(menu);
		}
		//User choice q: quit
		else if (userChoice == 'Q' || userChoice == 'q')
		{
			break;
		}

	}
}

/**********************************************************************
*Function: userChoiceA
*
*Add movie
*
*Parameters:
*	Movies* &menu (IN): reference to the pointer menu
*Return: NONE
***********************************************************************/

void userChoiceA (Movies*& menu)
{
	//declare variables
	char newMovie[500];
	int yearViewed;
	char movieRating;

	//name of movie
	while (true)
	{
		cout << "Enter name of movie: " << endl;
		cin.getline(newMovie, 500);
		if (newMovie != "")
			break;
	}

	//year of movie
	while (true)
	{
		cout << "Enter year viewed: " << endl;
		cin >> yearViewed;
		break;
	}

	//movie rating
	while (true)
	{
		cout << "Enter the movies rating: " << endl;
		cin >> movieRating;
		break;
	}

	//add movie to the beginning of the list
	if (menu == nullptr)
	{
		//construct new structure
		Movies* nextMovie = new Movies(); //left side creates pointer. right side creates new structure

		//insert values into structure
		nextMovie -> movie = newMovie; //left side points to place. right side puts value in that place
		nextMovie -> yearViewed = yearViewed;
		nextMovie -> rating = movieRating;
		nextMovie -> next = nullptr;

		//add movie to list
		menu = nextMovie;



	}
	else
	{
		//construct new structure
		Movies* nextMovie = new Movies;

		//insert values into structure
		nextMovie->movie = newMovie;
		nextMovie->yearViewed = yearViewed;
		nextMovie->rating = movieRating;

		//update next movie to point to rest of the list
		nextMovie -> next = menu;  //only difference in if else statement

		//add next movie at beginning of list
		menu = nextMovie;
	}

}

/**********************************************************************
*Function: userChoiceU
*
*Update expenses
*
*Parameters:
*	Movies* &menu (IN): reference to the pointer menu
*Return: NONE
***********************************************************************/

void userChoiceU(Movies*& menu)
{
	//declare variables
	int sequenceNumber;
	int index = 0;

	cout << "Which number movie do you want to update: " << endl;
	cin >> sequenceNumber;
	//cin.ignore(10, 1000);

	//create new temporary menu to point to the beginning of menu
	Movies* temp = menu;//left side pointer. put menu there

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
				cout << "Enter the movies rating: " << endl;
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

/**********************************************************************
*Function: userChoiceEPop
*
*Delete expenses
*
*Parameters:
*	Movies* &menu (IN):refernce to the pointer menu
*Return: NONE
***********************************************************************/

void userChoiceEPop(Movies*& menu)
{
	//declare variables
	Movies* temp = menu;//set pointer temp to beginning of menu



	int index = 1;



	int sequenceNumber;

	//ask user what movie to delete
	cout << "Enter number of movie would you like to delete: " << endl;
	cin >> sequenceNumber;

	//remove first value from list
	if (sequenceNumber == 1)
	{
		menu = temp -> next;//shift list to the left
		return;
	}

	//searching values in list to find value we want to delete

	while (temp->next != nullptr)
	{
		//check if next value is our target
		if (index + 1 == sequenceNumber)
		{
			//saving replacement location
			Movies* temp2 = temp -> next -> next;

			//restructure list
			temp -> next = temp2;
			index++;
			return;
		}
		else
		{
			temp = temp -> next;
			index++;
		}

	}
}

/**********************************************************************
*Function: userChoiceL
*
*List movies
*
*Parameters:
*	Movies* &menu (IN): reference to the pointer menu
*Return: NONE
***********************************************************************/

void userChoiceL(Movies*& menu)
{
	//declare variables
	Movies* temp = menu;
	table();
	int movieCounter = 1;

	while (temp != nullptr)
	{
		cout.width(2);
		cout << std::left;
		cout << movieCounter;
		cout.width(17);
		cout << temp->movie;
		cout.width(10);
		cout << temp->yearViewed;
		cout.width(40);
		cout << temp->rating << endl;
		movieCounter++;
		temp = temp->next;
	}

}


/**********************************************************************
*Function: userChoiceT
*
*Arrange by title
*
*Parameters:
*	Movies*& menu (IN): reference to pointer menu
*Return: NONE
***********************************************************************/

void userChoiceT(Movies*& menu)
{
	//go through all values of list
	for (Movies* p = menu; p; p = p->next)
	{
		//find the smallest value to the right of p
		for (Movies* q = p -> next; q; q = q->next)
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

/**********************************************************************
*Function: userChoiceV
*
*Arrange by year viewed
*
*Parameters:
*	Movies* &menu (IN): reference to pointer menu
*Return: NONE
***********************************************************************/

void userChoiceV(Movies*& menu)
{
	for (Movies* p = menu; p; p = p->next)
	{
		for (Movies* q = p  -> next; q; q = q->next)
		{
			if (q->yearViewed < p->yearViewed)
			{

				swap(*p, *q);
				swap(p->next, q->next);
			}
		}
	}
}

/**********************************************************************
*Function: userChoiceR
*
*Arrange by rating
*
*Parameters:
*	Movies* &menu (IN):
*Return: NONE
***********************************************************************/

void userChoiceR(Movies*& menu)
{
	for (Movies* p = menu; p; p = p->next)
	{
		for (Movies* q = p->next; q; q = q->next)
		{
			if (q->rating < p->rating)
			{
				swap(*p, *q);
				swap(p->next, q->next);
			}
		}
	}
}

/**********************************************************************
*Function: table
*
*Create table
*
*Return: NONE
***********************************************************************/

void table()
{
	cout << "# Title           Viewed   Rating" << endl;
	cout << "- -------------  --------  ------" << endl;
}

//funtion for every assignment output
void print_id(string lab_desc)
{
	cout << "\n";
	cout << "Name: Nichole Parkes\n";
	cout << lab_desc << "\n";
	cout << "Editor(s) used: notepad++" << "\n";
	cout << "Compiler(s) used: visual studio" << "\n";
	cout << "File: " << __FILE__ << "\n";
	cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}

/*
cd C:\COMSC165\chap6
cl linkedLists.cpp -EHs
*/
