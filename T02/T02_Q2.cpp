#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    Person mother;

public:
    Person(string name, int age) {
        name = name;
        age = age;
    }

    Person(string name, int age, Person person) {
        name = name;
        age = age;
        mother = &person);
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    Person getMother() {
        return mother;
    }

}

int main(void) {
    Person a;
    Person sally("Sally", 32);
    Peraon thomas("Thomas", 6, sally);

    cout << sally.name << " is the mother of " << thomas.name << endl;
    cout << "their age difference is " << sally.age - thomas.age << " years" << endl;

    return 0;
}