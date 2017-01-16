#include <iostream>

using namespace std;

class CircularDoublyLinkedList {
private:
    struct Node {
        int number;
        Node* next;
        Node* prev;
        ~Node() {
            delete next;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head;
public:
    CircularDoublyLinkedList() : head(nullptr) {}
    ~CircularDoublyLinkedList() {
        // Turn list from circular to standard list
        if (head != nullptr) {
            head->prev->next = nullptr;
        }
        delete head;
        head = nullptr;
    }
    void print() {
        if (head == nullptr) {
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
        if (head == nullptr) {
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
        if (head == nullptr) {
            return;
        }
        // Special case for list of size 1
        if (head->next == head) {
            head->next = nullptr;
            delete head;
            head = nullptr;
        }
        // Normal case
        Node* temp = head;
        // Redirect pointers
        head = head->next;
        temp->prev->next = head;
        head->prev = temp->prev;
        // Delete node
        temp->next = nullptr;
        delete temp;
    }
    int retrieve(int idx) {
        if (head == nullptr) {
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
        if (head == nullptr) {
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
                curr->next = nullptr;
                delete curr;
                curr = nullptr;
                return;
            }
        }
        return;
    }
    void reverse() {
        // Size 0 or 1, no need to reverse
        if (head == nullptr || head->next == nullptr) {
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