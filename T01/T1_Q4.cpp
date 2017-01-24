#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal(string name, string sound)
    : _name(name), _sound(sound) { }

    string getName() {
        return _name;
    }

    string getSound() {
        return _sound;
    }

private:
    string _name;
    string _sound;

};

class OldMcDonald {
public:
    OldMcDonald()
    : _size(3) {
        _farm = new Animal*[3];
        _farm[0] = new Animal("Cow", "Moo");
        _farm[1] = new Animal("Dog", "Woof");
        _farm[2] = new Animal("Duck", "Quack");
    }

    ~OldMcDonald() {
        for (int i = 0; i < _size; ++i) {
            delete _farm[i];
            _farm[i] = NULL;
        }
        delete[] _farm;
        _farm = NULL;
    }

    void sing() {
        for (int i = 0; i < _size; ++i) {
            cout << "Old McDonald had a farm, E-I-E-I-O" << endl;

            cout << "And on his farm he had a " << _farm[i]->getName() << ", E-I-E-I-O" << endl;

            cout << "With a " << _farm[i]->getSound() << " " << _farm[i]->getSound();
            cout << " here and a " << _farm[i]->getSound() << " " << _farm[i]->getSound() << " there" << endl;

            cout << _farm[i]->getSound() << " here " << _farm[i]->getSound() << " there, everywhere " << _farm[i]->getSound() << " " << _farm[i]->getSound() << endl;

            cout << "Old McDonald had a farm, E-I-E-I-O" << endl << endl;
        }
    }

private:
    Animal** _farm;
    const int _size;

};

int main(void) {
    OldMcDonald farm;
    farm.sing();
    return 0;
}