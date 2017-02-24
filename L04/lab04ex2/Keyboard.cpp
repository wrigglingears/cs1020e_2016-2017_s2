//=====================================================================
// FILE: Keyboard.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Xu Weichen	
// MATRIC NO.  : A0155584W
// NUS EMAIL   : e0031721@u.nus.edu
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
	_cursor = new Node();
}

void Keyboard::moveCursorLeft(int k) {
	cout << "moving cursor left" << endl;
	int counter = 0;
	Node* temp_node = new Node();
	while (counter < k or _cursor->prev != NULL) {
		temp_node->next = _cursor->prev;
		temp_node->prev = (_cursor->prev)->prev;
		_cursor->prev = temp_node->prev;
		_cursor->next = temp_node->next;
		counter++;
	}
	delete temp_node;
	temp_node = NULL;
}

void Keyboard::moveCursorRight(int k) {
	cout << "moving cursor right" << endl;
	int counter = 0;
	Node* temp_node = new Node();
	while (counter != k or _cursor->next != NULL) {
		temp_node->prev = _cursor->next;
		temp_node->next = (_cursor->next)->next;
		_cursor->prev = temp_node->prev;
		_cursor->next = temp_node->next;
		counter++;
	}
	delete temp_node;
	temp_node = NULL;
}

void Keyboard::insertChar(char newLetter) {
	cout << "inserting character" << endl;
	Node* new_node = new Node;
	new_node->letter = newLetter;
	//empty list
	if (_head == NULL and _tail== NULL) {
		_tail = new_node;
		_head = new_node;
		_cursor->prev = new_node;
	} 
	else {
		if (_cursor->prev == NULL) {
			new_node->next = _head;
			_head->prev = new_node;
			_head = new_node;
			_cursor->prev = new_node;
			_cursor->next = new_node->next;
		}
		else if (_cursor->next == NULL) {
			new_node->prev = _tail;
			_tail->next = new_node;
			_tail = new_node;
			_cursor->prev = new_node;
		}
		else {
			_cursor->prev->next = new_node;
			new_node->prev = _cursor->prev;
			new_node->next = _cursor->next;
			_cursor->next->prev = new_node;
			_cursor->prev = new_node;
		}
	}
}

void Keyboard::deleteChar() {
	cout << "delete character" << endl;
	if (_cursor->prev != NULL) {
		cout << "not the front of the list" << endl;
		Node* temp = _cursor->prev->prev;
		Node* deleted = _cursor->prev;
		_cursor->next->prev = temp;
		if (temp != NULL) {
			temp->next = _cursor->next;
		}
		delete deleted;
		deleted = NULL;
		_cursor->prev = NULL;
		_cursor->next = _head;
	}
}

void Keyboard::printLine() {
	Node* cur = _head;
	int count = 0;
	while (cur != NULL) {
		cout << count << endl;
		cout << cur->letter << endl;
		cur = cur->next;
		count++;
	}
}

