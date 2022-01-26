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

	CreateMovieNode* next; // single linked next pointer

};

void funcChoiceAdd(CreateMovieNode*& head, CreateMovieNode*& tail, int inputCounter);

void funcChoiceUpdate(CreateMovieNode*& head);

void funcChoiceRemove(CreateMovieNode*& head, CreateMovieNode*& tail, int nodeCount);

void funcChoiceList(CreateMovieNode*& head);

void funcChoiceArrangeByTitle(CreateMovieNode*& head);

void funcChoiceArrangeByYearViewed(CreateMovieNode*& head);

void funcChoiceArrangeByRating(CreateMovieNode*& head);

//enqueue - Add qeueue
void enQueue (CreateMovieNode*& head, CreateMovieNode*& tail, CreateMovieNode* nodeptr);

//eqeueue - dElete queue (takes in actual struct and modifies them.)
CreateMovieNode *deQueue (CreateMovieNode*& head, CreateMovieNode*& tail);

void CreateTxtFile (CreateMovieNode*& head, CreateMovieNode*& tail, int counter);



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
	head = nullptr; //nullptr is set to cut the node


	//CreateMovieNode - is the structure
	//tail - is the end of the node = tail of the snake

	//we can convert time complexity to linear to constant if we store mem address via tail
	CreateMovieNode* tail; //we have to keep this updated

	//nullptr is set to cut the node (in this case this will be the last input) -since we have a tail
	head = nullptr;


//------------------------------------------------------------------- TEST

 // serialize up
    ifstream fin; // declares an object

    int inputCounter = 0;

    fin.open("moviesTest.txt");
    if (fin.good()) // only read from the file if it exists!
        {
        cout << "- text file found - " << endl;

        string bufS; //buf method for EOF
        while (true || bufS != "EOF")

            {


            cout << "   NODES FILLED: " << inputCounter  << endl;

            //TEMPORARY LINK LIST HOLD
            CreateMovieNode* storageInput;


                //Storage is equal to new node
                //meaning storage will have the same structure BUT IT IS A NEW NODE;
            storageInput = new CreateMovieNode();;

            /*
            storageInput has these values

            string movie;

            int yearViewed;

            string rating;

            *next
            */

            //MOVIE NAME ----------------
            getline(fin, bufS);  //FOR COURSE NAME

            if (bufS == "EOF") break;
            else {storageInput -> movie = bufS;}


            //YEAR VIWED / SEEN  ----------------
            fin >>  bufS;      // FOR YEAR int

            if (bufS == "EOF") break;

            else
            {
                // storageInput.yearViewed = INT Year viewed
                storageInput -> yearViewed = atoi(bufS.c_str());
            }


            //RATING ----------------
            fin.ignore(1000, 10); //fin ignore

            fin >>  bufS;      // FOR UNITS
            if (bufS == "EOF") break;
            else
            {
                storageInput -> rating  = bufS; //ATOF FOR FLOAT
            }


            enQueue(head, tail, storageInput);

            //how much nodes were created


            inputCounter = inputCounter+ 1;  //moves on to next set of data.

            fin.ignore(1000, 10); //fin ignore


            }   //END OF WHILE LOOP FOR SER UP


            cout << "FIN SER UP INPUT FINISHED " << endl;

        } //END OF SER UP

        fin.close(); // closes file






	string menuInput; //menu choices

	//head of options for user
	while (true)
	{

//How to index or find the number of nodes
//------------------------------------------------------------- TEST

        int counter = 0; // Initialize counter
        CreateMovieNode* current; //new struct with node structure

        current = head; // current now contains the same address as head;

        while (current != nullptr) //if it is NOT NULLPTR / NULL
        {
            counter++; //counts the nodes
            current = current-> next; //moves through the list
        }

        cout << "~COUNTER IS NOW: " << counter << endl;

//------------------------------------------------------------- TEST

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
			funcChoiceAdd(head, tail, inputCounter);
		}

		//update movie -----------------------------------------
		if (menuInput == "u" || menuInput == "U")
		{
			funcChoiceUpdate(head);
		}

		//delete movie -----------------------------------------
        if (menuInput == "e" || menuInput == "E")
		{
			funcChoiceRemove(head, tail, inputCounter);
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

	}// end of if loop



    int nodeCount = 0; // Initialize count

    CreateMovieNode* current = head; // Initialize current

    while (current != nullptr)
    {
        nodeCount++;
        current = current->next;
    }

    cout << " COUNTER IS NOW: " << nodeCount<< endl << endl;


   //CreateTxtFile(head, tail, nodeCount);





//open output file
	ofstream fout;

	fout.open ("WORK_BITCH.txt");

	int n = 0;

	while(true)
	{
	    cout << "  n counter: " << n << endl;
		//set dequeue function to temp movie pointer
		CreateMovieNode *temp = deQueue(head, tail);

		//if temp equals nullptr you're at end of file, close file.
		if (temp == nullptr)
		{
			fout << "EOF";
			fout.close();  //closes file
			break;
		}

		//write info to text file
		else
		{
			fout << temp -> movie << endl;
			fout << temp -> yearViewed << endl;
			fout << temp -> rating << endl;

			//delete temp
			delete temp;
		}

		n = n + 1;

		cout << " inside that loop: " << n << endl << endl;


	}// end of while loop


    cout << " 2nd CREATE FILE "  << endl;
	CreateTxtFile(head, tail, nodeCount);










  // Deallocate all nodes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //while (true) -basically saying if it NOT NULLPTR / NULL
  while (head) // keep going as long as the list is not empty
  {
    //intialized placeHolder with same structure
    CreateMovieNode* placeHolder;


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
  funcChoiceList(head);



}// end of main

