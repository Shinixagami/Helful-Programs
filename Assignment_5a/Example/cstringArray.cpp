#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;



#include <string>
using std::getline; //get line for input
using std::string;


struct example
{
    char name[100][30];


};





int main()
{






  char names[12][30];; // nine names of up to 31 length (allowing for a null)
  //string names[9];




  strcpy(names[0], "MILk");  //dest = source;
    //just array and string

  strcpy(names[1], "DAIRY");




  int n = strlen(names[0]); // string length. check character.


  //strcat(names[0], "!");

  //strncpy(names[1], "Alexa Amazon", 30);

  printf("STRING one : %s \n" , names[0]);

  printf("STRING two : %s \n \n" , names[1]);


    //printf("n:  %s \n \n" , n);

    cout <<" n: " <<  n << endl;








  example example;

  strcpy(example.name[0], "DAIRY");


//example.name



  string name;
char *c_string;

getline(cin, name);

c_string = new char[name.length()];

for (int index = 0; index < name.length(); index++){
    c_string[index] = name[index];
}
c_string[name.length()] = '\0';//add the null terminator at the end of
                              // the char array















  printf("STRING struct ONE: %s \n \n" , example.name[0]);







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
