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

public:
    NUSModule(string name, int credits, string grade = "F")
    : _name(name), _credits(credits), _grade(grade) { }

    string toString() {
        ostringstream oss;
        oss << _name << "(" << _credits << "): " << _grade << " = " << _point;
        return oss.str();
    }

    void setGrade(string grade) {

    }

    double getPoint() {

    }

    double getCredits() {

    }
};

double calcCap(NUSModule moduleList[], int numModules) {

}

int main(void) {
    const int num_modules = 4;
    NUSModule modules[num_modules] {{"CS1010E", 4, "A+"},
                                    {"AA2001" , 3, "C"},
                                    {"CS1020E", 4, "A+"},
                                    {"BB3002" , 4, "A-"}};

    cout << "Initial module list" << endl;
    for (int i = 0; i < num_modules; ++i) {
        cout << modules[i].toString() << endl;
    }
    cout << "CAP = " << calcCAP(modules, num_modules) << endl << endl;

    modules[1].declareAsSU();
    cout << "After S/U declaration" << endl;
    for (int i = 0; i < num_modules; ++i) {
        cout << modules[i].toString() << endl;
    }
    cout << "CAP = " << calcCAP(modules, num_modules) << endl;
}