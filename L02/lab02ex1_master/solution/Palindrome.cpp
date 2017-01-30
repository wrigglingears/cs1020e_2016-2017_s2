//=====================================================================
// FILE: Palindrome.cpp
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

using namespace std;


// Returns the reverse of the input integer.
// The input must be positive and at most 9 digits long.

int reverseInt(int x) 
{
    int reverse = 0;

    while (x > 0)
    {
        reverse = 10 * reverse + x % 10;
        x = x / 10;
    }

    return reverse;
}



int main() 
{
    int data;
    cin >> data;

    int reverse = reverseInt(data);
    cout << reverse << endl;
    cout << ((reverse == data)? "Yes" : "No") << endl;

    return 0;
}
