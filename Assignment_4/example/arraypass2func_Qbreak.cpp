#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::getline;
using std::string;

#include <algorithm>
using std::swap;
using std::sort;

#include <cstdlib> // for atoi and atof

void printScores(int [], int);
// void printScores(int scoresList[]); 

int getMaxScore(int scoreList[], int size);
int getMinScore(int [], int);
void sortLoHi(int [], int);
void sortHiLo(int [], int);

bool searchScore(int scoresList[], int size, int target);

int main()
{
  const int CAPACITY = 50;
  int scores [CAPACITY] = {}; // init all to 0
  int size;
  
  string buf; // for using the string buffer method
  size = 0;
  while (true)
  {
    cout << "Enter a score or Q to quit: ";
    getline(cin, buf);
    if (buf == "Q" || buf == "q") break;

    if (size != CAPACITY)  // Why check ?
    {
      scores[size] = atoi(buf.c_str());
      size++; 
    }
  }
  
  cout << "List of scores you entered: " << endl;
  for (int i = 0; i < size; i++) // reusing the name "i"
    cout << "scores[" << i << "] = " << scores[i] << endl;
  
  // find the minimum and maximum scores
  int minScore = getMinScore(scores, size);
  int maxScore = getMaxScore(scores, size);
  cout << "Min score = " << minScore << endl;
  cout << "Max score = " << maxScore << endl;
  
  // count matching values
  int nPerfectScores = 0;
  for (int index = 0; index < size; index++)
    if (scores[index] == 100)
      ++nPerfectScores;
  cout << "Number of perfect scores = " << nPerfectScores << endl;
  
  // find any match
  bool hasPerfectScore = searchScore(scores, size, 100);
  // Note: "using std::boolalpha"
  cout << "hasPerfectScore = " << boolalpha << hasPerfectScore << endl;

  // find any match, another way
  hasPerfectScore = false;
  for (int index = 0; index < size && !hasPerfectScore; index++)
    if (scores[index] == 100)
      hasPerfectScore = true;

  // sort the values lo-to-hi
  sortLoHi(scores, size);
  
  cout << "After sorting from low to high:" << endl;
  printScores(scores, size);
	
  // sort the values hi-to-lo
  sortHiLo(scores, size);
  cout << "After sorting from high to low:" << endl;
  printScores(scores, size);

  // Using library function sort
  sort(scores, scores + size);
  cout << "After calling library function sort() " << endl;
  printScores(scores, size);
  
  return 0;
}

/**********************************************************************
* Purpose: retrieve the maximum score from the input score array
* Params:
*   scores (IN) : array of scores
*   count (IN)  : the number of elements in scores array
* Return:  the maximum score in scores array
***********************************************************************/
int getMaxScore(int scores[], int count)
{
  int maxScore = scores[0];
  for (int index = 1; index < count; index++) // starting at index 1
  {
    if (maxScore < scores[index])
      maxScore = scores[index];
  }
  
  return maxScore;
}

int getMinScore(int scores[], int count)
{
  int minScore = scores[0];
  for (int index = 1; index < count; index++) // starting at index 1
  {
    if (scores[index] < minScore)
      minScore = scores[index];
  }
  
  return minScore;
}

void sortLoHi(int scores[], int size)
{
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (scores[i] > scores[j])
           swap(scores[i], scores[j]);
}

void sortHiLo(int scores[], int size)
{
  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (scores[i] < scores[j])
           swap(scores[i], scores[j]);
}


bool searchScore(int scoresList[], int size, int target)
{
  bool found = false;
  for (int index = 0; index < size; index++)
    if (scoresList[index] == target)
    {
      found = true;
      break; // no need to keep looking
    }
	
  return found;
}

void printScores(int scoreArray[], int size)
{
  cout << "Score array contents: " << endl;
  for (int i = 0; i < size; i++)
    cout << "scoreArray[" << i << "] = " << scoreArray[i] << endl;
}