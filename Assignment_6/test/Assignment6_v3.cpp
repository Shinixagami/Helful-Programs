/*******************************************************************************
NAME: Vin Gabriel Fillon 11/15/2021 CompSci-165
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

	string rating;

	CreateMovieNode* next;
};

void funcChoiceAdd(CreateMovieNode*& head);

void funcChoiceUpdate(CreateMovieNode*& head);

void funcChoiceRemove(CreateMovieNode*& head);

void funcChoiceList(CreateMovieNode*& head);

void funcChoiceArrangeByTitle(CreateMovieNode*& head);

void funcChoiceArrangeByYearViewed(CreateMovieNode*& head);

void funcChoiceArrangeByRating(CreateMovieNode*& head);

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

	string menuInput; //menu choices

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

        getline(cin, menuInput);

		//add movie -----------------------------------------
		if (menuInput == "a" || menuInput == "A")
		{
			funcChoiceAdd(head);
		}

		//update movie -----------------------------------------
		if (menuInput == "u" || menuInput == "U")
		{
			funcChoiceUpdate(head);
		}

		//delete movie -----------------------------------------
        if (menuInput == "e" || menuInput == "E")
		{
			funcChoiceRemove(head);
		}

		//list movies -----------------------------------------
		if (menuInput == "l" || menuInput == "L")
		{
			funcChoiceList(head);
		}

		//arrange movies by title ----------------------------------------
        if (menuInput == "t" || menuInput == "T")
		{
			funcChoiceArrangeByTitle(head);
		}

		//arrange movies by date -----------------------------------------
		if (menuInput == "v" || menuInput == "V")
		{
			funcChoiceArrangeByYearViewed(head);
		}

		//arrange movies by rating ---------------------------------------
        if (menuInput == "r" || menuInput == "R")
		{
			funcChoiceArrangeByRating(head);
		}

		//end
		if (menuInput == "q" || menuInput == "Q")
		{
			break;
		}
	}
}// end of main

/*******************************************************************************
* Function : funcChoiceAdd
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       adds elements in node (node start is called head)
*       ~newNode is the add on node that will be linked on
********************************************************************************/
void funcChoiceAdd(CreateMovieNode*& head)
{
    cout << endl;
	string movieNameInput;
	int yearViewed;
	string movieRating;

    string buf1;
	while (true)
	{
		cout << "Enter a movie's name: ";

        getline (cin, buf1);

		if (!buf1.empty())
            {
            movieNameInput = buf1;
            break;
            }
		cout << "Invalid Input. Please try again! " << endl;
	}

    //int input
    string buf2;
	while (true)
	{

		cout << "Enter the year you saw " << movieNameInput << " [like 2016]: ";
		getline (cin, buf2);

		int temp = atoi(buf2.c_str());

		if (temp > 0)
            {
            yearViewed = temp;
            break;
            }

		cout << "Invalid Input. Please try again! " << endl;
	}

	//float input
	string buf3;
	while (true)
	{
		cout << "Enter your rating for " << movieNameInput << " [1-10]: ";

		getline (cin, buf3);

		double temp = atof(buf3.c_str());

		if (temp > 0 && temp <= 10)
            {
            movieRating = buf3;
            break;
            }

		cout << "Invalid Input. Please try again!" << endl;
	}

	//--------- add movie to the beginning of the list ---------
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
* Function : funcChoiceUpdate
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       modifies (updates) elements in the node.
*       ~creates a temp node that is linked to head
********************************************************************************/
void funcChoiceUpdate(CreateMovieNode*& head)
{

    CreateMovieNode* temp;
	temp = head; //new temp linked list -which data is copied from head

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
		cout << setprecision(2) << fixed << temp->movie;
		cout.width(10);
		cout << setprecision(2) << fixed << temp->yearViewed;
		cout.width(40);
		cout << setprecision(2) << fixed << temp->rating << endl;
		counter++;

		temp = temp->next;
		cVal = false; //sets false once one list is filled
	}

	if (cVal)
        {
        cout << "List is empty." << endl;
        cout << "Please add movies to update! " << endl;
        }

    //Update -------------------------------------
    //only if list is NOT EMPTY
	if(cVal != true)
    {
        int sequenceNumber;
        int index = 0;

        cout << "Which movie do you want to update (please input the list #): ";
        cin >> sequenceNumber;

        cin.ignore(1000, 10); //problems with next line -keep this.

        //creates a temp node that is linked to head
        CreateMovieNode* temp = head;

        while (temp != nullptr)
        {
            //found requested location
            if (index + 1 == sequenceNumber)
            {
                //declare variables
                string updateMovie;
                int updateYearViewed;
                string updateMovieRating;


                string buf1;
                while (true)
                {
                    cout << "Enter the new movie name: ";

                    getline (cin, buf1);

                    if (!buf1.empty())
                        {
                        updateMovie = buf1;
                        break;
                        }
                    cout << "Invalid Input. Please try again! " << endl;
                }

                //integer input ---------------
                string buf2;
                while (true)
                {
                    cout << "Enter the year you saw " << updateMovie << " [like 2016]: ";
                    getline (cin, buf2);


                    int temp = atoi(buf2.c_str());

                    if (temp > 0)
                        {
                        updateYearViewed = temp;
                        break;
                        }
                    cout << "Invalid Input. Please try again! " << endl;
                }

                //float input
                string buf3;
                while (true)
                {
                    cout << "Enter your rating for " << updateMovie << " [1-10]: ";
                    getline (cin, buf3);

                    double temp = atof(buf3.c_str());

                    if (temp > 0 && temp <= 10)
                        {
                        updateMovieRating = buf3;
                        break;
                        }
                    cout << "Invalid Input. Please try again! " << endl;
                } // end of while loop

                //updates elements -----------
                temp -> movie = updateMovie;
                temp -> yearViewed = updateYearViewed;
                temp -> rating = updateMovieRating;

                cout << "Movie #" << sequenceNumber << " updated! " << endl;

                return; //returns to main once done -does NOT go through code below

            } //end of if loop

            //check next location
            else
            {
                temp = temp->next;
                index++;
            }

        }

	}//end of if !true cval

}// End of function

