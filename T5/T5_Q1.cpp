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
    void moveFromList( LinkedList& list2 ) {
        // Delete our list
        delete _head;
        _head = nullptr;
        // Move head from other list
        _head = list2._head;
        // Empty other list
        list2._head = nullptr;
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
        Node* tail = _head;
        // Run through both lists
        while (p1 != nullptr && p2 != nullptr) {
            // Remove duplicates and move on
            if (p1->number == tail->number) {
                Node* dupl = p1;
                p1 = p1->next;
                dupl->next = nullptr;
                delete dupl;
            }
            else if (p2->number == tail->number) {
                Node* dupl = p2;
                p2 = p2->next;
                dupl->next = nullptr;
                delete dupl;
            }
            // Not duplicate, add to the list
            else {
                cout << "";
                if (p1->number < p2->number) {
                    tail->next = p1;
                    p1 = p1->next;
                }
                else {
                    tail->next = p2;
                    p2 = p2->next;
                }
                // Move the tail pointer along
                tail = tail->next;
            }
        }
        // Check for any excess nodes
        if (p1 != nullptr) {
            // Skip duplicates
            if (p1->number == tail->number) {
                p1 = p1->next;
            }
            tail->next = p1;
        }
        if (p2 != nullptr) {
            // Skip duplicates
            if (p2->number == tail->number) {
                p2 = p2->next;
            }
            tail->next = p2;
        }
        // Clear up list2
        list2._head = nullptr;
    }
    void reverse() {
        // Special case for list of size 0/1
        if (_head == nullptr || _head->next == nullptr) {
            return;
        }
        Node* prev = nullptr;
        Node* curr = _head;
        Node* next;
        // Run through the list
        while (curr != nullptr) {
            // Redirect pointers
            next = curr->next;
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
        Node* curr = _head;
        while (curr != nullptr) {
            resultList.push(curr->number);
            curr = curr->next;
            moveFromList(resultList);
        }
    }
    void removeDuplicates() {
        if (_head == nullptr) {
            return;
        }
        Node* prev = _head;
        Node* duplicate;
        Node* tail = _head->next;
        // Run through the list
        while (tail != nullptr) {
            // Found duplicate
            if (tail->number == prev->number) {
                duplicate = tail;
                // Redirect pointers
                tail = tail->next;
                prev->next = tail;
                duplicate->next = nullptr;
                // Remove duplicate
                delete duplicate;
                duplicate = nullptr;
            }
            else {
                // Move pointers along
                tail = tail->next;
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

    list.print();
    list2.print();

    //list.moveFromList(list2); cout << "moved" << endl;

    list.removeDuplicates(); cout << "removed duplicates" << endl;
    list2.removeDuplicates(); cout << "removed duplicates" << endl;
    list.print();
    list2.print();

    list.intersectFromList(list2); cout << "intersected" << endl;
    list.print();
    list2.print();

    list.reverse(); cout << "reversed" << endl;
    list.print();

    return 0;
}
