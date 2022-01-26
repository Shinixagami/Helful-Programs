#include <string.h>
#include <iostream>
using namespace std;

#define NO_OF_TEST 1

struct studentType {
    string studentID;
    string firstName;
    string lastName;
    string subjectName;
    string courseGrade;
    int arrayMarks[4];
    double avgMarks;
};





//gets input of multiple variables, can return specific tytpes

studentType input() {
    studentType newStudent;
    cout << "\nPlease enter student information:\n";

    cout << "\nFirst Name: ";
    cin >> newStudent.firstName;

    cout << "\nLast Name: ";
    cin >> newStudent.lastName;

    cout << "\nStudent ID: ";
    cin >> newStudent.studentID;

    cout << "\nSubject Name: ";
    cin >> newStudent.subjectName;

    for (int i = 0; i < NO_OF_TEST; i++) {
        cout << "\nTest " << i+1 << " mark: ";
        cin >> newStudent.arrayMarks[i];
    }

    return newStudent;  //this is your answer.
}





int main() {

    cout << "ran on int main () " << endl;
    studentType s;


    s = input();

    cout << endl << "Collected the details of " << s.firstName << endl;
    cout <<" student last name is " << s.lastName << endl;



     //each time Call Input is used, the data is overwritten. You have to store it.
     s = input();

     cout << endl << "Collected the details of " << s.firstName << endl;
     cout <<" student last name is " << s.lastName << endl;


/*

     storageName1 = s.firstName
     storageAge1   =
     storageCity1 =
     storageGpa1 =
     storageMajor1  =

     storageName2 = s.firstName
     storageAge2   =
     storageCity2 =
     storageGpa2 =
     storageMajor2  =

     storageName3 = s.firstName
     storageAge3   =
     storageCity3 =
     storageGpa3 =
     storageMajor3  =

*/


    cout <<" student last name is " << s.lastName << endl;






    return 0;
}
