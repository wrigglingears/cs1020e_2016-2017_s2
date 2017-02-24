//=====================================================================
// FILE: SocialNetwork.h
//=====================================================================

//=====================================================================
// STUDENT NAME: Tan Yi Wei
// MATRIC NO.  : A0140615R
// NUS EMAIL   : e0004525@u.nus.edu
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

    // Add more here if necessary.
};

#endif
