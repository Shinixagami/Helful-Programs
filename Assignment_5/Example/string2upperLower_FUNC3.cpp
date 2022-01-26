#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include <cctype> // for toupper and tolower

string toLowerCase(string); // these don't actually change the case of the parameter...
string toUpperCase(string); //...they return a changed version of the parameter.

void search(string, string);

int main( )
{
  string a = "Hello";
  string b = "World";
  cout << toLowerCase(a) << endl; // shows as "hello"
  cout << toUpperCase(b) << endl; // shows as "WORLD"
  a = toLowerCase(a); // now "a" is replaced by "hello"
  b = toUpperCase(b); // now "b" is replaced by "WORLD"


  // Compare string no case-sensitbive
  b = "hello";
  if (toLowerCase(a) == toLowerCase(b))
    cout << "They are the same\n";
  else if (toLowerCase(a) < toLowerCase(b))
    cout << "a comes before b\n";
  else // toLowerCase(a) > toLowerCase(b)
    cout << "a comes after b\n";

  string prog = "Programming is fun.";


  search (prog, "fun");

  return 0;
}

string toLowerCase(string aCppString)
{
  int n = aCppString.length( );
  for (int i = 0; i < n; i++)

    aCppString[i] = tolower(aCppString[i]);


  return aCppString;
}

string toUpperCase(string aCppString)
{
  int n = aCppString.length( );
  for (int i = 0; i < n; i++)
    aCppString[i] = toupper(aCppString[i]);
  return aCppString;
}

// You can change return type to make it more useful in assignment 7
void search(string s, string target)
{
   int index;

   index = s.find(target);

   // Test for match
   if (index != string::npos)
      cout << target << " found" << endl;
   else
      cout << target << " not found" << endl;
}
