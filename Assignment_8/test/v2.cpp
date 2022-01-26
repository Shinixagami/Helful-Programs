#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;
struct Movie
{
  string sayThis;
  Movie *yes;
  Movie *no;
};

void serializeDown(ofstream& fout, Movie* p);
Movie* serializeUp(ifstream& fin);
void deallocate(Movie* p);

int main()
{



//if it is good do this


//question 1


//tier 2 Q1 , Q2


//tier 3 Q1, Q2, Q3 , Q4

/*

lifo -  last in first out
queue - fifo

    Title: ~which finanicla are would suite most~


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
*/


// serialize up the top and all nodes below it
  ifstream fin;
  fin.open("TESTin.txt");

  Movie *top = nullptr;

//replace this after before 8 pm
  if (fin.good())
  {
    cout << "file input found " << endl;
    // create a node and fill with line from file, and attach all descendent nodes
    //grabInput is top
    top  = serializeUp(fin);
    fin.close();
  }



  //if the file is not available
  else
  {
    cout << "no file found creating a new one " << endl;
    top = new Movie;
    top ->sayThis = "Star Wars";
    top ->yes = top -> no = 0;



        Movie a = {"Bat"};
		Movie b = {"Bear"};
		Movie c = {"Bird"};
		Movie d = {"Reptile"};
		Movie e = {"Sturgeons"};
		Movie f = {"porgy"};
		Movie g = {"Shrimp"};
		Movie h = {"Jellyfish"};


		//all of the questions
		Movie i = {"Can if fly?", &a, &b}; //yes->a, n->b
		Movie j = {"Can it fly?", &c, &d}; //yes->c, no->d
		Movie k = {"Is it fresh water?", &e, &f}; //yes->e, no->f
		Movie l = {"Is it a crustacean", &g, &h}; //yes->g, no ->h
		Movie m = {"Is it a mammal?", &i, &j}; //yes->i,no->j
		Movie n = {"Does it have gills?", &k, &l}; //yes->k, no->l
		Movie o = {"Is it on land", &m, &n}; //yes->m, no ->n
		top = &o;



  }

/*
  // all of the movies (end nodes)
  Movie a = {"It's Star Wars"};
  Movie b = {"It's Titanic"};
  Movie c = {"It's Lion King"};
  Movie d = {"It's Finding Nemo"};

  // all of the questions
  Movie e = {"Are fish involved?", &d, &c}; // yes->d, no->c
  Movie f = {"Is it a romatic film?", &b, &a}; // yes->b, no->a
  Movie g = {"Is it animated?", &e, &f};  // yes->e, no->f
*/




  Movie *top = &g; // the full tree
  string buf;

  // the "challenge" to the user
  cout << "\nTell me about the movie you are watching and I'll identify it.\n";

  Movie *p = top; // move p through the tree
  while (true) // the p-loop
  {
    cout << p->sayThis; // could be the answer or could be another question
    if (p->yes == 0 && p->no == 0) break; // it was the answer -- we're done!
    cout << " [yes/no] ";
    getline(cin, buf);
    if (buf == "yes") p = p->yes;
    else if (buf == "no") p = p->no;
  }

  cout << "\n\n Serialize down: \n\n";

  // serialize down top and all nodes below it
  ofstream fout;
  fout.open("TESTout.txt");
  serializeDown(fout, top);
  fout.close();
  top = nullptr;

  // Deallocate all nodes
  deallocate(top);
}
void serializeDown(ofstream& fout, Movie* p)
{
  // make sure there's something to serialize
  if (p == nullptr)
    fout << "EOF\n";
  else
  {
    // serialize the p node itself
    fout << p->sayThis << "\n";
cout << p->sayThis << "\n";
serializeDown(fout, p->yes);  // serialize p->yes and all nodes below it
    serializeDown(fout, p->no);  // serialize p->no and all nodes below it
  }
}
Movie *serializeUp(ifstream& fin)
{
  string buf;
  getline(fin, buf);
  if (buf == "EOF") return nullptr;
  Movie* p = new Movie;
  p->sayThis = buf;
  cout << "serializeUp: " << buf << endl;
  p->yes = serializeUp(fin);
  p->no = serializeUp(fin);
  return p;
}
void deallocate(Movie* p)
{
  if (p == 0) return;
  deallocate(p->yes);
}
