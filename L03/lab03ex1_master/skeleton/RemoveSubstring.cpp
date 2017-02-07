//=====================================================================
// FILE: RemoveSubstring.cpp
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


// Returns the length of the null-terminated string s.
int stringLength(char s[]) {
    if (s == NULL) {
        return 0;
    } else {
        int i = 0;
        while (s[i] != '\0') { i++; }
        return i;
    }
}


const int maxSize = 101;

int main() 
{
    char str[maxSize], sub[maxSize];

    cin >> str;
    cin >> sub;

    // TODO: Remove from str all occurrences of sub.

    cout << "\"" << str << "\"" << endl;

    return 0;
}
