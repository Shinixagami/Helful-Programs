#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

struct TimeOfDay
{
  int hour;
  int minute;
  int second;
};

int main( )
{
  int age;
  double gpa;
  char grade;
  bool isEnrolledIn165;
  string name;
  TimeOfDay classStart;
  int scores[100];
 
  cout << "The memory location of \"int age\": " << &age << endl;
  cout << "The memory location of \"double gpa\": " << &gpa << endl;
  cout << "The memory location of \"char grade\": " << &grade << endl;
  cout << "The memory location of \"bool isEnrolledIn165\": " << &isEnrolledIn165 << endl;
  cout << "The memory location of \"string name\": " << &name << endl;
  cout << "The memory location of \"TimeOfDay classStart\": " << &classStart << endl;
  cout << "The memory location of \"int scores[100]\": " << &scores << endl;
  cout << "The memory location of \"scores[5]\": " << &scores[5] << endl;
}