/*******************************************************************************
* Function : funcChoiceRemove
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       deletes a whole node by deleting address linking nodes together
********************************************************************************/
void funcChoiceRemove(CreateMovieNode*& head)
{

    CreateMovieNode* temp;
	temp = head; //new temp linked list -which data is copied from head

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
		cout << setprecision(2) << fixed << temp->movie;
		cout.width(10);
		cout << setprecision(2) << fixed << temp->yearViewed;
		cout.width(40);
		cout << setprecision(2) << fixed << temp->rating << endl;
		counter++;

		temp = temp->next;
		cVal = false; //sets false once one list is filled
	}

	if (cVal)
        {
        cout << "List is empty." << endl;
        cout << "You cannot remove any movies! " << endl;
        }


    //only if list is NOT EMPTY
	if(cVal != true)
    {
        //---------- The method is a copy transfer delete method --------------
        CreateMovieNode* temp1; //temporary hold for storage;

        temp1 = head; //copies values from head to temp1;

        int counter = 1; //starts at one because it is going through the list;

        int sequenceNumber;

        //ask user what movie to delete
        cout << "Enter the movie you would like to delete (please input the list #): ";
        cin >> sequenceNumber;

        //remove first value from list -----------------------------
        if (sequenceNumber == 1)
            {
            head = temp1 -> next;//shift list to the left

            cout << "Movie #1 deleted!" ;

            return;
            }

        //searching values in list to find value we want to delete ------
        while (temp1->next != nullptr)
            {
            //check if next value is our target
            if (counter + 1 == sequenceNumber)
                {
                //saving replacement location
                CreateMovieNode* temp2 = temp1 -> next -> next;

                //restructure list
                temp1 -> next = temp2;
                counter++;
                cout << "Movie #" << sequenceNumber << " deleted!" ;

                //Frees memory
                delete temp2;
                return;
                }
            else
                {
                temp1 = temp1 -> next;
                counter++;
                }
            }

        //Frees memory
        delete temp1;

        cout << "Movie #" << sequenceNumber << " deleted!" ;

	}// end of if cval

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
		cout << setprecision(2) << fixed << temp->movie;
		cout.width(10);
		cout << setprecision(2) << fixed << temp->yearViewed;
		cout.width(40);
		cout << setprecision(2) << fixed << temp->rating << endl;
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

/*******************************************************************************
* Function : funcChoiceList
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       Sorts Linked List by Movie Title
********************************************************************************/
void funcChoiceArrangeByTitle(CreateMovieNode*& head)
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
    cout << "----------------------------------------" << endl;
    cout << "~Movies now arranged by titles!~" << endl;
    cout << "----------------------------------------" << endl;
}

/*******************************************************************************
* Function : funcChoiceArrangeByYearViewed
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       Sorts Linked List by year viewed
********************************************************************************/
void funcChoiceArrangeByYearViewed(CreateMovieNode*& head)
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
    cout << "----------------------------------------" << endl;
    cout << "~Movies now arranged by year viewed!~" << endl;
    cout << "----------------------------------------" << endl;
}

/*******************************************************************************
* Function : funcChoiceArrangeByRating
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       Sorts Linked List by year viewed
********************************************************************************/
void funcChoiceArrangeByRating(CreateMovieNode*& head)
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
    cout << "----------------------------------------" << endl;
    cout << "~Movies now arranged by rating!~" << endl;
    cout << "----------------------------------------" << endl;
}
