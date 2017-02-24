//=====================================================================
// FILE: Person.cpp
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
#include "Person.h"

// Add your code here.

Person::Person(string name)
: name(name){
}

string Person::getName(){
	return name;
}

void Person::joinGroup(int grp){
	groups.push_back(grp);
}

void Person::quitGroup(int grp){
	for(int i = 0; i < (int)groups.size(); ++i){
		if (groups[i] == grp){
			groups.erase(groups.begin()+i);
		}
	}
}

int Person::getNumOfGroups(){
	return groups.size();
}

int Person::getGroup(int i){
	return groups[i];
}

bool Person::know(Person *p2){
	for (int i = 0; i < (int)groups.size(); ++i){
		for (int j = 0; j < (int)p2->getNumOfGroups(); ++j){
			if (groups[i] == p2->getGroup(j)){
				return true;
			}
		}
	}
	return false;
}
