//=====================================================================
// FILE: Group.h
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

class Group {
private:
    string name;
    int size;

public:
    Group();
    Group(string name, int size);
    string getName();
    int getSize();
};