/*******************************************************************************
* Function : funcChoiceAdd
* Parameters :  CreateMovieNode*& head (IN)
* Return : void
* Description :
*       adds elements in node (node start is called head)
*       ~newNode is the add on node that will be linked on
********************************************************************************/

void funcChoiceAdd(CreateMovieNode*& head, CreateMovieNode*& tail, int inputCounter)

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


    CreateMovieNode* inputNewMovieNode;

    inputNewMovieNode = new CreateMovieNode;

    //insert values into structure

    inputNewMovieNode -> movie = movieNameInput;
    inputNewMovieNode -> yearViewed = yearViewed;
    inputNewMovieNode-> rating = movieRating;
    inputNewMovieNode -> next = nullptr;

    //adds to queue
    enQueue(head, tail, inputNewMovieNode);



}//End of add function

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


                    int tempInput = atoi(buf2.c_str());

                    if (temp > 0)
                        {
                        updateYearViewed = tempInput;
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
void funcChoiceRemove(CreateMovieNode*& head, CreateMovieNode*& tail, int nodeCount)
{
    //temp is initialized
    CreateMovieNode* temp;

    //temp is now the same as head
	temp = head;

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

        CreateMovieNode* temp = head;
        int index = 1;
        int sequenceNumber;

        cout << "Enter the movie you would like to delete (please input the list #) [1-" << index << "]: ";
        cin >> sequenceNumber;


        //remove first value from list
        if (sequenceNumber == 1)
        {
            //shift list to left
            head = temp -> next;

            //delete temp
            delete temp;
            nodeCount = nodeCount - 1;

            return;
        }

        //searching values in list to find value we want to delete
        while (temp-> next != nullptr)
        {
            //check if next value is our target
            if (index + 1 == sequenceNumber)
            {
                //saving replacement location
                CreateMovieNode* temp2 = temp -> next -> next;
                delete temp -> next;

                //restructure list
                temp -> next = temp2;
                index++;

                //if sequence number is equal to size
                if(sequenceNumber == nodeCount)
                {
                    tail = temp2;
                }
                //size--;

                nodeCount = nodeCount - 1;
                return;

             delete temp2;
            }


            else
            {
                temp = temp -> next;
                index++;
            }

    }

        //Frees memory ----
        delete temp;

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
	CreateMovieNode* temp;  //new node with just structure

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

//enqueue - Add qeueue



                //Head andTail are
void enQueue (CreateMovieNode*& head, CreateMovieNode*& tail, CreateMovieNode* nodePtr)
{
    cout << "(+)-------------------------------------" << endl;
    cout << "~add queue triggered!~" << endl;
    cout << "----------------------------------------" << endl;

    //temporary
    CreateMovieNode* temp = new CreateMovieNode;

	temp -> movie = nodePtr -> movie;

	temp -> yearViewed = nodePtr -> yearViewed;

	temp -> rating = nodePtr-> rating;

	temp -> next = 0;


	if (head == nullptr)
	{
        //if the start is null ptr, data is set
		head = temp;

		//if the end is null ptr, data is set
		tail = temp;
	}

	else
	{
		tail -> next = temp;//link old tail to new node

		tail = temp;//set tail to new node
	}


}

//deqeueue - ends the queue (takes in actual struct and modifies them.)
CreateMovieNode *deQueue (CreateMovieNode*& head, CreateMovieNode*& tail)
{
    cout << "(-)-------------------------------------" << endl;
    cout << "~delete queue triggered!~" << endl;
    cout << "----------------------------------------" << endl;

    CreateMovieNode* temp;

	//if not head or tail - it will return null ptr -this is to cut the info or stop it if it is NOT FILLED.
	if(!head || !tail)
	{
		//return null
		return nullptr;
	}

	//set head to temp
	temp = head;  //temporary head - temp now has the value of temp

	//if there is only one node. head ==tail
	if (head == tail)
	{
		//set nullptr to head
		head = nullptr;
		//set nulptr to tail
		tail = nullptr;
	}



	//got to next node
	else //everything else here will be executed
	{
		//set next node to head
		head = head -> next;

	}

	return temp;


}

void CreateTxtFile (CreateMovieNode*& head, CreateMovieNode*& tail, int counter)
{
    cout << " ---- CREATING TEXT FILE ---- " << endl;


    // serialize down
    ofstream fout; // declares an object of type "ofstream"
    fout.open("TESTER.txt");

    CreateMovieNode* temp = head;

        // Delete not needed for program
       for (int i = 0; i < counter+1; i++)
       {

            fout << temp -> movie << endl;
			fout << temp -> yearViewed << endl;
			fout << temp -> rating << endl;

			temp = temp -> next;
        }

    fout << "EOF\n"; // stands for end-of-file

    fout.close(); // done with the file

}





