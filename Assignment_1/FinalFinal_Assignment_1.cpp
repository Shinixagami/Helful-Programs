#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <cmath> //round function is in here.

int main() {

    double YourAge, DegreeF, TwoYears, DegreeC, RoundTenthsPlace ;
    string YourName, YourCity, StrngAge, StrngDegreeF;

    cout << "Enter your age: " <<  endl;
    cin >> StrngAge;
    YourAge = atof(StrngAge.c_str()); //converts string into double, double for more precision.

    cin.ignore();

    cout << "Enter Your Name: " <<  endl;
    getline(cin, YourName);

    cout << "Enter the temperature outside in Degrees Fahrenheit: " << endl;
    cin >> StrngDegreeF;
    DegreeF = atof(StrngDegreeF.c_str());   //converts string into double

    cin.ignore();


    cout << "Degree F precise: " << DegreeF << endl;


    cout << "What city are you in right now? " << endl;
    getline(cin, YourCity);

    cout << endl;  //next line

    TwoYears = YourAge + 2; //+2 years

    DegreeC = (DegreeF - 32) * 5/9 ;  // 1 Celsius = 33.8 Fahrenheit

    RoundTenthsPlace = round(DegreeC*10)/10; //rounding 10th places

    cout << endl;  //next line

    cout << YourName << " is " << YourAge <<  " years old now, and will be "  <<  TwoYears << " two years from now. " << endl;
    cout << "It's " << DegreeF << " degrees Fahrenheit in "  << YourCity << " -- that's "  << RoundTenthsPlace << " degrees Celsius. " << endl;

    return 0;

}







