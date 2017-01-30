//=====================================================================
// FILE: Matrix.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include "Matrix.h"
#include <iostream>

// add other necessary procedures

void Matrix::rotate(int degrees) {
    // transform the matrix by rotating the matrix 
    int tmp[_maxSize][_maxSize];

    for (int times = 0; times < degrees/90; times++) {
        for (int i = 0; i < _size; i++) 
            for (int j = 0; j < _size; j++)
                tmp[i][j] = _elem[i][j];

        for (int i = 0; i < _size; i++)
            for (int j = 0; j < _size; j++)
                _elem[i][j] = tmp[_size - j - 1][i];
    }
}


void Matrix::reflectX() {
    // transform the matrix by reflecting it about the x-axis
    int tmp[_maxSize][_maxSize];

    for (int i = 0; i < _size; i++) 
        for (int j = 0; j < _size; j++)
            tmp[i][j] = _elem[i][j];

    for (int i = 0; i < _size; i++)
        for (int j = 0; j < _size; j++)
            _elem[i][j] = tmp[_size - i - 1][j];
}


void Matrix::reflectY() {
    // transform the matrix by reflecting it about the y-axis
    int tmp[_maxSize][_maxSize];

    for (int i = 0; i < _size; i++) 
        for (int j = 0; j < _size; j++)
            tmp[i][j] = _elem[i][j];

    for (int i = 0; i < _size; i++)
        for (int j = 0; j < _size; j++)
            _elem[i][j] = tmp[i][_size - j - 1];
}


void Matrix::operate(string operation, string type) {
    // transform matrix according to input operation and type

    if (operation == "Rotate") {
        if (type == "90") 
            rotate(90);
        else if (type == "180") 
            rotate(180);
        else if (type == "270") 
            rotate(270);
        
    } else if (operation == "Reflect") {
        if (type == "x") 
            reflectX();
        else 
            reflectY();
    }
}


Matrix::Matrix(int size): _size(size) {
}


void Matrix::print() {
    for (int i = 0; i < _size; i++) {
        cout << _elem[i][0]; 
        for (int j = 1; j < _size; j++)
            cout << " " << _elem[i][j];
        cout << endl;
    }
}


void Matrix::input() {
    for (int i = 0; i < _size; i++) { 
        for (int j = 0; j < _size; j++)
            cin >> _elem[i][j];
    }
}
