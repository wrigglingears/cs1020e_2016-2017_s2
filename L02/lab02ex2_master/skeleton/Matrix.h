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
using namespace std;

class Matrix {
    private:
        void rotate(int degrees);
        void reflectX();
        void reflectY();

        // add other necessary procedures

    public:
        // constructor

        void operate(string operation, string type);

        // add other necessary procedures

};
