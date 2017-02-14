//=====================================================================
// FILE: DataStructure.cpp
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
#include "DataStructure.h"
using namespace std;

DataStructure::DataStructure() {}

DataStructure::DataStructure(int ID) {
    _id = ID;
    next = this;
    prev = this;
}

DataStructure::DataStructure(int ID,DataStructure* Prev,DataStructure* Next) {
    _id = ID;
    next = Next;
    prev = Prev;
}

void DataStructure::insert(int ID) {
    DataStructure *tmp = new DataStructure(ID,this,next);
    next->prev = tmp;
    next = tmp;
}

DataStructure* DataStructure::del() {
    DataStructure* tmp = next;
    prev->next = next;
    next->prev = prev;
    delete this;
    return tmp;
}

int DataStructure::getID() {
    return _id;
}

DataStructure* DataStructure::move() {
    return next;
}
