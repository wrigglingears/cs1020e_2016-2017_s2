//=====================================================================
// FILE: Transformation.cpp
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
#include "Matrix.h"

int main() {
    // read input and create the Matrix object
    int size;
    cin >> size;

    Matrix mat(size);
    mat.input();

    // for each operation, process the matrix
    int numOps;
    string operation, type;

    cin >> numOps;

    for (int i = 0; i < numOps; i++) {
        //mat.print();
        cin >> operation >> type;
        mat.operate(operation, type);
    }

    // output the final matrix
    mat.print();

    return 0;
}
