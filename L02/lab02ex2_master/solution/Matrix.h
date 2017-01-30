//=====================================================================
// FILE: Matrix.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include <string>
#define _maxSize 100
using namespace std;


class Matrix {
    private:
        int _size;
        int _elem[_maxSize][_maxSize];

        void rotate(int degrees);
        void reflectX();
        void reflectY();

        // add other necessary procedures
    
    public:
        // constructor
        Matrix(int size);

        void operate(string operation, string type);
        void print();
        void input();
};
