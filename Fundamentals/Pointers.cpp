#include <iostream>
using namespace std;


int main()
{
     int n = 5; // typical variable


     cout << n << endl; //typical print

     //using pointer to print out data storage USING &

     cout << &n << endl; //turning the n value into pointer using &


     //putting * next to a data type will print out pointer memory location.
     int* pointerPrint = &n;  //making it a variable using* or pointer



     cout << pointerPrint << endl;  //printing out using variable






     //putting a * next to a variable pointer prints out its actual value
     cout << *pointerPrint << endl;




    //its a on and off switch with *






}
