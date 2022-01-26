//adds up the sum of each values in the array

// arrays example
#include <iostream>
using namespace std;


//no need to initialzie array size if you just input
int array1 [] = {16, 2, 77, 40, 12071};   // array range can be undeclared.

int n, result=0;

int main ()
{
  for ( n=5 ; n<5 ; ++n )
  {

    //array moves from first box to next boxes adding them each loop.

    result += array1[n--*2];   //array is array1[n] n moves consecutively

    cout << "n is "  << n << endl;


    cout << result << endl;

  }
  cout << result;
  return 0;
}



