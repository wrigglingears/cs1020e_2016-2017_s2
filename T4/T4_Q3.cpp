#include <iostream>

using namespace std;

class LinkedList {
private:
    struct Node {
        int number;
        Node* next;
        ~Node() {
            delete next;
            next = nullptr;
        }
    };
    Node* _head;
public:
    LinkedList() : _head(nullptr) {}
    ~LinkedList() {
        delete _head;
        _head = nullptr;
    }
    void print() {
        Node* curr = _head;
        while (curr != nullptr) {
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
        if (_head != nullptr) {
            Node* temp = _head;
            // Set the new head
            _head = _head->next;
            // Prep node for deletion
            temp->next = nullptr;
            // Delete node
            delete temp;
        }
    }
    int retrieve( int idx ) {
        Node* curr = _head;
        for (int i = 0; curr != nullptr; ++i, curr = curr->next) {
            if (i == idx) {
                return curr->number;
            }
        }
        return -1;
    }
    void remove( int idx ) {
        Node* curr = _head;
        Node* prev = nullptr;
        for (int i = 0; curr != nullptr; ++i, prev = curr, curr = curr->next) {
            if (i == idx) {
                // Redirect pointers
                prev->next = curr->next;
                curr->next = nullptr;
                // Remove node
                delete curr;
                return;
            }
        }
    }
    void sort() {
        // 0 or 1 node, automatically sorted
        if (_head == nullptr || _head->next == nullptr) {
            return;
        }
        // Method used here is bubble sort
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            Node* first = _head;
            Node* second = _head->next;
            // Run through the list
            while (second != nullptr) {
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
