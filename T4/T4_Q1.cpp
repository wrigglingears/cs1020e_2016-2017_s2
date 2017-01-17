#include <iostream>
#include <string>

using namespace std;

class NusModule {
private:
    string _name;
    int _credits;
    string _grade;
    double _point;

    void _updatePoint() {
        if (_grade == "A+" || _grade == "A") {
            _point = 5.0;
        }
        else if (_grade == "A-") {
            _point = 4.5;
        }
        else if (_grade == "B+") {
            _point = 4.0;
        }
        else if (_grade == "B") {
            _point = 3.5;
        }
        else if (_grade == "B-") {
            _point = 3.0;
        }
        else if (_grade == "C+") {
            _point = 2.5;
        }
        else if (_grade == "C") {
            _point = 2.0;
        }
        else if (_grade == "D+") {
            _point = 1.5;
        }
        else if (_grade == "D") {
            _point = 1.0;
        }
        else if (_grade == "F" || _grade == "S" || _grade == "U") {
            _point = 0.0;
        }
    }

public:
    NusModule(string name, int credits, string grade = "F")
    : _name(name), _credits(credits), _grade(grade) {
        _updatePoint();
    }
    void printInfo() {
        cout << _name << "(" << _credits << "): " << _grade << " = " << _point << endl;
    }
    void setGrade(string grade) {
        _grade = grade;
        _updatePoint();
    }
    void declareAsSU() {
        if (_grade == "A+" || _grade == "A" || _grade == "A-" ||
            _grade == "B+" || _grade == "B" || _grade == "B-" ||
            _grade == "C+" || _grade == "C") {
            _grade = "S";
        }
        else if (_grade == "D+" || _grade == "D" ||
                 _grade == "F") {
            _grade = "U";
        }
        _updatePoint();
    }
    double getPoint() {
        return _point;
    }
    double getCredits() {
        if (_grade == "S" || _grade == "U") {
            return 0.0;
        }
        return _credits;
    }
};

double calculateCAP(NusModule* moduleList, int numModules) {
    double sumProducts = 0.0;
    int sumCredits = 0;
    for (int i = 0; i < numModules; ++i) {
        sumProducts += moduleList[i].getPoint() * moduleList[i].getCredits();
        sumCredits += moduleList[i].getCredits();
    }
    return sumProducts / sumCredits;
}

int main(void) {
    NusModule modules[2] {{"CS1010E", 4, "A+"},
                          {"CS1020E", 3, "B"}};
    modules[0].printInfo();
    modules[1].printInfo();
    cout << calculateCAP(modules, 2) << endl;

    modules[1].declareAsSU();
    modules[0].printInfo();
    modules[1].printInfo();
    cout << calculateCAP(modules, 2) << endl;
}