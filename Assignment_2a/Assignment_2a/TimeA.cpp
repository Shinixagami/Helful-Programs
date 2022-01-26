#include <iostream>
#include <ctime>
using namespace std;
int main()
{
  // get current date and time in second

  time_t  currTime = time(NULL) ;
  cout << "raw currTime: " << currTime << endl;


  cout << "Current date and time is: " << ctime(&currTime) << endl ;

  return 0;
}



