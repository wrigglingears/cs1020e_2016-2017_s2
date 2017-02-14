//=====================================================================
// FILE: Josephine.cpp
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
#include <string>
#include <cstdlib>
#include "DataStructure.h"
using namespace std;


int main()
{
    int t,n,k;

    cin >> t;
    while (t-- > 0) {
        cin >> n >> k;
        DataStructure *cur = new DataStructure(1);
        for (int i=2; i<=n; i++) {
            cur->insert(i);
            cur = cur->move();
        }
        cur = cur->move();

        while (n-- > 0) {
            for (int i=0; i<k-1; i++)
                cur = cur->move();
            cout << cur->getID() << ' ';
            cur = cur->del();
        }
        cout << endl;

    }
    return 0;
}
