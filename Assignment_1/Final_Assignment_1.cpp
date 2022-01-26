#include <iostream>
#include <cstdlib> //using namespace std; //using the whole library

using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <cmath>

int main() {

    double YourAge, DegreeF, TwoYears, DegreeC, RoundTenthsPlace ;
    string YourName, YourCity;

    cout << "Enter your age: " <<  endl;
    cin >> YourAge;

    cin.ignore();

    cout << "Enter Your Name: " <<  endl;
    getline(cin, YourName);

    cout << "full name is: " << YourName << endl;

    cout << "Enter the temperature outside in Degrees Fahrenheit: " << endl;
    cin >> DegreeF;

    cin.ignore();

    cout << "What city are you in right now? " << endl;
    getline(cin, YourCity);

    cout << "full city is: " << YourCity << endl;
    cout << endl;  //next line

    TwoYears = YourAge + 2;

    //cout<< "two years later I will be:  " << TwoYears << endl;

    DegreeC = (DegreeF - 32) * 5/9 ;  // 1 Celsius = 33.8 Fahrenheit
    //cout<< "In degrees Celsius :" << DegreeC << endl;

    RoundTenthsPlace = round(DegreeC*10)/10;


    cout << "Degrees in tenths place: " << RoundTenthsPlace << endl;

    cout << endl;  //next line

    cout << YourName << " is " << YourAge <<  " years old now, and will be "  <<  TwoYears << " two years from now. " << endl;
    cout << "It's " << DegreeF << " degrees Fahrenheit in "  << YourCity << " that's "  << RoundTenthsPlace << " degrees Celsius. " << endl;

    return 0;
}







