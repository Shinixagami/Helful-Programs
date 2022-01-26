#include <iostream>
#include <cstdlib>

using std::cin; //
using std::cout; //cout display the output
using std::endl; //inserts a new line char and flush the stream
using std::end;

//using namespace std;
// ^ full library

#include <string>
using std::string;
using std::getline;

int main()  {

    double age;
    string NumberOne; // a variable C++ string

    cout << "enter your age: " << endl;  // a prompt for your age

    cin >> NumberOne;
    age = atoi(NumberOne.c_str()); //input numbers using "string buffers"

    cout << "RETURNS 0 if input is A-F:  " << age << endl;

    return 0;


}
