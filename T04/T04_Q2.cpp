#include <iostream>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

class Fraction : pair<int, int> {
private:

public:
    Fraction(int num, int den) {
        first = num;
        second = den;
    }

    string getFraction() {
        ostringstream oss;
        oss << first << "/" << second;
        return oss.str();
    }

    Fraction add(Fraction other) {

    }
};