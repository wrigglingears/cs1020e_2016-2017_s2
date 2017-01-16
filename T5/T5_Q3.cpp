#include <iostream>
#include <list>
#include <utility>

using namespace std;

void reverse(list<int>& linkList) {
    // Size 0 or 1, no need to reverse
    if (linkList.size() < 2) {
        return;
    }
    list<int>::iterator front = linkList.begin();
    list<int>::iterator back = --linkList.end();
    while (front != back) {
        swap(*front, *back);
        // If list length is even
        if (++front == back) {
            return;
        }
        --back;
    }
}

void removeDuplicates(list<int>& linkList) {
    // Size 0 or 1, no duplicates
    if (linkList.size() < 2) {
        return;
    }
    list<int>::iterator prev = linkList.begin();
    list<int>::iterator curr = ++linkList.begin();
    while (curr != linkList.end()) {
        if (*curr == *prev) {
            curr = linkList.erase(curr);
        }
        // Only move both pointers along if no duplicates
        // as there might be multiple duplicates in a row
        else {
            ++curr;
            ++prev;
        }
    }
}

void print(list<int>& linkList) {
    for (list<int>::iterator i = linkList.begin(); i != linkList.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

int main(void) {
    list<int> my_list{1, 2, 2, 2, 3, 4, 4};
    print(my_list);

    reverse(my_list);
    print(my_list);

    removeDuplicates(my_list);
    print(my_list);
}