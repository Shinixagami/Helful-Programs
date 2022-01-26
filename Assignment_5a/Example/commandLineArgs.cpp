#include <iostream>
#include <string>

using namespace std;



//takes in two inputs.

//any function has parameters you can declare

        //arg count , arg vector
        //argc is how many elements in array
int main(int argc, char *argv[])  //argv is array of char
{

   string pgmName   = argv[0] ; //name it was given
   string arg1;

   cout << "argc = " << argc << endl;

   if (argc > 1)
     arg1 = argv[1] ;
   else
     arg1 = "Not given" ;


   cout << "PROGRAM: " << pgmName << endl;
   cout << "argv[1]: " << arg1 << endl;


   return 0;
}
