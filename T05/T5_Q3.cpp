#include <iostream>
#include <list>
#include <utility>

using namespace std;

void reverse(list<int>& linkList) {

}

void removeDuplicates(list<int>& linkList) {
    
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

    reverse(my_list);
    removeDuplicates(my_list);
    print(my_list);
}