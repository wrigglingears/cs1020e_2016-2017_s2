//=====================================================================
// FILE: Token.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef Token_h
#define Token_h

#include <string>
using namespace std;

class Token {
private:
    string _token;

public:
    Token(string tokenStr);
    bool isLeftParenthesis();
    bool isRightParenthesis();
    bool isNumber();
    bool isOperator();
    bool hasLowerPrecedenceThan(Token& another);
    bool hasEqualPrecedenceTo(Token& another);
    string getToken();
    void setToken(string tokenStr);

    // Add more if necessary.
};

#endif
