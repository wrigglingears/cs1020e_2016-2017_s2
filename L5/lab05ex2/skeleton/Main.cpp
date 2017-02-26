//=====================================================================
// FILE: Main.cpp
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
#include <cstdlib>
#include "List.h"
using namespace std;


int main() {

    List myList;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        myList.push_back(x);
    }

    myList.reorderList();
    myList.printList();
    cout << endl;

    return 0;
}
