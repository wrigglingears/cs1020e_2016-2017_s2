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
#include "Keyboard.h"
using namespace std;


int main() {

    Keyboard keyboard;

    int N;
    cin >> N;

    while ( N-- > 0 ) {
        string op;
        cin >> op;

        if (op == "left") {
            int k;
            cin >> k;
            keyboard.moveCursorLeft(k);
        }
        else if (op == "right") {
            int k;
            cin >> k;
            keyboard.moveCursorRight(k);
        }
        else if (op == "insert") {
            char letter;
            cin >> letter;
            keyboard.insertChar(letter);
        }
        else if (op == "delete") {
            keyboard.deleteChar();
        }
    }

    keyboard.printLine();
    cout << endl;

    return 0;
}
