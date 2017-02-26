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
    Node *newNode = new Node(x);
    Node *tail = _head;
    while (tail->next != NULL) tail = tail->next;
    tail->next = newNode;
}


void List::reorderList() {
    if ( _head == NULL || _head->next == NULL || _head->next->next == NULL) return;

    //find the middle of the list, and split into two lists.
    Node *p = _head, *q = _head;
    while (p && q && q->next && q->next->next) {
        p = p->next;
        q = q->next->next;
    }

    Node *mid = p->next;
    p->next = NULL;
    p = _head;

    //reverse from the middle to the end
    // 1 2 3 4 5 6 -> 1 2 3 6 5 4 
    Node *q1 = mid, *q2, *q3;
    if (mid->next) {
        q1 = mid;
        q2 = mid->next;
        while (q2) {
            q3 = q2->next;
            q2->next = q1;
            q1 = q2;
            q2 = q3;

        }
        mid->next = NULL;
    }
    q = q1;

    //merge these two list
    // 1 2 3 6 5 4 -> 1 6 2 5 3 4
    Node *s = p;
    p = p->next;
    while (p && q) {
        s->next = p;
        s = s->next;
        p = p->next;

        s->next = q;
        s = s->next;
        q = q->next;
    }
    if (p) {
        s->next = p;
    }
    if (q) {
        s->next = q;
    }
}


void List::printList() {
    for (Node *n = _head->next; n != NULL; n = n->next) {
        cout << n->value << " ";
    }
}
