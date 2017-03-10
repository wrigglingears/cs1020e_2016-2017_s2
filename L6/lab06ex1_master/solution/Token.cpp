//=====================================================================
// FILE: Token.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include "Token.h"


Token::Token(string tokenStr): _token(tokenStr) {
}

bool Token::isLeftParenthesis() {
    if (_token == "(") return true;
    return false;
}

bool Token::isRightParenthesis() {
    if (_token == ")") return true;
    return false;
}

bool Token::isOperator() {
    if (_token == "+") return true;
    if (_token == "-") return true;
    if (_token == "*") return true;
    if (_token == "/") return true;
    return false;
}

bool Token::isNumber() {
    if (isRightParenthesis()) return false;
    if (isLeftParenthesis()) return false;
    if (isOperator()) return false;
    return true;
}

bool Token::hasLowerPrecedenceThan(Token& another) {
    if ((_token == "+" || _token == "-") && 
        (another.getToken() == "*" || another.getToken() == "/")) 
        return true;
    return false;
}

bool Token::hasEqualPrecedenceTo(Token& another) {
    if ((_token == "+" || _token == "-") && 
        (another.getToken() == "+" || another.getToken() == "-")) 
        return true;
    if ((_token == "*" || _token == "/") && 
        (another.getToken() == "*" || another.getToken() == "/")) 
        return true;
    return false;
}

string Token::getToken() {
    return _token;
}

void Token::setToken(string tokenStr) {
    _token = tokenStr;
}
