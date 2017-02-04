#include <iostream>

using namespace std;

class MyVector {
private:

public:
    MyVector() {

    }

    ~MyVector() {

    }

    void addItem() {

    }

    void del() {

    }

    int size() {

    }

    datatype getItemAt(idx) {

    }
};

int main(void) {
    MyVector vec;

    vec.addItem(5);
    vec.addItem(6);
    vec.addItem(7);
    vec.addItem(8);

    vec.del();

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec.getItemAt(i) << endl;
    }
}