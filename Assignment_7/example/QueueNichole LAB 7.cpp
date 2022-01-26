/*Name: Nichole Parkes
*Lab 7: Queue
*Editor used: notepad++
*Compiler: visual studio
*Description: Using a queue to store information
**************************************************************************************/

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

#include<fstream>
using std::ifstream;
using std::ofstream;

struct Movies
{
	string movie;
	int yearViewed;
	char rating;
	Movies* next;
};

//declare function prototypes
void userChoiceA (Movies*& menu, Movies *&tail, int &size);
void userChoiceU(Movies*& menu, int &size);
void userChoiceEPop(Movies*& menu, Movies *& tail, int &size);
void userChoiceL(Movies*& menu);
void userChoiceT(Movies*& menu);
void userChoiceV(Movies*& menu);
void userChoiceR(Movies*& menu);
void print_id(string lab_desc);
void table();
Movies *dequeue (Movies *&head, Movies *&tail);
void enqueue (Movies *&head, Movies *&tail, Movies *nodeptr);



int main()
{
	//declare variables
	Movies* menu = nullptr;
	char userChoice;
	char buf;
	Movies *tail = nullptr;
	int size=0;


	ifstream fin;
	fin.open ("moviesTest1.txt");
	if(fin.is_open())
	{
		while(true)
		{
			Movies *temp = new Movies();
			fin>>temp->movie;
			if (temp-> movie == "EOF")
				break;

			fin>>temp->yearViewed;
			fin>>temp->rating;

			enqueue(menu, tail, temp);
			size++;
		}

		fin.close();
	}



	//menu of options for user
	while (true)
	{
		cout << endl;
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
			userChoiceA(menu,tail,size);
		}
		//user choice u: update movie
		else if (userChoice == 'U' || userChoice == 'u')
		{
			userChoiceU(menu,size);
		}
		//user choice e: delete movie
		else if (userChoice == 'E' || userChoice == 'e')
		{
			userChoiceEPop(menu,tail,size);
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
	ofstream fout;
	fout.open ("moviesTest1.txt");

	while(true)
	{

		Movies *temp; //new struct temporary

		temp = dequeue(menu, tail);


		if (temp == nullptr)
		{
			fout << "EOF";
			fout.close();
			break;
		}


		else
		{
			fout<< temp->movie<<endl;
			fout<< temp -> yearViewed <<endl;
			fout<< temp-> rating<<endl;

			delete temp;
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

void userChoiceA (Movies*& menu, Movies *&tail, int &size)
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

	//construct new structure
	Movies* inputNewMovieNode = new Movies();

	//insert values into structure
	inputNewMovieNode -> movie = newMovie;
	inputNewMovieNode -> yearViewed = yearViewed;
	inputNewMovieNode -> rating = movieRating;
	inputNewMovieNode -> next = nullptr;

	//add movie to queue
	enqueue(menu, tail ,inputNewMovieNode);
	size++;

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

void userChoiceU(Movies*& menu, int &size)
{
	//declare variables
	int sequenceNumber;
	int index = 0;

	cout << "Which number movie between 1 and "<<size<< " that you would like to update: ";
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
			cin.getline(newMovie, 500);

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
*Function: userChoiceEPop -- BASICALLY DELETE
*
*Delete expenses
*
*Parameters:
*	Movies* &menu (IN):refernce to the pointer menu
*Return: NONE
***********************************************************************/

void userChoiceEPop(Movies*& menu, Movies *&tail, int &size)
{
	//declare variables
	Movies* temp = menu;//set pointer temp to beginning of menu
	int index = 1;
	int sequenceNumber;

	//ask user what movie to delete
	cout << "Enter number of movie between 0 and "<<size<<" that you would like to delete: " << endl;
	cin >> sequenceNumber;

	//remove first value from list
	if (sequenceNumber == 1)
	{

		menu = temp -> next;//shift list to the left
		delete temp;
		size--;
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
			delete temp -> next;
			//restructure list
			temp -> next = temp2;
			index++;
			if(sequenceNumber==size)
			{
				tail=temp2;
			}
			size--;
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
		for (Movies* q = p->next; q; q = q->next)
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




void enqueue(Movies *&head, Movies *&tail, Movies *nodeptr)
{
	Movies *temp = new Movies;

	temp -> movie = nodeptr -> movie;

	temp -> yearViewed = nodeptr -> yearViewed;

	temp -> rating = nodeptr -> rating;

	temp -> next = 0;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail -> next = temp;//link old tail to new node
		tail = temp;//set tail to new node
	}

}

Movies *dequeue (Movies *&head, Movies *&tail)
{
	Movies *temp;

	if(!head || !tail)
	{
		return nullptr;
	}

	temp = head;

	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}

	else
	{
		head = head -> next;
	}
	return temp;
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
cl queue.cpp -EHs
*/
