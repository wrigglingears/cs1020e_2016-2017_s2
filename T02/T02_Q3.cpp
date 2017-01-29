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

    void makeSound() {
        cout << _name << " goes " << _sound << endl;
    }

protected:
    string _name;
    string _sound;
};

class Flyer : public Animal {
protected:
    string _name;
    string _sound;
    bool _isFlying;

public:
    Flyer(string name, string sound)
        : _name(name), _sound(sound), _isFlying(false) { }

    void makeSound() {
        if (_isFlying) {
            cout << getName() << " goes flap flap" << endl;
        }
        else {
            Animal::makeSound();
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

    void makeSound() {
        if (_isGliding) {
            cout << getName() << " goes whoosh" << endl;
        }
        else {
            makeSound();
        }
    }
};

class OldMcDonald {
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

    void makeSomeNoise() {

    }

    void fillThisFarm() {
        _farm[0] = new Flyer("Parrot", "squak");
        _farm[1] = new Flyer("Cow", "moo");
        _farm[2] = new Flyer("Mosquito", "buzz");
        ((Flyer*)_farm[2])->fly();
        _farm[3] = new Flyer("Sheep", "mehh");
        _farm[4] = new Flyer("Fish", "blurp");

    }

private:
    Animal** _farm;
    const int _size;

};

int main(void) {
    OldMcDonald farm;
    farm.fillThisFarm();
    farm.makeSomeNoise();
    return 0;
}