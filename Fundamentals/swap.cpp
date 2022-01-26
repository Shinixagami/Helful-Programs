#include <algorithm>
using std::swap;  // this is whats used for swap

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main( )
{
  int a = 100;
  int b = 200;
  cout << "a=" << a << ", b=" << b << endl;
  swap(a, b);
  cout << "But now, a=" << a << ", b=" << b << endl;

  string h = "Hello";
  string g = "Goodbye";
  cout << "\ng=" << g << ", h=" << h << endl;
  swap(g, h);
  cout << "But now, g=" << g << ", h=" << h << endl;

  double x = 123.345;
  double y = x / 2;
  cout << "\nx=" << x << ", y=" << y << endl;
  swap(x, y);
  cout << "But now, x=" << x << ", y=" << y << endl;
}
