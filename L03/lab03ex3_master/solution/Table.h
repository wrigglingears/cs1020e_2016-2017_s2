//=====================================================================
// FILE: Table.h
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
#include "Group.h"
using namespace std;

class Table {
private:
    string name;
    int capacity;
    Group* group;

public:
    Table();
    Table(string name, int capacity);
    int getCapacity();
    string getName();

    bool addGroup(Group* group);
    bool removeGroup();
    Group* getGroup();
};
