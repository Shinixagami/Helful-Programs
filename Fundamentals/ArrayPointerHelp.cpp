#include <iostream>
using namespace std;

int main ()
{
    int Capacity = 4;
    int numbers[Capacity] = {1,3,9,39};

    //array is the first address is also the array address
    cout << "Array address: " << numbers << endl;

    cout << endl;

    //& TELLS ADDRESS of array 4
    cout << "address of numbers[4]: "<< &numbers[4] << endl;

    cout << endl;

    //Just an array with data.
    cout << "just an array data: " << numbers[2] << endl;

    cout << endl;

    //using pointer to tell you the address directly
    cout << "using pointer to tell you the address of whole array directly: " << &numbers << endl;

    //using pointer referenced.
    //numbers is the array address.
    //+1 moves it to the next unit and accesses the data.
    cout << "referenced: " <<  *(numbers+1) << endl;  //basically the same as the other except pointer

    cout << endl;

    //The pointer reference is similar to how we access them normally.
    cout << "Typical array layout: " << numbers[2] << endl;

    cout << endl;


    for (int i = 0; i < 2 ; i++)
    {

        cout << "Input the values for Array [ " << i << " ] " << endl;
        cin >> numbers[i];
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "[ " << i << " ] with the data ( " << numbers[i] << " ) is in " << endl;
        cout << "address : " << &numbers[i]<< endl;
        cout << endl;
    }


    cout << endl;
    cout << "------ Changing data using pointer ------ " << endl;


    *(numbers+1) = 88; // changes data of 2nd number in array -remember we start from 0;





    cout << "Data of array 2 : " << numbers[1]<< endl;

    return 0;
}
