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

    void unionWithList( LinkedList& other ) {
        // Other list is empty
        if (other._head == NULL) {
            return;
        }
        // Our list is empty
        if (_head == NULL) {
            _head = other._head;
            other._head = NULL;
            return;
        }

        Node* p1 = _head;
        Node* p2 = other._head;
        // Select the new head as the lower value of the two heads
        if (p1->number < p2->number) {
            // No change to the current head
            p1 = p1->next;
        }
        else if (p1->number > p2->number) {
            _head = p2;
            p2 = p2->next;
        }
        // Both heads are the same
        else {
            Node* duplicate = p2;
            p1 = p1->next;
            p2 = p2->next;
            delete duplicate;
        }

        Node* tail = _head;
        // Continue as long as there are still nodes in both lists
        while (p1 != NULL && p1 != NULL) {
            // Next node comes from our list
            if (p1->number < p2->number) {
                tail->next = p1;
                p1 = p1->next;
            }
            // Next node comes from other list
            else if (p1->number > p2->number) {
                tail->next = p2;
                p2 = p2->next;
            }
            // Duplicate found
            else {
                Node* duplicate = p2;
                tail->next = p1;
                p1 = p1->next;
                p2 = p2->next;
                delete duplicate;
            }
            tail = tail->next;
        }

        // Add remaining nodes from the longer list
        if (p1 != NULL) {
            tail->next = p1;
        }
        if (p2 != NULL) {
            tail->next = p2;
        }

        // Ensure that other list is empty
        other._head = NULL;
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

};

int main(void) {
    LinkedList list1;
    list1.push(5);
    list1.push(4);
    list1.push(3);
    list1.push(2);
    list1.push(1);

    LinkedList list2{1, 3, 4, 5, 6};

    cout << "list1: " << list1.toString() << endl;
    cout << "list2: " << list2.toString() << endl;

    list1.unionWithList(list2);
    cout << "union 2 into 1: " << list1.toString() << endl;

    list1.reverse();
    cout << "reverse 1: " << list1.toString() << endl;

    return 0;
}
