//=====================================================================       
// FILE: HelloByeBye.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <iostream>
#include <string>

using namespace std;


int main() 
{
    string name;

    cout << "What is your name? ";
    getline(cin, name);

    //=======================
    // WRITE YOUR CODE BELOW.
    //=======================

    int numTimes;

    cout << "Hello how many times? ";
    cin >> numTimes;

    for (int i = 1; i <= numTimes; i++)
    {
        cout << i << ": Hello, " << name << "." << endl;
    }

    //=======================

    cout << "Bye-bye!" << endl;

    return 0;
}
