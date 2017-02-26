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
#include "BinarySearchTree.h"
using namespace std;


int main() {

    BinarySearchTree tree;

    string operation;
    int N, x;
    cin >> N;

    while (N-- > 0) {
        cin >> operation;

        if (operation == "INSERT") {
            cin >> x;
            tree.insert(x);
        } 
        else if (operation == "FIND") {
            cin >> x;
            cout << tree.findDepth(x) << endl;
        }
        else if (operation == "FINDMIN") {
            cout << tree.findMin() << endl;
        }
        else if (operation == "FINDMAX") {
            cout << tree.findMax() << endl;
        }
    }

    return 0;
}
