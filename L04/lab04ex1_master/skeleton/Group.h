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

#ifndef group_h
#define group_h

#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Group{
private:
    int id;  // assign a unique id to each group.
    string name;
    vector <Person *> members;

public:
    Group();
    Group(int id, string name);
    
    int getId();
    string getName();
    void addMember(Person *p);
    void delMember(string name);
    int getNumOfMembers();
    Person * getMember(int i);
    Person * getSocialCapital();

    // Add more here if necessary.
};

#endif
