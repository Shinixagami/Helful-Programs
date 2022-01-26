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

    int age;
    float temperature;
    string buf; // a variable C++ string

    cout << "enter your city: " << endl;
    getline(cin, buf);  // read multiple words
    cout << "You entered: " << buf << endl;

    cout << "enter your age ";  // a prompt for your age
    //cin >> age;      /enter 5a and observe what happens
    //will not take other data types except int, will return 0

    cin >> buf;
    age = atoi(buf.c_str()); //input numbers using "string buffers"

    cout << "age asdasd " << age << endl;


    cout << "enter current temperature: ";   //a prompt
    cin >> temperature;
    cout << "temperature = " << temperature << endl;



    return 0;


}
