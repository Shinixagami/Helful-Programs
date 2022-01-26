#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int main( )
{
  string a = "Hello";
  string b = "hello";
  if (a == b)
    cout << "They are the same\n";
  else if (a < b)
    cout << "a comes before b\n";
  else // a > b
    cout << "a comes after b\n"; 
	
  return 0;
}