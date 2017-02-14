#include <iostream>
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
    LinkedList() : _head(NULL) {}

    ~LinkedList() {
        Node* curr = _head;
        // Iterate through the list, deleting one Node at a time
        while (curr != NULL) {
            // Store the next Node pointer first,
            // so that we can still access it
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

    string toString() {
        ostringstream oss;
        for (Node* curr = _head; curr != NULL; curr = curr->next) {
            oss << curr->number << " ";
        }
        return oss.str();
    }

    void push( int value ) {
        // Create new node
        Node* temp = new Node;
        temp->number = value;
        // Redirect pointers at the front
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
};

int main(void) {
    LinkedList list;
    list.push(10);
    list.push(24);
    list.push(8);
    list.push(2);
    list.push(16);
    list.push(99);
    list.push(48);
    list.push(73);
    list.push(33);
    list.push(61);

    cout << "Initial list" << endl;
    cout << list.toString() << endl << endl;

    list.sort();
    cout << "After sorting" << endl;
    cout << list.toString() << endl << endl;

    list.remove(3);
    list.remove(5);
    cout << "After removing index 3, then index 5" << endl;
    cout << list.toString() << endl << endl;

    list.pop();
    list.pop();
    cout << "After popping twice" << endl;
    cout << list.toString() << endl << endl;

    cout << "Retrieving by index (very careful not to go beyond size)" << endl;
    // Should have 6 left
    for (int i = 0; i < 6; ++i) {
        cout << list.retrieve(i) << " ";
    }
    cout << endl;

    return 0;
}
