//=====================================================================
// FILE: Keyboard.cpp
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
#include "Keyboard.h"
using namespace std;


Keyboard::Keyboard() {
    Node *hnode = new Node;
    Node *tnode = new Node;
    hnode->prev = NULL;
    hnode->next = tnode;
    tnode->prev = hnode;
    tnode->next = NULL;
    _head = hnode;
    _tail = tnode;
    _cursor = tnode;
}

void Keyboard::moveCursorLeft(int k) {
    for (int i = 0; i < k; i++) {
        if ( _cursor->prev == _head ) 
            break;
        else
            _cursor = _cursor->prev;
    }
}

void Keyboard::moveCursorRight(int k) {
    for (int i = 0; i < k; i++) {
        if ( _cursor == _tail ) 
            break;
        else
            _cursor = _cursor->next;
    }
}

void Keyboard::insertChar(char newLetter) {
    Node *newNode = new Node;
    newNode->letter = newLetter;
    newNode->prev = _cursor->prev;
    newNode->next = _cursor;
    _cursor->prev->next = newNode;
    _cursor->prev = newNode;
}

void Keyboard::deleteChar() {
    if ( _cursor->prev == _head ) return;
    Node *delNode = _cursor->prev;
    delNode->prev->next = _cursor;
    _cursor->prev = delNode->prev;
    delete delNode;
    _cursor = _head->next;
}

void Keyboard::printLine() {
    for (Node *n = _head->next; n != _tail; n = n->next) {
        cout << n->letter;
    }
}
