#include <iostream>
using namespace std;

int main ()
{
    int Capacity = 100;
    int numbers[Capacity] = {};

    /*

    //array is the first address is also the array address
    cout << numbers << endl;

    //check
    cout << &numbers[0] << endl; //First array.


    //checking which part of array were on.
    cout << numbers[2] << endl;

    //using pointer referenced.
    cout << *(numbers+2) << endl;  //basically the same as the other except pointeR

    */


    for (int i = 0; i < 3 ; i++)
    {

        cout << "number: ";
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cout << *(numbers+i)<< "  ";
    }






    return 0;
}
