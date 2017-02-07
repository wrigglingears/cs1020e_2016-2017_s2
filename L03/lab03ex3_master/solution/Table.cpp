//=====================================================================
// FILE: Table.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================


#include "Table.h"

Table::Table() {
    this->group = NULL;
}

Table::Table(string name, int capacity):
  name(name), capacity(capacity) {
    this->group = NULL;
}

int Table::getCapacity() {
    return capacity;
}

string Table::getName() {
    return name;
}

bool Table::addGroup(Group* group) {
    if (group->getSize() > capacity || this->group != NULL) {
        return false;
    }
    this->group = group;
    return true;
}

bool Table::removeGroup() {
    if (group == NULL) {
        return false;
    }
    group = NULL;
    return true;
}

Group* Table::getGroup() {
    return group;
}
