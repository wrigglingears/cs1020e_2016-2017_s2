//=====================================================================
// FILE: Main.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO. : <matric no.>
// NUS EMAIL : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include "SocialNetwork.h"

int main() {
    /* char infile[] = "data/socialnetworkw.in";
    char outfile[] = "data/socialnetworkw.out";
    for (int tc=0; tc<10; tc++){
    infile[18] = outfile[18] = '0'+tc;
    freopen(infile,"r",stdin); freopen(outfile,"w",stdout); */
    SocialNetwork *sn = new SocialNetwork();
    int N;
    cin>>N;
    for (int ll = 0; ll<N; ll++){
        string op, prs, grp;
        cin>>op;
        //cout<<op<<' '<<ll<<endl;
        if (op == "Createjoin"){
            cin>>prs>>grp;
            sn->createjoin (prs, grp);
        }
        else if (op == "Quit"){
            cin>>prs>>grp;
            sn->quit(prs,grp);
        }
        else if (op == "Query"){
            int qtype;
            cin>>qtype;
            if (qtype == 1){
                cout<<sn->answerQuery1()<<endl;
            }
            else if (qtype == 2){
                cout<<sn->answerQuery2()<<endl;
            }
            else continue;
        }
        else continue;
    }
    //}
    return 0;
}
