#include <iostream>
using namespace std;

int main() {
  int arr[] = {10,20,30,40,50,60};
  int arrSize = *(&arr + 1) - arr;
  cout << "The length of the array is: " << arrSize;
  return 0;


}
