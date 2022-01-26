#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;  //input output stream -also where print functions are.

#include <iomanip>   //for setprecision
using std::fixed;
using std::setprecision;

#include <sstream>   //to allow format control when converting numbers to strings
using std::stringstream;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string>
using std::getline; //get line for input
using std::string;

#include <cstdlib> // for atoi and atof

#include <sstream> //important use check STRING STRING HERE !!



struct someStruct {
    unsigned int total;
};

/*
 * Modifies the struct that exists in the calling function.
 *   Function test() takes a pointer to a struct someStruct variable
 *   so that any modifications to the variable made in the function test()
 *   will be to the variable pointed to.
 *   A pointer contains the address of a variable and is not the variable iteself.
 *   This allows the function test() to modify the variable provided by the
 *   caller of test() rather than a local copy.
 */
void test(struct someStruct *state) {
    state->total = 4;

}

/*
 * Modifies the local copy of the struct, the original
 * in the calling function is not modified.
 * The C compiler will make a copy of the variable provided by the
 * caller of function test2() and so any changes that test2() makes
 * to the argument will be discarded since test2() is working with a
 * copy of the caller's variable and not the actual variable.
 */
int test2(struct someStruct state) {
    state.total = 8;


    return 0;
}

int test3(struct someStruct *state) {
    struct someStruct  stateCopy;
    stateCopy = *state;    // make a local copy of the struct
    stateCopy.total = 12;  // modify the local copy of the struct


    *state = stateCopy;    /* assign the local copy back to the original in the
                              calling function. Assigning by dereferencing pointer. */
    return 0;
}

int main () {
    struct someStruct s;

    /* Set the value then call a function that will change the value. */
    s.total = 5;
    test(&s);
    printf("after test(): s.total = %d\n", s.total);

    /*
     * Set the value then call a function that will change its local copy
     * but not this one.
     */
    s.total = 5;
    test2(s);
    printf("after test2(): s.total = %d\n", s.total);

    /*
     * Call a function that will make a copy, change the copy,
       then put the copy into this one.
     */
    test3(&s);
    printf("after test3(): s.total = %d\n", s.total);

    return 0;
}
