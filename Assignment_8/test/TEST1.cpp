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
  string sayThis;
  animalNode *yes;
  animalNode *no;
};

void serializeDown(ofstream& fout, animalNode* p);
animalNode* serializeUp(ifstream& fin);
void deallocate(animalNode* p);


int main()
{


  // all of the animalNodes (end nodes)

    //open input file
	ifstream fin;
	fin.open ("INPUTi.txt");

    int nodes = 16;
    string storage[nodes];
    string bufS; //buf method for EOF

    if(fin.good())
    {//if there is a file to be read

        cout << "find found reading ...." << endl;
        cout << "reading done" << endl;


            animalNode *top = nullptr;

            // create a node and fill with line from file, and attach all descendent nodes
            top = serializeUp(fin);









            fin.close();








          // Deallocate all nodes
          deallocate(top);
    }


    if(!fin.good())
    {

         cout << "there was no file found making a new one... DEFAULT" << endl;

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

        animalNode *top = &o; // the full tree

        string buf;

        // the "challenge" to the user
        cout << "\n Tell me about an animal and I will guess it. .\n";

          animalNode *p = top; // move p through the tree
          while (true) // the p-loop
          {
            cout << p->sayThis; // could be the answer or could be another question
            if (p->yes == 0 && p->no == 0) break; // it was the answer -- we're done!
            cout << " [yes/no] ";

            getline(cin, buf);
            if (buf == "yes") p = p->yes;
            else if (buf == "no") p = p->no;
          } // end of while loop

//-----------------------------------------------------

         cout << endl;
         cout << "----- while loop has ended ----- " << endl;

          cout << "\n\n Serialize down: \n\n";

          // serialize down top and all nodes below it
          ofstream fout;
          fout.open("OUTPUTx.txt");
          serializeDown(fout, top);
          fout.close();





          // serialize up the top and all nodes below it
          //ifstream fin;

          top = nullptr;

          fin.open("animalNodeTree.txt");
          if (fin.good())
          {
            // create a node and fill with line from file, and attach all descendent nodes
            top = serializeUp(fin);
            fin.close();
          }

          else
          {
            top = new animalNode;
            top->sayThis = "Star Wars";
            top->yes = top->no = 0;
          }




          // Deallocate all nodes
          deallocate(top);

    }// end of else


}// end of int main

void serializeDown(ofstream& fout, animalNode* p)
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


animalNode *serializeUp(ifstream& fin)
{
  string buf;
  getline(fin, buf);
  if (buf == "EOF") return nullptr;

  animalNode* p = new animalNode;
  p->sayThis = buf;
  cout << "serializeUp: " << buf << endl;
  p->yes = serializeUp(fin);
  p->no = serializeUp(fin);
  return p;
}

void deallocate(animalNode* p)
{
  if (p == 0) return;
  deallocate(p->yes);
  deallocate(p->no);
  delete p;
}
