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


// Returns true iff sub is a substring in str starting from str[start_pos].
bool isSubstr(char sub[], char str[], int start_pos) {
    int i = 0, j = start_pos;
    int subLen = stringLength(sub);
    int strLen = stringLength(str);
    while (i < subLen && j < strLen) {
        if (sub[i] != str[j]) { 
            return false; 
        } else {
            i++; j++;
        }
    }
    return (i == subLen);
}


// Removes k characters from str starting from str[start_pos].
// The remaining right section of the string is shifted left
// to fill in the holes.
void removeChars(char str[], int start_pos, int k) {
    int strLen = stringLength(str);
    for (int i = start_pos + k; i <= strLen; i++) {
        str[i - k] = str[i];
    }
}


void removeSubstr(char sub[], char str[]) {
    int subLen = stringLength(sub);
    int strLen = stringLength(str);
    int i = 0;

    while (i < strLen) {
        if (isSubstr(sub, str, i)) {
            removeChars(str, i, subLen);
            strLen -= subLen;
        } else {
            i++;
        }
    }
}


const int maxSize = 101;

int main() 
{
    char str[maxSize], sub[maxSize];

    cin >> str;
    cin >> sub;

    // TODO: Remove from str all occurrences of sub.
    removeSubstr(sub, str);

    cout << "\"" << str << "\"" << endl;

    return 0;
}
