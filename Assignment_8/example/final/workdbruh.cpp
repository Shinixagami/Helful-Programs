/*Name: Nichole Parkes
*Lab 8: Artificla Intelligence with Innate Knowledge
*Editor used: notepad++
*Compiler: visual studio
*Description: Write a C++ program to identify something
*by applying series of yes-no questions
**************************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include<fstream>
using std::ifstream;
using std::ofstream;

//Animal struct
struct Animal
{
	string sayThis;
	Animal *yes;
	Animal *no;
};

//declare functions
void serializeDown (ofstream&, Animal* p);
Animal *serializeUp (ifstream& fin);
void deallocate (Animal *p);
void print_id (string lab_desc);

int main()
{
	//open input file
	ifstream fin;
	fin.open ("ai.txt");

	//settop pointer to null, in order to avoid errors if nothing is in file.
	Animal *top = nullptr;

	if(fin.good())
	{
		//create node and fill with line from file, and attach descendent nodes.
		top = serializeUp(fin);
		fin.close();
	}

	//if you can not open file, build tree from info.
	else
	{
		Animal a = {"Bat"};
		Animal b = {"Bear"};
		Animal c = {"Bird"};
		Animal d = {"Reptile"};
		Animal e = {"Sturgeons"};
		Animal f = {"porgy"};
		Animal g = {"Shrimp"};
		Animal h = {"Jellyfish"};


		//all of the questions
		Animal i = {"Can if fly?", &a, &b}; //yes->a, n->b
		Animal j = {"Can it fly?", &c, &d}; //yes->c, no->d
		Animal k = {"Is it fresh water?", &e, &f}; //yes->e, no->f
		Animal l = {"Is it a crustacean", &g, &h}; //yes->g, no ->h
		Animal m = {"Is it a mammal?", &i, &j}; //yes->i,no->j
		Animal n = {"Does it have gills?", &k, &l}; //yes->k, no->l
		Animal o = {"Is it on land", &m, &n}; //yes->m, no ->n
		top = &o;
	}

	//declare variable
	string buf;

	//Ask user input
	cout << "Tell me about an animal and I will guess it."<<endl;

	//move p through the tree
	Animal *p = top;

	//take through all the questions
	while(true)//the p-loop
	{
		cout << p -> sayThis;//could be the answer or could be another question
		if (p -> yes == 0 && p -> no == 0) break;//if at the answer (if we're at the leaves)

		cout << " [y/n] ";

		getline(cin, buf);

		if (buf == "y" || buf == "Y")
		{
			p = p -> yes;
		}
		else if (buf == "n" || buf == "N")
		{
			p = p -> no;
		}

	}

	//opening output file
	ofstream fout;
	fout.open ("ai.txt");

	//call serialize function to write to file
	serializeDown (fout, top);

	//call deallocate function
	deallocate (top);

	//close input file
	fin.close();

}

/**********************************************************************
*Function: serializeDown
*
*Write to the file
*
*Parameters:
*	ofstream& fout (IN): file stream we are writing to
*	Animal * P (IN): pointer to Animal struct
*Return: NONE
***********************************************************************/

void serializeDown (ofstream&  fout, Animal* p)
{
	//make sure there is something to serializeDown
	if (p == nullptr)
		fout << "EOF\n";
	else
	{
		fout << p -> sayThis << "\n";

		//cout << p -> sayThis << "\n";
		serializeDown(fout,p -> yes);//serialize p->yes and all nodes below it
		serializeDown(fout,p -> no); //serialize p-> no and all nodes below it
	}
}
/**********************************************************************
*Function: Animal *serializeUp
*
*Reading from the file
*
*Parameters:
*	ifstream& fin (IN): file stream we are reading from
*
*Return: NONE
***********************************************************************/

Animal *serializeUp (ifstream& fin)
{
	string buf;
	getline (fin, buf);
	if (buf == "EOF") return nullptr;

	//create node to put info read into from file
	Animal *p = new Animal;

	p -> sayThis = buf;

	//serialize up all the yes nodes (going down the tree)
	p -> yes = serializeUp(fin);

	//serialize up all the no nodes (going down the tree)
	p -> no = serializeUp (fin);

	return p;
}
/**********************************************************************
*Function: deallocate
*
*deallocating nodes from tree
*
*Parameters:
*	Animal *p (IN): pointer to Animal struct
*
*Return: NONE
***********************************************************************/
void deallocate (Animal *p)
{
	if (p == 0) return;

	//deallocate everything
	deallocate(p -> yes);
	deallocate(p -> no);
	delete p;
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
cd C:\COMSC165\chap7
cl artificialIntelligence.cpp -EHs
*/
