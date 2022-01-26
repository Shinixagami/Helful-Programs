/*******************************************************************************
NAME: Vin Gabriel Fillon 11/23/2021 CompSci-165
TITLE: Lab Assignment 8
IDE: Code::Blocks
COMPILER: Code::Blocks
DESCRIPTION:
    Program is similar to bot / Ai chat bots  (version 3)
    Program uses Binary Trees to find different responses for different questions.
********************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

struct animalNode
{
  string sayThis;RrR
  animalNode *yes;
  animalNode *no;
};

void serializeDown(ofstream& fout, animalNode* p);
animalNode* serializeUp(ifstream& fin);
void deallocate(animalNode* p);

/*******************************************************************************
* Function : Main Function
* Parameters :  N/A
* Return : int
* Description :
*       Uses if or else statement to check if file exist
*       ~if file exist read of it and make 7 Q / 8 aswr Binary Tree
*       ~if file does NOT exist use default Binary Tree
********************************************************************************/
int main()
{
    //open input file
	ifstream fin;
	fin.open ("ai.txt");

    if(fin.good()) //if there is a file to be read
    {
        cout << "File Found ..." << endl;

            //start node
            animalNode *top = nullptr;

            // create a node and fill with line from file, and attach all decendent nodes
            top = serializeUp(fin);
        /*------------------------------------------------------------------------------
        Binary Tree structure:
        *binary tree is static NOT dynamic (has to have separate code to create branches)
        *has 7 questions
        *has 8 answers

        File: Ai.text
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
               1   2  3  4  5  6  7  8           yes = 1  Crypto.com
                                                 no = 2   Binance.com - no support
                                              a2  ----------------   Crypto / non technical
                                                 yes = 3  Gemini
                                                 no = 4 Coinbase - no support
                                              b1  ----------------  stocks / technical
                                                 yes = 5   Webull
                                                 no = 6  Robinhood - no support
                                              b2  ----------------   stocks / non technical
                                                 yes = 7   Td Ameritrade
                                                 no = 8   Merril Lynch - no support
        -----------------------------------------------------------------------------*/

           string buf;
           cout << endl;
           cout << "~ Which financial vehicle would suite you the most ~ " << endl;

          animalNode *p = top; // move p through the tree
          while (true) // the p-loop
          {
            cout << endl;
            cout << p->sayThis; // could be the answer or could be another question
            if (p->yes == 0 && p->no == 0) break; // it was the answer -- we're done!
            cout << " [yes/no]: ";

            getline(cin, buf);
            if (buf == "y" || buf == "Y" || buf == "yes" ||  buf == "YES" ) p = p->yes;
            else if
            (buf == "n" || buf == "N" || buf == "no" ||  buf == "NO" ) p = p->no;
          }// end of while true

          cout  << endl;
          ofstream fout;
          fout.open("ai.txt");
          serializeDown(fout, top);
          fout.close();

          //deletes all nodes
          deallocate(top);

    }//end of if good.

    fin.close(); //here to avoid errors with open file

    //if it is not good -meaning if the file does not exist do this.
    if(!fin.good())
    {

        //default binary tree
        animalNode a = {"it is a Bat"};
		animalNode b = {"it is a Bear"};
		animalNode c = {"it is a Bird"};
		animalNode d = {"it is a Reptile"};
		animalNode e = {"it is a Sturgeons"};
		animalNode f = {"it is a porgy"};
		animalNode g = {"it is a Shrimp"};
		animalNode h = {"it is a Jellyfish"};

        //all of the questions - 7 questions
        animalNode i = {"Can if fly?", &a, &b}; //yes->a, n->b
		animalNode j = {"Can it fly?", &c, &d}; //yes->c, no->d
		animalNode k = {"Is it fresh water?", &e, &f}; //yes->e, no->f
		animalNode l = {"Is it a crustacean", &g, &h}; //yes->g, no ->h
		animalNode m = {"Is it a mammal?", &i, &j}; //yes->i,no->j
		animalNode n = {"Does it have gills?", &k, &l}; //yes->k, no->l
		animalNode o = {"Is it on land", &m, &n}; //yes->m, no ->n

		//goes through from root to leaves
        animalNode *top = &o; // the full tree

        //Binary Tree choice picker -------------------------------------------
        string buf;
        cout << endl;
        cout << " Tell me about an animal and I will guess it. . . ." << endl;

        animalNode *p = top; // move p through the tree
        while (true) // the p-loop
        {
        cout << endl;
        cout << p->sayThis; // could be the answer or could be another question
        if (p->yes == 0 && p->no == 0) break; // it was the answer -- we're done!
        cout << " [yes/no]: ";

        getline(cin, buf);
        if (buf == "y" || buf == "Y" || buf == "yes" ||  buf == "YES" ) p = p->yes;
        else if
        (buf == "n" || buf == "N" || buf == "no" ||  buf == "NO" ) p = p->no;
        } // end of while loop

        // serialize down top and all nodes below it
        ofstream fout;
        fout.open("ai.txt");
        serializeDown(fout, top);
        fout.close();

        //deletes all nodes
        deallocate(top);

    }// end of else

}// end of int main

/*******************************************************************************
* Function : serialize Down
* Parameters :  ofstream fout AnimalNode* p (IN)
* Return : void
* Description :
*       ~prints data onto ai.txt
********************************************************************************/
void serializeDown(ofstream& fout, animalNode* p)
{
  // make sure there's something to serialize
  if (p == nullptr)
    fout << "EOF\n";
  else
  {
    // serialize the p node itself
    fout << p->sayThis << "\n";
	//cout << p->sayThis << "\n";
	serializeDown(fout, p->yes);  // serialize p->yes and all nodes below it
    serializeDown(fout, p->no);  // serialize p->no and all nodes below it
  }
}

/*******************************************************************************
* Function : serialize Up
* Parameters :  ofstream fout AnimalNode* p (IN)
* Return : void
* Description :
*       ~grabs data from ai.txt
********************************************************************************/
animalNode *serializeUp(ifstream& fin)
{
  string buf;
  getline(fin, buf);
  if (buf == "EOF") return nullptr;

  animalNode* p = new animalNode;
  p->sayThis = buf;
  //cout << "serializeUp: " << buf << endl;
  p->yes = serializeUp(fin);
  p->no = serializeUp(fin);
  return p;
}

/*******************************************************************************
* Function : Deallocate
* Parameters :  AnimalNode* p
* Return : void
* Description :
*       deletes all nodes and clears memory
********************************************************************************/
void deallocate(animalNode* p)
{
  if (p == 0) return;
  deallocate(p->yes);
  deallocate(p->no);
  delete p;
}
