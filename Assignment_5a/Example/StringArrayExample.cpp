#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;



#include <string>
using std::getline; //get line for input
using std::string;


struct format
{
    // 100 arrays, 30 characters
    char name[100][30];

};




int main()
{
  format example; //struct with char name[100][30];

  strcpy(example.name[0], "DAIRY");


  //turn c++ into c string / char.

    string name;

    char *c_string; // points to c_string

    cout << "please input the string : ";
    getline(cin, name);


    cout << endl;


  //points here    //new char [name length]
    c_string = new char[name.length()];

            cout << "name.length : " << name.length() << endl; //HOW to use string.length

    for (int index = 0; index < name.length(); index++)
        {
        c_string[index] = name[index];
        }

    c_string[name.length()] = '\0';//add the null terminator at the end of
                                  // the char array




    strcpy(example.name[0], c_string ); //COPIES NEW DATA INSIDE.

    printf("STRING struct ONE: %s \n \n" , example.name[0]);

    printf("STRING struct TWO: %s \n \n" , example.name[2]);




  return 0;
}
