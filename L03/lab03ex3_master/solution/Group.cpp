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


#include "Group.h"

Group::Group() {
}

Group::Group(string name, int size):
  name(name), size(size) {
}

string Group::getName() {
    return name;
}

int Group::getSize() {
    return size;
}
