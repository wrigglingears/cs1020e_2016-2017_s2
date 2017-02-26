//=====================================================================
// FILE: List.cpp
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
#include <string>
#include <cstdlib>
#include "List.h"
using namespace std;


List::List() {
    _head = new Node(-1);  // Add a dummy head node.
}


void List::push_back(int x) {

    // Add your code here.

}


void List::reorderList() {
    if ( _head->next == NULL || _head->next->next == NULL) return;

    // Add your code here.

}


void List::printList() {
    for (Node *n = _head->next; n != NULL; n = n->next) {
        cout << n->value << " ";
    }
}
