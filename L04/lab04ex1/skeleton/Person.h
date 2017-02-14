//=====================================================================
// FILE: Person.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef person_h
#define person_h

#include <string>
#include <vector>
using namespace std;

class Person{
private:
    string name;
    vector <int> groups;  // contain the group id's of the person's groups.

public:
    Person();
    Person(string name);

    string getName();
    void joinGroup(int grp);
    void quitGroup(int grp);
    int getNumOfGroups();
    int getGroup(int i);
    bool know(Person *p2);
    bool knowOtherThan(Person *p2, int grp);

    // Add more here if necessary.
};

#endif
