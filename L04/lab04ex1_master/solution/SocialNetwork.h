//=====================================================================
// FILE: SocialNetwork.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef social_network_h
#define social_network_h

#include <string>
#include <vector>
#include "Person.h"
#include "Group.h"
using namespace std;

class SocialNetwork{
private:
    vector <Group *> groups;
    vector <Person *> persons;

public:
    SocialNetwork();
    
    Person * addPerson(string name);
    Group * addGroup (string name);
    Person * findPerson (string name);
    Group * findGroup (string name);
    void createjoin (string, string);
    void quit (string, string);
    string answerQuery1();
    string answerQuery2();
};

#endif
