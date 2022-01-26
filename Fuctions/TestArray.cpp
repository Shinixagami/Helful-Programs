// C++ Program to display marks of 5 students

#include <iostream>
using namespace std;

// declare function to display marks
// take a 1d array as parameter
void display(int m[2]) {
    cout << "Displaying marks: " << endl;

    // display array elements
    for (int i = 0; i < 2; ++i) {

        cout << "Student " << i + 1 << ": " << m[i] << endl << endl;
    }

    double one, two;

    cout << "It's working " << endl;

    cout << m[1] + 100 << endl;



}

int main() {

    // declare and initialize an array
    int marks[] = {88, 50};

    // call display function
    // pass array as argument
    display(marks);


    return 0;
}
