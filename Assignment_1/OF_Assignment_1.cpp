#include <iostream>
#include <cstdlib>

//using namespace std; //using the whole library

using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

int main() {

    double YourAge, DegreeF, TwoYears, DegreeC ;
    string YourName, YourCity;

    string YourName2 ;


    cout << "ENTER YOUR FULL NAME: " <<  endl;
    getline(cin, YourName2);
    cout << "full name is: " << YourName2 << endl;

    cout << "Enter your age: " <<  endl;
    cin >> YourAge;

    cout << "Enter your name: " <<  endl;

    cin >> YourName;



    cout << "Enter the temperature outside in Degrees Fahrenheit: " << endl;
    cin >> DegreeF;

    cout << "What city are you in right now? " << endl;
    cin >> YourCity;

    cout << endl;  //next line

    //cout<< "Hello there " << YourAge << endl;
    //cout<< "Hello there " << YourName << endl;
    //cout<< "Hello there " << DegreeF << endl;
    //cout<< "Hello there " << YourCity << endl;

    TwoYears = YourAge + 2;
    cout<< "two years later I will be:  " << TwoYears << endl;

    DegreeC = (DegreeF - 32) * 5/9 ;  // 1 Celsius = 33.8 Fahrenheit
    cout<< "In degrees Celsius :" << DegreeC << endl;


    cout << endl;  //next line



    cout << YourName << " is " << YourAge <<  " years old now, and will be "  <<  TwoYears << " two years from now. " << endl;

    cout << "It's " << DegreeF << " degrees Fahrenheit in "  << YourCity << " that's "  << DegreeC << " degrees Celsius. " << endl;



    //cout << "Hello person!" << endl;
    //cout << "What is your name?" << endl;
    //cin>> YourName;
    //cout<< "Hello there "<< YourName << endl;


    return 0;

}







