#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstring> // need it for strcpy

#include <cstdlib> // for atoi

const int STUDENTS = 4;    //4 students
const int TESTS = 3;         //3 test

void printScores(int testScores[][TESTS]); // must speficfy 2nd dimension

int main( )
{

  int testScores[STUDENTS][TESTS ];


  // loop to enter all test scores
  string buf; // input buffer
  for (int col = 0; col < TESTS ; col++)
  {

    cout << "\nEnter scores for exam #" << (col + 1) << ' ';
    for (int row = 0; row < STUDENTS; row++)
    {
      cout << " Enter score for student #" << (row + 1) << endl;
      cin >> buf; testScores[row][col] = atoi(buf.c_str( ));
    }
  }

  // output in a nicely-formatted table
  cout << "\nStudent#  exam#1  exam#2  exam#3 \n";
  cout << "--------  ------  ------  ------  \n";
  for (int row = 0; row < STUDENTS; row++)
  {
    cout.width(5);
    cout << (row + 1);
    for (int col = 0; col < TESTS; col++)
    {
      cout.width(8);
      cout << testScores[row][col];
    }
    cout << endl;
  }

  // Calling function to print scores
  printScores(testScores);

  // C string arrays
  string names[9]; // nine names
  char cnames[9][32]; // nine names of up to 31 length (allowing for a null)

  strcpy(cnames[0], "James Doe");
  cout << "cnames[0] = " << cnames[0] << endl;

}

void printScores(int testScores[][TESTS])
{
  cout << "\n----- printScores function: \n";
  cout << "\nStudent#  exam#1  exam#2  exam#3 \n";
  cout << "--------  ------  ------  ------  \n";
  for (int row = 0; row < STUDENTS; row++)
  {
    cout.width(5);
    cout << (row + 1);
    for (int col = 0; col < TESTS; col++)
    {
      cout.width(8);
      cout << testScores[row][col];
    }
    cout << endl;
  }
}
