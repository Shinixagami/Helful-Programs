#include <iostream>

using std::cin; //c input
using std::cout; //c output
using std::endl; //end line

#include <string> //string
using std::getline;  //get line

int main () {

    double Kryssa = 15;

    cout << "Kryssa is " << Kryssa << endl << endl;

    int testrun = 0;

    while (Kryssa < 18 ){


         cout << "~~~~~~~~~~~" << endl;
        cout << "she's underage" << endl;

        Kryssa += 1;
        cout << "Kryssa is " << Kryssa << endl;

        testrun += 1;
        cout << "Number of Loops: " <<  testrun << endl << endl ;

    }

    if(Kryssa >= 18) {
        cout << "Kryssa is  NOW LEGAL " << endl;

    }  else if (Kryssa >= 21) {

        cout << "she's an adult" << endl;
    }






return 0;



}
