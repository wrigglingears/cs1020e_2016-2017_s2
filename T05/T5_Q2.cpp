#include <iostream>
#include <initializer_list>
#include <string>
#include <sstream>

using namespace std;

class CircularDoublyLinkedList {
private:
    struct Node {
        int number;
        Node* next;
        Node* prev;
    };
    Node* _head;

    void swap(Node* first, Node* second) {
        int temp = first->number;
        first->number = second->number;
        second->number = temp;
    }

public:
    CircularDoublyLinkedList() : _head(NULL) {}

    // Allows us to initialise the LinkedList with a single statement
    // rather than the long series of calls to push()
    // makes testing easier
    CircularDoublyLinkedList(initializer_list<int> initVals)
        : _head(NULL) {
        for (int i = initVals.size() - 1; i >= 0; --i) {
            push(*(initVals.begin() + i));
        }
    }

    ~CircularDoublyLinkedList() {
        while (_head != NULL) {
            pop();
        }
    }

    string toString() {
        ostringstream oss;
        if (_head == NULL) {
            return "";
        }
        Node* curr = _head;
        oss << curr->number << " ";
        curr = curr->next;
        while (curr != _head) {
            oss << curr->number << " ";
            curr = curr->next;
        }
        return oss.str();
    }

    void push(int value) {
        // Special case for empty list
        if (_head == NULL) {
            Node* temp = new Node;
            temp->number = value;
            temp->next = temp;
            temp->prev = temp;
            _head = temp;
            return;
        }
        // Normal case
        Node* temp = new Node;
        temp->number = value;
        temp->next = _head;
        temp->prev = _head->prev;
        _head->prev->next = temp;
        _head->prev = temp;
        _head = temp;
    }

    void pop() {
        // Special case for list of size 0
        if (_head == NULL) {
            return;
        }
        // Special case for list of size 1
        if (_head->next == _head) {
            delete _head;
            _head = NULL;
            return;
        }
        // Have a pointer to the Node to be deleted
        Node* temp = _head;
        // Redirect pointers
        _head = _head->next;
        temp->prev->next = _head;
        _head->prev = temp->prev;
        // Delete node
        delete temp;
        temp = NULL;
    }

    int retrieve(int idx) {
        if (_head == NULL) {
            return -1;
        }
        if (idx == 0) {
            return _head->number;
        }
        Node* curr = _head->next;
        for (int i = 1; curr != _head; ++i, curr = curr->next) {
            if (i == idx) {
                return curr->number;
            }
        }
        return -1;
    }

    void remove(int idx) {
        if (_head == NULL) {
            return;
        }
        if (idx == 0) {
            pop();
            return;
        }
        Node* curr = _head->next;
        for (int i = 1; curr != _head; ++i, curr = curr->next) {
            if (i == idx) {
                // Redirect pointers
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                curr = NULL;
                return;
            }
        }
    }

    void reverse() {
        
    }
};

int main(void) {
    CircularDoublyLinkedList list;
    list.push(5);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);

    cout << list.toString() << endl;

    CircularDoublyLinkedList list2{1, 2, 3, 4};
    cout << list2.toString() << endl;

    cout << list.retrieve(4) << endl;

    list.remove(2);
    list.remove(3);
    list.push(2);
    cout << list.toString() << endl;

    list.reverse();
    cout << list.toString() << endl;

    list.pop();
    list.pop();
    cout << list.toString() << endl;
}