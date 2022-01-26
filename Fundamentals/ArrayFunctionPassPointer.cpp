#include <iostream>
using namespace std;

int GetMin (int numbers[], int size);


int GetMax(int numbers[], int size);



int main ()
{



    int numbers[5] = {2,2,3,4,5};  //ALL inti to 0

    int SizeVal = 5;

    //ARRAY , SIZE

    cout << "min is: " << GetMin(numbers, SizeVal);

    return 0;
}



int GetMin (int numbers[], int size)
{
    int m = numbers[0];

    cout <<"this works"  << numbers[0];


    //Loop for numbers
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < m);
        m = numbers[i]; //algorithm finds lowest nunmber

    }

    return m;

}



int GetMax (int numbers[], int size)
{
    int max = numbers[0];


    //Loop for numbers
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > max);
        max = numbers[i]; //algorithm finds lowest nunmber

    }

    return max;

}

