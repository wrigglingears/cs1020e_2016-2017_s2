#include <iostream>
#include <string>

using namespace std;

class Animal {
    
};

class OldMcDonald {
private:
    Animal** _farm;
    const int _size;

public:
    OldMcDonald() {

    }


    ~OldMcDonald() {

    }

    void sing() {
        for (int i = 0; i < _size; ++i) {
            cout << "Old McDonald har a farm, E-I-E-I-O" << endl;

            
        }
    }

    void fillThisFarm() {

    }
}

int main(void) {
    OldMcDonald farm;
    farm.fillThisFarm();
    farm.sing();
    return 0;
}