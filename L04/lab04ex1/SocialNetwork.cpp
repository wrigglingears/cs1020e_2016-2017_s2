//=====================================================================
// FILE: SocialNetwork.cpp
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
#include "SocialNetwork.h"

// Add your code here.

SocialNetwork::SocialNetwork(){
}

Person* SocialNetwork::addPerson(string name){
	persons.push_back(new Person(name));
	return persons.back();
}

Group* SocialNetwork::addGroup(string name){
	groups.push_back(new Group(groups.size(), name));
	return groups.back();
}

Person* SocialNetwork::findPerson(string name){
	for (int i = 0; i < (int)persons.size(); ++i){
		if (persons[i]->getName() == name){
			return persons[i];
		}
	}
	return NULL;
}

Group* SocialNetwork::findGroup(string name){
	for (int i = 0; i < (int)groups.size(); ++i){
		if (groups[i]->getName() == name){
			return groups[i];
		}
	}
	return NULL;
}

void SocialNetwork::createjoin(string person, string group){
	Group* finalgroup;
	Person* finalperson;
	int counter = 0;
	for (int i = 0; i < (int)groups.size(); ++i){
		if (groups[i]->getName() == group){
			finalgroup = groups[i];
			counter = 1;
			break;
		}
	}
	if (counter == 0){
		finalgroup = addGroup(group);
	}
	counter = 0;
	for (int i = 0; i < (int)persons.size(); ++i){
		if (persons[i]->getName() == person){
			finalperson = persons[i];
			counter = 1;
			break;
		}
	}
	if (counter == 0){
		finalperson = addPerson(person);
	}
	finalgroup->addMember(finalperson);
	finalperson->joinGroup(finalgroup->getId());
}

void SocialNetwork::quit(string person, string group){
	findPerson(person)->quitGroup(findGroup(group)->getId());
	findGroup(group)->delMember(person);
}

string SocialNetwork::answerQuery1(){
	Group *final;
	final = groups[0];
	for (int i = 0; i < (int)groups.size(); ++i){
		if (groups[i]->getNumOfMembers() > final->getNumOfMembers() || 
			(groups[i]->getNumOfMembers() == final->getNumOfMembers() && 
			groups[i]->getName() < final->getName())){
			final = groups[i];
		}
	}
	return final->getName();
}

string SocialNetwork::answerQuery2(){
	Person *final;
	int finalNumber = 0;
	final = persons[0];
	for (int i = 0; i < (int)persons.size(); ++i){
		int numberOfPeople = 0;
		for (int j = 0; j < (int)persons.size(); ++j){
			if (persons[i]->know(persons[j])){
				++numberOfPeople;
			}
		}
		if ( numberOfPeople > finalNumber ||
			(numberOfPeople == finalNumber && 
			persons[i]->getName() < final->getName())){
			final = persons[i];
			finalNumber = numberOfPeople;
		}
	}
	return final->getName();
}
