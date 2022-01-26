#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

int main()
{

  char names[9][32]; // nine names of up to 31 length (allowing for a null)
  //string names[9];

  strcpy (names[0], "James Doe");
  int n = strlen(names[0]);
  strcat(names[0], "!");

  strncpy(names[1], "Alexa Amazon", 30);
  /*
  Copy characters from string
  Copies the first num characters of source to destination.
  If the end of the source C string (which is signaled by a null-character)
  is found before num characters have been copied, destination is
  padded with zeros until a total of num characters have been written to it.
  No null-character is implicitly appended at the end of destination
  if source is longer than num. Thus, in this case, destination shall not be considered a null terminated C string (reading it as such would overflow).
  destination and source shall not overlap (see memmove for a safer alternative when overlapping).
   */

   for (int i = 0; i < 2; i++)
	   cout << names[i] << endl;

  return 0;
}
