//=====================================================================
// FILE: SocialNetwork.cpp
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
#include "SocialNetwork.h"

SocialNetwork::SocialNetwork(){
    persons.clear();
    groups.clear();
}

Person * SocialNetwork::addPerson(string name){
    Person * p = new Person(name);
    persons.push_back(p);
    return p;
}

Group * SocialNetwork::addGroup(string name){
    Group * g = new Group(groups.size(), name);
    groups.push_back(g);
    return g;
}

Person* SocialNetwork::findPerson(string name){
    for (int i=0; i<persons.size(); i++)
        if (persons[i]->getName() == name) return persons[i];
    return addPerson(name);
}

Group * SocialNetwork::findGroup(string name){
    for (int i=0; i<groups.size(); i++)
        if (groups[i]->getName() == name) return groups[i];
    return addGroup (name);
}

void SocialNetwork::createjoin(string prs, string grp){
    Person * p = findPerson(prs);
    Group * g = findGroup(grp);
    p->joinGroup(g->getId());
    g->addMember(p);
}

void SocialNetwork::quit(string prs, string grp){
    Person * p = findPerson(prs);
    Group * g = findGroup(grp);
    p->quitGroup(g->getId());
    g->delMember(prs);
}

string SocialNetwork::answerQuery1(){
    int k=0;
    for (int i=1; i<groups.size(); i++)
        if (groups[i]->getNumOfMembers() > groups[k]->getNumOfMembers()
            || groups[i]->getNumOfMembers() == groups[k]->getNumOfMembers()
            && groups[i]->getName() < groups[k]->getName()) k = i;
    return groups[k]->getName();
}

string SocialNetwork::answerQuery2(){
    int k = -1;
    int max_know = -1;
    for (int i=0; i<persons.size(); i++){
        int num_know = 0;
        for (int j=0; j<persons.size(); j++){
            if (i==j) continue;
            if (persons[i]->know(persons[j])) num_know++;
        }
        if (num_know > max_know || num_know == max_know && persons[i]->getName() <persons[k]->getName()){
            max_know = num_know;
            k = i;
        }
    }
    return persons[k]->getName();    
}
