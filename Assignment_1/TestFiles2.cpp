#include <iostream>
#include <cstdlib>   //using namespace std; //using the whole library

using std::cin;
using std::cout;
using std::endl;

#include <cmath>

#include <string>
using std::string;
using std::getline;

int main()  {

    double YourAge, DegreeF, TwoYears, DegreeC, RoundC ;
    string YourName, YourCity;

    cout << "Enter your age: " <<  endl;
    cin >> YourAge;

    cin.ignore(256, '\n');

    cout << "Enter your Full Name: " <<  endl;
    getline(cin, YourName);
    cout << "full name is: " << YourName << endl;


    cout << "Enter the temperature outside in Degrees Fahrenheit: " << endl;
    cin >> DegreeF;

    cin.ignore(256, '\n');

    cout << "What city are you in right now? " << endl;
    std::getline(cin, YourCity);
    cout << "full city is: " << YourCity << endl;



    cout << endl;  //next line
    //cout<< "Hello there " << YourAge << endl;
    //cout<< "Hello there " << YourName << endl;
    //cout<< "Hello there " << DegreeF << endl;
    //cout<< "Hello there " << YourCity << endl;

     TwoYears = YourAge + 2;
     cout<< "two years later I will be:  " << TwoYears << endl;

     DegreeC = (DegreeF - 32) * 5/9 ;  // 1 Celsius = 33.8 Fahrenheit
     cout<< "In degrees Celsius : " << DegreeC << endl;

     cout << endl; // next line

     cout<< "Rounded using Round Func. : " << round(DegreeC) << endl;   //built in round function

     RoundC = round(DegreeC*10)/10;    //rounded using formula for tenth  place
     cout << "Rounded ones place: " << RoundC << endl;

     cout << endl;  //next line


    cout << YourName << " is " << YourAge <<  " years old now, and will be "  <<  TwoYears << " two years from now. " << endl;
    cout << "It's " << DegreeF << " degrees Fahrenheit in "  << YourCity << " that's "  << DegreeC << " degrees Celsius. " << endl;

    //cout << "Hello person!" << endl;
    //cout << "What is your name?" << endl;
    //cin>> YourName;
    //cout<< "Hello there "<< YourName << endl;


    return 0;
}







