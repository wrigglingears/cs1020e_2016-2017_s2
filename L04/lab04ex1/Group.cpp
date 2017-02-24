//=====================================================================
// FILE: Group.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tan Yi Wei
// MATRIC NO.  : A0140615R
// NUS EMAIL   : e0004525@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include <cstdlib>
#include "Group.h"

// Add your code here.

Group::Group(int id, string name)
: id(id), name(name){
}

int Group::getId(){
	return id;
}

string Group::getName(){
	return name;
}

void Group::addMember(Person *p){
	members.push_back(p);
}

void Group::delMember(string name){
	for (int i = 0; i < (int)members.size(); ++i){
		if (members[i]->getName() == name){
			members[i] = members.back();
			members.pop_back();
		}
	}
}

int Group::getNumOfMembers(){
	return members.size();
}

Person* Group::getMember(int i){
	return members[i];
}
