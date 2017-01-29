#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

double add(int a, int b) {
    return a + b;
}

void swap(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(void) {

}