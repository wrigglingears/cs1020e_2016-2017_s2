#include <iostream>

using namespace std;

class CircularDoublyLinkedList {
private:
    struct Node {
        int number;
        Node* next;
        Node* prev;
        Node() : next(NULL), prev(NULL) {}
        ~Node() {
            delete next;
            next = NULL;
            prev = NULL;
        }
    };
    Node* head;
public:
    CircularDoublyLinkedList() : head(NULL) {}
    ~CircularDoublyLinkedList() {
        // Turn list from circular to standard list
        if (head != NULL) {
            head->prev->next = NULL;
        }
        delete head;
        head = NULL;
    }
    void print() {
        if (head == NULL) {
            return;
        }
        Node* curr = head;
        cout << curr->number << " ";
        curr = curr->next;
        while (curr != head) {
            cout << curr->number << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void push(int value) {
        // Special case for empty list
        if (head == NULL) {
            Node* temp = new Node;
            temp->number = value;
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            return;
        }
        // Normal case
        Node* temp = new Node;
        temp->number = value;
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
    }
    void pop() {
        // Special case for list of size 0
        if (head == NULL) {
            return;
        }
        // Special case for list of size 1
        if (head->next == head) {
            head->next = NULL;
            delete head;
            head = NULL;
        }
        // Normal case
        Node* temp = head;
        // Redirect pointers
        head = head->next;
        temp->prev->next = head;
        head->prev = temp->prev;
        // Delete node
        temp->next = NULL;
        delete temp;
    }
    int retrieve(int idx) {
        if (head == NULL) {
            return -1;
        }
        if (idx == 0) {
            return head->number;
        }
        Node* curr = head->next;
        for (int i = 1; curr != head; ++i, curr = curr->next) {
            if (i == idx) {
                return curr->number;
            }
        }
        return -1;
    }
    void remove(int idx) {
        if (head == NULL) {
            return;
        }
        if (idx == 0) {
            pop();
            return;
        }
        Node* curr = head->next;
        for (int i = 1; curr != head; ++i, curr = curr->next) {
            if (i == idx) {
                // Redirect pointers
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->next = NULL;
                delete curr;
                curr = NULL;
                return;
            }
        }
        return;
    }
    void reverse() {
        // Size 0 or 1, no need to reverse
        if (head == NULL || head->next == NULL) {
            return;
        }
        Node* front = head;
        Node* back = head->prev;
        while (front != back) {
            // Swap the two numbers
            int temp = front->number;
            front->number = back->number;
            back->number = temp;
            // Move the front and back pointers
            front = front->next;
            if (front == back) {
                return;
            }
            back = back->prev;
        }
    }
};

int main(void) {
    CircularDoublyLinkedList list;
    list.push(5);
    list.push(4);
    list.push(3);
    list.push(2);
    list.push(1);
    list.print();

    cout << list.retrieve(4) << endl;

    list.remove(2);
    list.remove(3);
    list.push(2);
    list.print();

    list.reverse();
    list.print();
}