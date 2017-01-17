#include <iostream>

using namespace std;

class LinkedList {
private:
    struct Node {
        int number;
        Node* next;
        Node() : next(NULL) {}
        ~Node() {
            delete next;
            next = NULL;
        }
    };
    Node* _head;
public:
    LinkedList() : _head(NULL) {}
    ~LinkedList() {
        delete _head;
        _head = NULL;
    }
    void print() {
        Node* curr = _head;
        while (curr != NULL) {
            cout << curr->number << " ";
            curr = curr->next;
        }
        cout << endl;
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
            // Prep node for deletion
            temp->next = NULL;
            // Delete node
            delete temp;
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
                curr->next = NULL;
                // Remove node
                delete curr;
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
            while (second != NULL) {
                // Out of order
                if (first->number > second->number) {
                    sorted = false;
                    // Swap the two
                    int temp = first->number;
                    first->number = second->number;
                    second->number = temp;
                }
                first = second;
                second = second->next;
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
    list2.push(2);
    list2.push(3);

    list.print();
    list2.print();

    list.sort();
    list2.sort();
    list.print();
    list2.print();

    return 0;
}
