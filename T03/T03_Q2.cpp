#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Product {
private:
    long _productID;
    long _volume;
    long _weight;

public:
    Product(string pInput) {

    }

    string str() {

    }

    long getProductID() {
        return _productID;
    }

    long getVolume() {
        return _volume;
    }

    long getWeight() {
        return _weight;
    }
};

int main(void) {
    Product product1("1234567:Wheel bearing|Yamaha XJ900s|Front:9000 50");
    Product product2("00900#acm327df2mm3d1f0#Carburetor needle;Honda CB400;4 pcs;8 5");
    Product product3("000000,Oil filter,Yamaha,3FV-13440-00,225000 200");

    cout << product1 << endl;
    cout << product2 << endl;
    cout << product3 << endl;

    return 0;
}