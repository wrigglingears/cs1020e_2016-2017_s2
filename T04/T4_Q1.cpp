#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class NUSModule {
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
    NUSModule(string name, int credits, string grade = "F")
    : _name(name), _credits(credits), _grade(grade) {
        _updatePoint();
    }
    string toString() {
        ostringstream oss;
        oss << _name << "(" << _credits << "): " << _grade << " = " << _point;
        return oss.str();
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

double calcCAP(NUSModule moduleList[], int numModules) {
    double sumProducts = 0.0;
    int sumCredits = 0;
    for (int i = 0; i < numModules; ++i) {
        sumProducts += moduleList[i].getPoint() * moduleList[i].getCredits();
        sumCredits += moduleList[i].getCredits();
    }
    return sumProducts / sumCredits;
}

int main(void) {
    NUSModule modules[3] {{"CS1010E", 4, "A+"},
                          {"CS1020E", 3, "B"},
                          {"CS2010",  4, "A-"}};
    cout << modules[0].toString() << endl;
    cout << modules[1].toString() << endl;
    cout << modules[2].toString() << endl;
    cout << calcCAP(modules, 3) << endl;

    modules[1].declareAsSU();
    cout << modules[0].toString() << endl;
    cout << modules[1].toString() << endl;
    cout << modules[2].toString() << endl;
    cout << calcCAP(modules, 3) << endl;
}