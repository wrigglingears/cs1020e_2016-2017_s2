#include <iostream>
#include <initializer_list>
#include <string>
#include <sstream>

using namespace std;

class LinkedList {
private:
    struct Node {
        int number;
        Node* next;
    };
    Node* _head;

    void swap(Node* first, Node* second) {
        int temp = first->number;
        first->number = second->number;
        second->number = temp;
    }

public:
    LinkedList() : _head(NULL) { }

    // Allows us to initialise the LinkedList with a single statement
    // rather than the long series of calls to push()
    // makes testing easier
    LinkedList(initializer_list<int> initVals)
        : LinkedList() {
        for (int i = initVals.size() - 1; i >= 0; --i) {
            push(*(initVals.begin() + i));
        }
    }

    ~LinkedList() {
        while(_head != NULL) {
            pop();
        }
    }

    string toString() {
        ostringstream oss;
        Node* curr = _head;
        while (curr != NULL) {
            oss << curr->number << " ";
            curr = curr->next;
        }
        return oss.str();
    }

    void push( int value ) {
        // Create new node
        Node* temp = new Node;
        temp->number = value;
        // Redirect pointers
        temp->next = _head;
        _head = temp;
    }

    void pop() {
        // Check if we have a node to delete
        if (_head != NULL) {
            Node* temp = _head;
            // Set the new head
            _head = _head->next;
            // Delete node
            delete temp;
            temp = NULL;
        }
    }

    int retrieve( int idx ) {
        Node* curr = _head;
        for (int i = 0; curr != NULL; ++i, curr = curr->next) {
            if (i == idx) {
                return curr->number;
            }
        }
        return -1;
    }

    void remove( int idx ) {
        Node* curr = _head;
        Node* prev = NULL;
        for (int i = 0; curr != NULL; ++i, prev = curr, curr = curr->next) {
            if (i == idx) {
                // Redirect pointers
                prev->next = curr->next;
                // Remove node
                delete curr;
                curr = NULL;
                return;
            }
        }
    }

    void sort() {
        // 0 or 1 node, automatically sorted
        if (_head == NULL || _head->next == NULL) {
            return;
        }
        // Method used here is bubble sort
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            Node* first = _head;
            Node* second = _head->next;
            // Run through the list
            for ( ; second != NULL; first = second, second = second->next) {
                // Out of order
                if (first->number > second->number) {
                    sorted = false;
                    // Swap the two
                    swap(first, second);
                }
            }
        }
    }

    void moveFromList( LinkedList& list2 ) {
        // Delete our list
        delete _head;
        _head = NULL;
        // Move head from other list
        _head = list2._head;
        // Empty other list
        list2._head = NULL;
    }

    void intersectFromList( LinkedList& list2 ) {
        Node* p1 = _head;
        Node* p2 = list2._head;
        // Set the new head as the lower value of the two heads
        if (p1->number < p2->number) {
            // No change in head
            p1 = p1->next;
        }
        else {
            _head = p2;
            p2 = p2->next;
        }
        // Keep track of the last node we added
        Node* curr = _head;
        // Run through both lists
        while (p1 != NULL && p2 != NULL) {
            // Remove duplicates and move on
            if (p1->number == curr->number) {
                Node* duplicate = p1;
                p1 = p1->next;
                delete duplicate;
                duplicate = NULL;
            }
            else if (p2->number == curr->number) {
                Node* duplicate = p2;
                p2 = p2->next;
                delete duplicate;
                duplicate = NULL;
            }
            // Not duplicate, add to the list
            else {
                if (p1->number < p2->number) {
                    curr->next = p1;
                    p1 = p1->next;
                }
                else {
                    curr->next = p2;
                    p2 = p2->next;
                }
                // Move the curr pointer along
                curr = curr->next;
            }
        }
        // Check for any excess nodes
        if (p1 != NULL) {
            // Skip duplicates
            if (p1->number == curr->number) {
                p1 = p1->next;
            }
            curr->next = p1;
        }
        if (p2 != NULL) {
            // Skip duplicates
            if (p2->number == curr->number) {
                p2 = p2->next;
            }
            curr->next = p2;
        }
        // Ensure that list2 no longer has any data since
        // everything has been moved in/deleted
        list2._head = NULL;
    }

    void reverse() {
        // Special case for list of size 0/1
        if (_head == NULL || _head->next == NULL) {
            return;
        }
        Node* prev = NULL;
        Node* curr = _head;
        // Run through the list
        while (curr != NULL) {
            Node* next = curr->next;
            // Redirect pointers
            curr->next = prev;
            // Move pointers along
            prev = curr;
            curr = next;
        }
        // New head
        _head = prev;
    }

    void reverseRestricted() {
        LinkedList resultList;
        while (_head != NULL) {
            resultList.push(_head->number);
            pop();
        }
        moveFromList(resultList);
    }

    void removeDuplicates() {
        if (_head == NULL) {
            return;
        }
        Node* prev = _head;
        Node* curr = _head->next;
        // Run through the list
        while (curr != NULL) {
            // Found duplicate
            if (curr->number == prev->number) {
                Node* duplicate = curr;
                // Redirect pointers
                curr = curr->next;
                prev->next = curr;
                // Remove duplicate
                delete duplicate;
                duplicate = NULL;
            }
            else {
                // Move pointers along
                curr = curr->next;
                prev = prev->next;
            }
        }
    }
};

int main(void) {
    LinkedList list;
    list.push(5);
    list.push(4);
    list.push(4);
    list.push(4);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(2);
    list.push(1);
    list.push(1);

    LinkedList list2;
    list2.push(6);
    list2.push(5);
    list2.push(4);
    list2.push(3);

    LinkedList list3{1, 2, 3, 5};

    cout << list.toString() << endl;
    cout << list2.toString() << endl;
    cout << list3.toString() << endl;

    list.removeDuplicates(); cout << "removed duplicates" << endl;
    list2.removeDuplicates(); cout << "removed duplicates" << endl;
    cout << list.toString() << endl;
    cout << list2.toString() << endl;

    list.moveFromList(list3); cout << "moved" << endl;
    cout << list.toString() << endl;

    list.intersectFromList(list2); cout << "intersected" << endl;
    cout << list.toString() << endl;
    cout << list2.toString() << endl;

    list.reverse(); cout << "reversed" << endl;
    cout << list.toString() << endl;

    list.reverseRestricted(); cout << "reversed restricted" << endl;
    cout << list.toString() << endl;

    return 0;
}
