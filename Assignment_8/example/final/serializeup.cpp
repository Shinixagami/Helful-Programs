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

  Movie* top = &g; // the full tree
  string buf;

  // the "challenge" to the user
  cout << "\nTell me about the movie you are watching and I'll identify it.\n";

  Movie* p = top; // move p through the tree
  while (true) // the p-loop
  {
    cout << p->sayThis; // could be the answer or could be another question
    if (p->yes == 0 && p->no == 0) break; // it was the answer -- we're done!
    cout << " [yes/no] ";

    getline(cin, buf);
    if (buf == "yes") p = p->yes;
    else if (buf == "no") p = p->no;
  }
*/
  /*
  // serialize top and all nodes below it
  ofstream fout;
  fout.open("movieTree.txt");
  serializeDown(fout, top);
  fout.close();
   */
  Movie* top;

  top = 0;
  // serialize the top and all nodes below it
  ifstream fin;
  fin.open("movieTree.txt");
  if (fin.good())
  {
    // create a node and fill with line from file, and attach all descendent nodes
    top = serializeUp(fin);
    fin.close();
  }
  else
  {
    top = new Movie;
    top->sayThis = "Star Wars";
    top->yes = top->no = 0;
  }

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

}

void serializeDown(ofstream &fout, Movie *p)
{
  // make sure there's something to serialize
  if (p == nullptr)
    fout << "EOF\n";
  else
  {
    // serialize the p node itself
    fout << p->sayThis << "\n";
	serializeDown(fout, p->yes);  // serialize p->yes and all nodes below it
    serializeDown(fout, p->no);  // serialize p->no and all nodes below it
  }
}


Movie *serializeUp(ifstream& fin)
{
  string buf;
  getline(fin, buf);
  if (buf == "EOF") return nullptr;

  Movie *p = new Movie;
  p->sayThis = buf;
  p->yes = serializeUp(fin);
  p->no = serializeUp(fin);
  return p;
}

void deallocate(Movie* p)
{
  if (p == 0) return;
  deallocate(p->yes);
  deallocate(p->no);
  delete p;
}
