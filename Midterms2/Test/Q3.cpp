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


//a linked list a set of dynamically allocated nodes
//nodes - elements in a linked list
//all nodes have  DATA and a pointer to the next address
// --- It is like a more dynamic array.
struct Node //basically a class.
{
    //DATA -----
    int dataVal;
    Node* next;
};

//print not used in program
void printNodeList(Node*& head);

int main ()
{

    string buf;
    int input;

    Node* head = nullptr;

    int counter = 0;
    while(true)
        {

        cout << "counter: " << counter << endl;
        cout << "enter negative number to terminate input! " << endl;
        cout << "please enter the input for node [" << counter << "] : ";
        getline(cin, buf);

        input = atoi(buf.c_str());

        cout << endl;


        if (input < 0)
            {
            break;
            }

        cout << endl;


        if (head == nullptr)
            {
            cout << "~added to start of list[with nullptr)" << endl;

            //new temp struct
            Node* nextNode = new Node;

                //value = INT NUMBER
            nextNode -> dataVal = input;

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
            nextNode -> dataVal = input;

            //update next node to point to rest of the list
            nextNode -> next = head;  //only difference in if else statement

            //add next to the END of the list - not beginning
            head = nextNode;
            }


        counter += 1;

        }


    printNodeList(head);




}

void printNodeList(Node*& head)
{
    int counter = 1;

        //while it is not equal to end of Node with nullptr;
    while(head != nullptr)
        {
        //How to to print node address;

        //dereference and reference address
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Data inside Node [ " << counter << "] " << endl;
        cout << head -> dataVal << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        //points to next address of head
        head = head -> next;

        counter += 1;
        }

}



