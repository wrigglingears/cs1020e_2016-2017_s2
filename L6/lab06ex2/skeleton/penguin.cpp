//=====================================================================
// FILE: penguin.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include <queue>
#include <utility>  // for pair class.
using namespace std;


class BestDive {
private:
    queue< pair<bool, int> > _units; // <risk, fishes>
    int _currFishes;
    int _currRisk;
    int _maxFishes;
    int _riskThreshold;

public:
    // Constructor.
    BestDive( int riskThreshold ) 
        : _units(), _currFishes(0), _currRisk(0),
        _maxFishes(0), _riskThreshold(riskThreshold) {} // no dive


    int getMaxFishes() { return _maxFishes; }


    void considerUnit( bool isRisky, int unitFishes ) 
    {
        _units.push( make_pair( isRisky, unitFishes ) );

        // Add your code here.
    }

};


int main() {
    int riskThreshold;
    cin >> riskThreshold; // T

    BestDive dive( riskThreshold );

    char unitRisk;
    int unitFishes;

    while ( cin >> unitRisk >> unitFishes ) // read risk and Fi
        dive.considerUnit( (unitRisk == 'R'), unitFishes );

    cout << dive.getMaxFishes() << endl;;

    return 0;
}
