//=====================================================================       
// FILE: ArrayOfPoints.cpp
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

using namespace std;


struct Point {
    int x;
    int y;
};


int main() 
{
    int numPoints;

    cin >> numPoints;

    Point *pt = new Point[numPoints];

    for (int i = 0; i < numPoints; i++ )
    {
        cin >> pt[i].x;
        cin >> pt[i].y;
    }

    for (int j = numPoints - 1; j >= 0; j--)
    {
        cout << "Point " << j << ": (" 
             << pt[j].x << ", " << pt[j].y << ")" << endl;
    }

    delete[] pt; 

    return 0;
}
