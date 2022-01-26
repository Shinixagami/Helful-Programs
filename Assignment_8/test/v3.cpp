/*******************************************************************************
NAME: Vin Gabriel Fillon 11/20/2021 CompSci-165
TITLE: Lab Assignment 7
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    An Ai program with different links
********************************************************************************/

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
	//open input file
	ifstream fin;
	fin.open ("ai.txt");

	//settop pointer to null, in order to avoid errors if nothing is in file.
	Animal *top = nullptr;


	int nodes = 16;
    string storage[nodes];
    string bufS; //buf method for EOF
    if(fin.good())
        {

    //---------------------------------------------------
            lifo -  last in first out
            queue - first in first out

        Title: ~which financial are would suite most~


        Tier1             0         do you like inflation and price manipulation ??   Q[1]
                         / \          a = yes - banks / stocks
                        /   \         b = no - crypto
                  yes  /     \  no
                      /       \
        Tier2        a         b       are you very technical ?  yes / a2 no Q[2]
                    / \       / \         yes =  a1 / a2
                   /   \     /   \        no =  b1 / b2
                  /     \   /     \
        Tier3    a1     a2  b1     b2       Would you like a good support team incase of issues ? Q[3]
                / \    / \  / \   / \         a1  ----------------  Crypto / technical
               1   2  3  4  5  6  7  8           yes = 1  crypto.com
                                                 no = 2   binance.com - no support
                                              a2  ----------------   Crypto / non technical
                                                 yes = 3  gemini
                                                 no = 4 coinbase - no support
                                              b1  ----------------  stocks / technical
                                                 yes = 5   webull
                                                 no = 6  robinhood - no support
                                              b2  ----------------   stocks / non technical
                                                 yes = 7   Td Ameritrade
                                                 no = 8   Merril Lynch - no support
    //-------------------------------------------------------
    */

                for (int i = 0; i < nodes; i ++)
                {

                    cout << endl;
                    cout << "getting data" << endl;
                    getline(fin, bufS);
                    if (bufS == "EOF") break;
                    else {storage[i] = bufS;}
                    cout << "data grabbed: " << storage[i] << endl;
                }

                 for (int i = 0; i < nodes; i ++)
                {

                    cout << endl;
                    cout << "data grabbed[" << i <<"]: " << storage[i] << endl;
                }

                cout << endl;

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
                Animal m = {storage[2], &i, &j}; //yes->i,no->j
                Animal n = {"Does it have gills?", &k, &l}; //yes->k, no->l
                Animal o = {"Do you like banks", &m, &n}; //yes->m, no ->n
                top = &o;

                fin.close();

        }// end of if good

	//if you can not open file, build tree from info.
	else
	{
        cout << "no file found creating a new one " << endl;

        top = new Animal;
        top ->sayThis = "Star Wars";
        top ->yes = top -> no = 0;

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

***********************************************************************/
void deallocate (Animal *p)
{
	if (p == 0) return;

	//deallocate everything
	deallocate(p -> yes);
	deallocate(p -> no);
	delete p;
}
