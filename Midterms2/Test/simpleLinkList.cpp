/*******************************************************************************
NAME: Vin Gabriel Fillon 10/28/2021 CompSci-165
TITLE: Lab Assignment 5b
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Program is a menu driven program for expenses.
    Takes inputs in array structs and searches for specific expenses.
    Inputs are not case sensitive.
    ~Using C strings~  &  ~Dynamic Array~
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


/*---------------------------------------------------------------
INFO: a linked list a set of dynamically allocated nodes
~nodes - elements in a linked list
~all nodes have  DATA and a pointer to the next address
 --- It is like a more dynamic array.
/*--------------------------------------------------------------*/


struct Node //basically a class. - private by default
{
public: //sets class as public to be accessible outside of

    //data -----
    int value;
    //address of next node-----
    Node* next;
};



//not used 
void inputValue(Node* ); //input function for array.

//not used 
void deleteNode(Node* ); //deletes node

//not used 
void printList(Node* n); //n is the node information


int main()
{

    //first element of linked list
    //node pointer
    Node* head = new Node();  //allocated space for first node

    Node* second = new Node(); //second node

    Node* third = new Node(); //third node

    //NodeName  -uses similar notation to .dot notation

    //adding elements to a node --------------------------------------------------

    //first node
    head -> value = 10;
    head -> next = second; //points to next address

    //second
    second -> value = 20;
    second -> next = third; //points to next address

    //third
    third -> value = 30;
    third -> next = NULL; //points to Nothing - end of address;

    printList(head);

    cout << endl;
    //cout << " end " << counter << endl;

}



void printList(Node* n)
{

    int counter = 0;

    //-this can be a for loop as well
    while(n != NULL) //while it is not the null address
        {

        cout << "~loop [ "<< counter << " ]" << endl;

        //prints out value
        cout << "Value: " << n->value << endl;

        //moves address to the next address.
        n = n -> next;

        //counts loops
        counter += 1;
        }


}//end of print node
