//=====================================================================
// FILE: Person.cpp
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
#include <cstdlib>
#include "Person.h"

Person::Person(){
    name = "";
    groups.clear();
}

Person::Person(string name){
    this->name = name;
    groups.clear();
}

string Person::getName(){
    return this->name;
}

void Person::joinGroup(int grp){
    groups.push_back(grp);
}

void Person::quitGroup(int grp){
    int i;
    for (i=0; i<groups.size(); i++)
        if (groups[i] == grp) break;
    groups.erase(groups.begin()+i);
}

int Person::getNumOfGroups(){
    return groups.size();
}

int Person::getGroup(int i){
    return groups[i];
}

bool Person::know(Person *p2){
    for (int i=0; i<groups.size(); i++)
        for (int j=0; j<p2->getNumOfGroups(); j++)
            if (groups[i] == p2->getGroup(j)) return true;
    return false;
}

bool Person::knowOtherThan(Person *p2, int grp){
    for (int i=0; i<groups.size(); i++)
        for (int j=0; j<p2->getNumOfGroups(); j++)
            if (groups[i] != grp && groups[i] == p2->getGroup(j)) return true;
    return false;
}
        
     
