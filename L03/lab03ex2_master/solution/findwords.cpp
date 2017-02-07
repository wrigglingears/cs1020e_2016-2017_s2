//=====================================================================
// FILE: findwords.cpp
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

const int maxSize = 100 + 5;

string puzzle[maxSize];
int row, col, numOfQuery, threshold;

bool match(string query, int headI, int headJ) {
    int queryLength = query.length();
    bool flag;

    // left to right
    if (headJ + queryLength <= col) {
        flag = true;
        for (int j=0; j<queryLength; j++)
            if (query[j] != puzzle[headI][headJ+j]) {
                flag = false;
                break;
            }
        if (flag) return true;

        // top-left ot btm-right
        if (headI + queryLength <= row) {
            flag = true;
            for (int i=0; i<queryLength; i++) 
                if (query[i] != puzzle[headI+i][headJ+i]) {
                    flag = false;
                    break;
                }
            if (flag) return true;
        }

        // btm-left to top-right
        if (headI - queryLength + 1 >= 0) {
            flag = true;
            for (int i=0; i<queryLength; i++) 
                if (query[i] != puzzle[headI-i][headJ+i]) {
                    flag = false;
                    break;
                }
            if (flag) return true;
        }

    }

    // right to left
    if (headJ - queryLength + 1 >= 0) {
        flag = true;
        for (int j=0; j<queryLength; j++)
            if (query[j] != puzzle[headI][headJ-j]) {
                flag = false;
                break;
            }
        if (flag) return true;

        // top-right ot btm-left
        if (headI + queryLength <= row) {
            flag = true;
            for (int i=0; i<queryLength; i++) 
                if (query[i] != puzzle[headI+i][headJ-i]) {
                    flag = false;
                    break;
                }
            if (flag) return true;
        }

        // btm-right to top-left
        if (headI - queryLength + 1 >= 0) {
            flag = true;
            for (int i=0; i<queryLength; i++) 
                if (query[i] != puzzle[headI-i][headJ-i]) {
                    flag = false;
                    break;
                }
            if (flag) return true;
        }

    }

    // top to btm
    if (headI + queryLength <= row) {
        flag = true;
        for (int i=0; i<queryLength; i++) 
            if (query[i] != puzzle[headI+i][headJ]) {
                flag = false;
                break;
            }
        if (flag) return true;
    }

    // btm to top
    if (headI - queryLength + 1 >= 0) {
        flag = true;
        for (int i=0; i<queryLength; i++) 
            if (query[i] != puzzle[headI-i][headJ]) {
                flag = false;
                break;
            }
        if (flag) return true;
    }

    return false;
}

int main()
{
    string query;
    bool found;

    cin >> row >> col;
    threshold = (row > col ? row : col);
    for (int i=0; i<row; i++)
        cin >> puzzle[i];

    cin >> numOfQuery;
    while (numOfQuery > 0) {
        numOfQuery--;
        cin >> query;
        if (query.length() > threshold) {
            cout << "NO" << endl;
            continue;
        }

        found = false;

        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++) 
                if (!found && query[0] == puzzle[i][j]) {
                    if (match(query,i,j)) {
                        cout << "YES" << endl;
                        found = true;
                    }
                }
        if (!found) cout << "NO" << endl;
    }

    return 0;
}
