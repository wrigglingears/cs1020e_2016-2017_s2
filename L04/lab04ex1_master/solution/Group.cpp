//=====================================================================
// FILE: Group.cpp
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
#include "Group.h"

Group::Group(){
    name = "";
    members.clear();
}

Group::Group(int id, string name){
    this->id = id;
    this->name = name;
    members.clear();
}

int Group::getId(){
    return id;
}

string Group::getName(){
    return name;
}

void Group::addMember (Person *p){
    members.push_back(p);
}

void Group::delMember (string name){
    int i;
    for (i=0; i<members.size(); i++)
        if (members[i]->getName() == name) break;
    members.erase(members.begin()+i);
}

int Group::getNumOfMembers(){
    return members.size();
}

Person * Group::getMember(int i){
    return members[i];
}

Person * Group::getSocialCapital(){
    int k = -1;
    int max_know = -1;
    for (int i=0; i<members.size(); i++){
        int num_know = 0;
        for (int j=0; j<members.size(); j++){
            if (i==j) continue;
            if (members[i]->knowOtherThan(members[j], id)) num_know++;
        }
        if (num_know > max_know || num_know == max_know && members[i]->getName()<members[k]->getName()){
            max_know = num_know;
            k = i;
        }
        //cout<<members[i]->getName()<<' '<<num_know<<endl;
    }
    return members[k];       
}
