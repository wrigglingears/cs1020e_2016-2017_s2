#include <iostream>

using namespace std;

int main(void) {
    int a = -1, b = 1, c = 1, d = 0, e = 2, f = 2, g = 0, i = 1;
    int h = f-- && e++ && d++ && c-- || b++ && i-- || a++;

    if (g = 9) {
        cout << a << b << c << d << e << f << g << h << i << endl;
    }
    else {
        cout << i << h << g << f << e << d << c << b << a << endl;
    }

    return 0;
}