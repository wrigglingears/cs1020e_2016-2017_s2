#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class MyDate {
private:

public:
    MyDate(string dateInput) {

    }

    int getDay() {

    }

    string getMonth() {

    }

    int getYear() {

    }

    string getDate() {

    }
};

int main(void) {
    MyDate date1("4/1/2017");
    MyDate date2("04 Jan");
    MyDate date3("4.January.17");

    cout << date1.getDate() << endl;
    cout << date2.getDate() << endl;
    cout << date3.getDate() << endl;

    return 0;
}