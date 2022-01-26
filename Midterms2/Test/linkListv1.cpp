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


#include <cstring>
#include<ctype.h>


//a linked list a set of dynamically allocated nodes
//nodes - elements in a linked list
//all nodes have  DATA and a pointer to the next address
// --- It is like a more dynamic array.
struct Node //basically a class.
{
    //DATA -----
    int idVal;
    //address of next node-----
    Node* next;
};

void inputNode(Node*& head, int inputAtoi ); //input function for array.

void printNodeList(Node*& head,int inputAtoi); //prints node;

void deleteNode(Node*& head); //deletes node

void insertAtTheFront(Node** head, int newValue); //insert at the front

void insertAtTheEnd(Node** head, int newValue);



void insertAfter(Node* previus, int newValue); //one pointer

int main()
{

    int counter = 0;
    string buf;


    //start of our linked list
    //DECLARES head node.
    Node* head = nullptr; //Last node with no elements

    int inputAtoi;



    while(true)
        {
        cout << "counter: " << counter << endl;
        cout << "enter negative number to terminate input! " << endl;
        cout << "please enter the input for node [" << counter << "] : ";
        getline(cin, buf);

        inputAtoi = atoi(buf.c_str());

        cout << endl;


        if (inputAtoi < 0)
            {
            break;
            }

        cout << endl;

        inputNode(head, inputAtoi); //input node function;

        counter += 1;

        }
        cout << endl;

        cout << " ~ While loop terminated ~" << endl;
        cout << "counter: " << counter << endl << endl;



        insertAtTheFront(&head, 4);



        cout << endl;
        printNodeList(head, inputAtoi);


        cout << endl;

//--------------------------------------
        insertAfter(head, 88);


        cout << endl;

        printNodeList(head, inputAtoi);


}//END OF MAIN


//INPUT NEW NODES AT THE START
void inputNode(Node*& head, int inputAtoi)
{
    //if it is the last node


    cout << "inputAtoi : " << inputAtoi  << endl;


    //IF head is nullptr -IT WIll do this.
    if (head == nullptr)
        {
        cout << "~added to start of list[with nullptr)" << endl;

        //new temp struct
        Node* nextNode = new Node;

            //value = INT NUMBER
        nextNode -> idVal= inputAtoi;

            //next pointer = null
        nextNode -> next = nullptr;

        //adds node to the list
        head = nextNode;

        }
    else
        {
        cout << "~Added to next list" << endl;
		//construct new structure
		Node* nextNode = new Node;

		//inserts value into new node
		nextNode -> idVal = inputAtoi;

		//update next node to point to rest of the list
		nextNode -> next = head;  //only difference in if else statement

		//add next to the END of the list - not beginning
		head = nextNode;


        }


}


void insertAfter(Node* previus, int newValue)
{

    //1. CHECK IF PREVIOYS node is NULL
    if(previus == nullptr){

        cout << "PREVIUS CAN NOT BE NULL";
        return;
    }


    //2. prepare a newNode
    Node* newNode = new Node();

    newNode -> idVal = newValue; //new value

    //3. Insert a newNode after previous
    newNode-> next = previus -> next;
    previus-> next  = newNode;



}


//INSERT AT THE FRONT
void insertAtTheFront(Node** head, int newValue)
{
    //prepare A NEW NODE


    Node* newNode = new Node(); //Allocates memory
    newNode -> idVal = newValue;


    //PUT IT INFRONT OF CURRENT HEAD
    newNode->next = *head;

    //MOVE head of the lust to point to the newNode;
    *head = newNode;

}

void insertAtTheEnd(Node** head, int newValue)
{

    cout << "INSERT AT THE END"  << endl;
    //1. Prepares A new node
    Node* newNode = new Node();

    newNode -> idVal = newValue;
    newNode -> next = nullptr;

    //2. if linked list is empty, new node will be head node
    if (*head = nullptr)
        {
        *head = newNode;
        return;
        }

    //3. find the last node;

    //last is temporary
    Node* last = *head;

    while(last -> next != nullptr)
    {
        last = last -> next; //goes to the last one;

    }

    //4. insert newNode after last node
    last -> next = newNode;


}//end of function


//PRINTS NODE LIST
void printNodeList(Node*& head,int inputAtoi)
{

     cout << "---- printing ----"  << endl;
    int counter = 0;

        //while it is not equal to end of Node with nullptr;
    while(head != nullptr)
        {
        //How to to print node address;

        //dereference and reference address
       int n = 5;
       int* address = &n;  //referenced address

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " address to pointer:"  << &head << endl;
        cout << "Data inside Node [ " << counter << "] " << endl;
        cout << head -> idVal << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        //points to next address of head
        head = head -> next;

        counter += 1;
        }

}


//DELETE NODE -WITHOUT STUDENT
void deleteNode(Node*& head) //deletes node
{

    cout << "---deleteing nodes activated---"  << endl;

    //declare variables
	Node* temp = head;//set pointer temp to beginning of menu

	//keeping track
	int index = 1;


	int sequenceNumber;
    string buf;


	//which number to delete
	cout << "Enter number of movie would you like to delete: ";


	getline(cin, buf);

    sequenceNumber = atoi(buf.c_str());




	//remove first value from list
	if (sequenceNumber == 1)
	{
		head = temp -> next;//shift list to the left
		return;
	}

	//searching values in list to find value we want to delete

	while (temp->next != nullptr)
	{
		//check if next value is our target
		//if index is the same as sequence number

		if (index + 1 == sequenceNumber)
		{
			//saving replacement location
			Node* temp2 = temp -> next -> next;

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

	}// END OF WHILE




}//END Of delete function



//DELETES NODE PASS by reference
void deleteNode(Node*& head)
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














