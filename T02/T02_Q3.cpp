#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string _name;
    string _sound;

public:
    Animal(string name, string sound)
        : _name(name), _sound(sound) { }

    string getName() {
        return _name;
    }

    string getSound() {
        return _sound;
    }
};

class Flyer : public Animal {
protected:
    string _name;
    string _sound;
    bool _isFlying;

public:
    Flyer(string name, string sound)
        : _name(name), _sound(sound), _isFlying(false) { }

    string getSound() {
        if (_isFlying) {
            return "flap";
        }
        else {
            return Animal::getSound();
        }
    }

    void fly() {
        _isFlying = true;
    }

    void stop() {
        _isFlying = false;
    }
};

class Glider : Flyer {
    bool _isGliding;

public:
    Glider(string name, string sound)
        : Flyer(name, sound), _isGliding(false) { }

    void glide() {
        if (_isFlying) {
            _isGliding = true;
        }
    }

    void stop() {
        _isFlying = false;
        _isGliding = false;
    }

    string getSound() {
        if (_isGliding) {
            return "woosh";
        }
        else {
            return getSound();
        }
    }
};

class OldMcDonald {
private:
    Animal** _farm;
    const int _size;
    
public:
    OldMcDonald()
        : _size(5) {
        _farm = new Animal*[_size];
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

    void fillThisFarm() {
        _farm[0] = new Flyer("Parrot", "squak");
        _farm[1] = new Flyer("Cow", "moo");
        _farm[2] = new Flyer("Mosquito", "buzz");
        ((Flyer*)_farm[2])->fly();
        _farm[3] = new Flyer("Sheep", "mehh");
        _farm[4] = new Flyer("Fish", "blurp");

    }
};

int main(void) {
    OldMcDonald farm;
    farm.fillThisFarm();
    farm.sing();
    return 0;
}