//=====================================================================
// FILE: Main.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tan Yi Wei
// MATRIC NO. : A0140615R
// NUS EMAIL : e0004525@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include "SocialNetwork.h"

int main() {
    SocialNetwork *sn = new SocialNetwork();
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i){
		string cmd;
		string name, group;
		int type;

		cin >> cmd;
		if (cmd == "Query"){
			cin >> type;
			if (type == 1){
				cout << sn->answerQuery1() << endl;
			}
			else if (type == 2){
				cout << sn->answerQuery2() << endl;
			}
		}
		else {
			cin >> name;
			cin >> group;
			if (cmd == "Createjoin"){
				sn->createjoin(name, group);
			}
			else if (cmd == "Quit"){
				sn->quit(name, group);
			}
		}
	}
	
	delete sn;
    return 0;
}
