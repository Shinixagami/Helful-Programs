/*******************************************************************************
NAME: Vin Gabriel Fillon 11/20/2021 CompSci-165
TITLE: Lab Assignment 7
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Uses linked list with head and tail to traverse program
    ~able to edit linked list, and cut time complexity by saving addresses
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

void serializeDown (ofstream&, Animal* p);

Animal *serializeUp (ifstream& fin);

void deallocate (Animal *p);

void print_id (string lab_desc);

int main()
{

/*
	fin.open("TEST1.txt");
    if (fin.good()) // only read from the file if it exists!
        {

        string bufS; //buf method for EOF
        while (true || bufS != "EOF")

            {

                //TEMPORARY LINK LIST HOLD
                CreateMovieNode* storageInput;

                    //Storage is equal to new node
                    //meaning storage will have the same structure BUT IT IS A NEW NODE;
                storageInput = new CreateMovieNode();;


                // storageInput has these values
                // string movie;
                // int yearViewed;
                // string rating;
                // *next


                //MOVIE NAME ----------------
                getline(fin, bufS);

                if (bufS == "EOF") break;
                else {storageInput -> movie = bufS;}

                //YEAR VIWED / SEEN  ----------------
                fin >>  bufS;
                if (bufS == "EOF") break;
                else
                {
                    storageInput -> yearViewed = atoi(bufS.c_str());
                }

                fin.ignore(1000, 10); //fin ignore

                //RATING ----------------
                fin >>  bufS;
                if (bufS == "EOF") break;
                else
                {
                    storageInput -> rating  = atof(bufS.c_str());; //ATOF FOR FLOAT
                }

                enQueue(head, tail, storageInput);

                //how much nodes were created
                inputCounter = inputCounter+ 1;  //moves on to next set of data.

                fin.ignore(1000, 10); //fin ignore

            }//END OF WHILE LOOP FOR SERIALIZATION UP

        } //END OF SER UP

        fin.close(); // closes file
*/

//-----------------------------------------

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

int main()
{
	//open input file
	ifstream fin;
	fin.open ("test2.txt");

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
	    //8 answers
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

}// end of main


/*******************************************************************************
* Function : Serialize Up (grab input
* Parameters :  CreateMovieNode*& head
* Return : int
* Description :
*       Uses link list and dynamically modifies data
*       ~a movie is  stored in each node
*       ~the main nodes first chain is called "head"
********************************************************************************/
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

/*******************************************************************************
* Function : Serialize Down
* Parameters :  CreateMovieNode*& head
* Return : int
* Description :
*       Uses link list and dynamically modifies data
*       ~a movie is  stored in each node
*       ~the main nodes first chain is called "head"
********************************************************************************/
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

/*******************************************************************************
* Function : deallocate
* Parameters :  CreateMovieNode*& head
* Return : int
* Description :
*       Uses link list and dynamically modifies data
*       ~a movie is  stored in each node
*       ~the main nodes first chain is called "head"
********************************************************************************/
void deallocate (Animal *p)
{
	if (p == 0) return;

	//deallocate everything
	deallocate(p -> yes);
	deallocate(p -> no);
	delete p;
}
