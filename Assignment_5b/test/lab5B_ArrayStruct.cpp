/*Name: Nichole Parkes
*Lab 5A: Track Expenses Using Character Arrays (C string)
*Editor used: notepad++
*Compiler: visual studio
*Description: Write a menu-driven program
**************************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;


#include <cstring>
#include<string.h>
#include<ctype.h>

//struct of expenses
struct Expenses
{
	char typeExpense[500];
	double amount;
};

//declare function prototypes
void toLowerCase(char aCString[]);
bool search(char s[] , char target[]);
void print_id (string lab_desc);
void userChoice1(Expenses* menu, int index);
int userChoice2(Expenses* menu, int &maxSize, int index);
void userChoice3( Expenses* menu, int index);
void userChoice4 (Expenses* menu, int index);


/**********************************************************************
*Function: Main
**********************************************************************/

int main()
{
	//declare variables
	Expenses* menu= new Expenses [2];
	int maxSize=2;
	int index = 0;
	int userChoice;



	//menu of options for user
	while (true)
	{
		cout << "Expense Tracking Menu: " << endl;
		cout << "1. show all " << endl;
		cout << "2. spend " << endl;
		cout << "3. search expenses containing this string" << endl;
		cout << "4. search expenses with greater than or equal to this amount " << endl;
		cout << "5. exit " << endl;
		cout << "Enter your option: ";
		cin >> userChoice;
		cin.ignore(1000,10);

		//user choice 1: show all
		if (userChoice == 1)
		{
			userChoice1(menu,index);
		}

		//user choice 2: user enter expenses
		else if (userChoice == 2)
		{
			index=userChoice2(menu, maxSize, index);
		}

		//user choice 3: search for target expense
		else if (userChoice == 3)
		{
			userChoice3(menu, index);
		}

		//user choice 4: search expenses with greater than or equal to this amount
		else if (userChoice == 4)
		{
			userChoice4(menu, index);
		}

		//user choice 5: exit
		else
			if (userChoice == 5)
			break;

}
}
void userChoice1(Expenses* menu, int index)
{
	//go through index and ouput expense
	for(int i = 0; i < index; i++)
	cout << menu[i].amount <<" "<< menu[i].typeExpense << endl;
}

int userChoice2(Expenses* menu, int &maxSize, int index)
{
	char newTypeExpense[500];

	//user enter amount
	while (true)
	{
		string buf;
		cout << "Enter new amount: " << endl;
		getline(cin,buf);
		double newAmount=atof(buf.c_str());

		if (newAmount > 0)
		{
			//store newAmount in array
			menu[index].amount = newAmount;
			break;
		}
			else
		{
			cout << "Invalid input" << endl;

		}
	}
	//user enter type of expense
	cout << "Enter new type of expense: " << endl;
	while (true)
	{
		cin.getline(newTypeExpense,500);
		if (newTypeExpense!="")
			break;
	}
	//copy newTypeExpense into typeExpense
	strcpy(menu[index].typeExpense,newTypeExpense);
	index++;

if(index==maxSize)
{
	maxSize=maxSize*2;
	Expenses* newMenu=new Expenses[maxSize];

	for(int i=0; i<index;i++)
		newMenu[i]=menu[i];
	menu=newMenu;

	delete[] newMenu; // deletes whole struct array newMenu
	}


	return index;
}
void userChoice3(Expenses* menu, int index)
{
	char lookForExpense[500];

	//enter type of expense
	cout << "What is the type of expense you are looking for: " << endl;
	cin.getline(lookForExpense,500);

	//set look for expense to lowercase by calling toLowerCase function
	toLowerCase(lookForExpense);

	//search index for target expense by calling search function
	for (int i = 0; i < index; i++)
	{
		if (search(menu[i].typeExpense,lookForExpense) == true)
		{
			cout << menu[i].amount << " " << menu[i].typeExpense << endl;
		}
	}
}

void userChoice4 (Expenses* menu, int index)
{
	double compareAmounts;

	//user enter amount
	cout << "Enter amount: " << endl;
	cin >> compareAmounts;
	cin.ignore(1000,10);

	//go through index and compare amounts
	for(int i = 0; i < index; i++)
	{
		if (compareAmounts <= menu[i].amount)
		{
			cout << menu[i].amount << " " << menu[i].typeExpense << endl;;
		}
	}
}
/**********************************************************************
*Function: toLowerCase
*
*Convert to lowercase
*
*Parameters:
*	aCString (IN): type of expense
*Return: NONE
***********************************************************************/


void toLowerCase(char aCString[])
{
	for (int i = 0 ; aCString[i] !=0 ; i++)
	aCString[i] = tolower(aCString[i]);
}

/**********************************************************************
*Function: search
*
*Find target
*
*Parameters:
*	s (IN): expense
*	target (IN): target expense
*Return:
*	True if target is found
*	False if target is not found
***********************************************************************/

bool search(char s[], char target[])
{
	toLowerCase(s);
	//search for target
	if (strstr(s,target))
		return true;
	else
		return false;
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
cd C:\COMSC165\chap5
cl lab5B.cpp -EHs
*/
