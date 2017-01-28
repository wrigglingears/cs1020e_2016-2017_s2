#include <iostream>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

class Fraction : pair<int, int> {
private:
    void _reduce() {
        // Iterate through possible divisors
        for (int i = 2; i <= first && i <= second; ++i) {
            // Reduce both numerator and denominator
            while (first % i == 0 && second % i == 0) {
                first /= i;
                second /= i;
            }
        }
    }

public:
    Fraction(int num, int den)
    : pair<int, int>(num, den) {
        _reduce();
    }
    string toString() {
        ostringstream oss;
        oss << first << "/" << second;
        return oss.str();
    }
    double getDouble() {
        return (double)first / (double)second;
    }
    int getNum() {
        return first;
    }
    int getDen() {
        return second;
    }
    Fraction add(Fraction other) {
        // Perform cross-multiplication
        int num = first * other.second + second * other.first;
        int den = second * other.second;
        // Create new fraction which automatically reduces
        Fraction result(num, den);
        return result;
    }
    Fraction subtract(Fraction other) {
        // Add the negated value
        other.first *= -1;
        return add(other);
    }
    Fraction multiply(Fraction other) {
        // Directly multiply
        int num = first * other.first;
        int den = second * other.second;
        // Create new fraction which automatically reduces
        Fraction result(num, den);
        return result;
    }
    Fraction divide(Fraction other) {
        // Flip numerator and denominator then multiply
        Fraction temp(other.second, other.first);
        return multiply(temp);
    }
};

int main(void) {
    Fraction frac1(2,4);
    Fraction frac2(3,9);

    cout << "f1 = " << frac1.toString() << " = " << frac1.getDouble() << endl;
    cout << "numerator of f1 = " << frac1.getNum() << ", denominator of f1 = " << frac1.getDen() << endl;
    cout << "f2 = " << frac2.toString() << " = " << frac2.getDouble() << endl;
    cout << "numerator of f2 = " << frac2.getNum() << ", denominator of f2 = " << frac2.getDen() << endl;
    cout << "f1+f2 = " << frac1.add(frac2).toString() << endl;
    cout << "f1-f2 = " << frac1.subtract(frac2).toString() << endl;
    cout << "f1*f2 = " << frac1.multiply(frac2).toString() << endl;
    cout << "f1+f2 = " << frac1.divide(frac2).toString() << endl;

    return 0;
}