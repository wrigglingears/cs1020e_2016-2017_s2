//=====================================================================
// FILE: Main.cpp
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
#include <stack>
#include "Token.h"
using namespace std;


int main() {
    stack<Token> myStack;

    string postfix(""), tmp;

    while (cin >> tmp) {
        Token curToken(tmp);
        //cout <<  curToken.getToken() << endl;

        if (curToken.isNumber())
            postfix = postfix + curToken.getToken() + " ";

        if (curToken.isLeftParenthesis())
            myStack.push(curToken);

        if (curToken.isRightParenthesis()) {
            while(!myStack.top().isLeftParenthesis()) {
                postfix = postfix + myStack.top().getToken() + " ";
                myStack.pop();
            }
            myStack.pop();
        }

        if (curToken.isOperator()) {
            while (!myStack.empty() && (curToken.hasLowerPrecedenceThan(myStack.top()) || 
                   curToken.hasEqualPrecedenceTo(myStack.top()))) {
                postfix += myStack.top().getToken() + " ";
                myStack.pop();
            }
            myStack.push(curToken);
        }

        //cout << myStack.size() << endl;
    }

    while (!myStack.empty()) {
        postfix += myStack.top().getToken() + " ";
        myStack.pop();
    }

    cout << postfix << endl;

    return 0;
}
