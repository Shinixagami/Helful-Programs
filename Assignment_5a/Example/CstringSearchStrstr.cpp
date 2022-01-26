#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdlib.h>
#include <string.h>




 int main()

 {



    char buff[1000];



    printf("INPUT : ");

    cin.getline(buff, 1000);

     printf("\n");



    printf(" %s ", buff);







    char *s;




     s = strstr(buff, "pussy hi");      // search for string "hassasin" in buff

     if (s != NULL)                     // if successful then s now points at "hassasin"
     {
         printf("Found string at index = %d\n", s - buff);
     }                                  // index of "hassasin" in buff can be found by pointer subtraction
     else
     {
         printf("String not found\n");  // `strstr` returns NULL if search string not found
     }







    return 0;
 }
