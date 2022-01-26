#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdlib.h>
#include <string.h>




 int main()

 {

    char a[1000] = "hello MY NAME nigga";
    char b[1000] = "a";


    char *s;

    // null is similar to npos.
    //*output is a pointer telling it something
    char *output;


    //strstr will return 0 if the string a, contains, string b
    output = strstr (a ,b);

    if(output != NULL)
        {

        printf("String Found");

        }






    return 0;
 }
