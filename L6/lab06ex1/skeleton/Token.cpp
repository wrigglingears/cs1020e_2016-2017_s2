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
    // Add your code here.

}


bool Token::isRightParenthesis() {
    // Add your code here.

}


bool Token::isOperator() {
    // Add your code here.

}


bool Token::isNumber() {
    // Add your code here.

}


bool Token::hasLowerPrecedenceThan(Token& another) {
    // Add your code here.

}


bool Token::hasEqualPrecedenceTo(Token& another) {
    // Add your code here.

}


string Token::getToken() {
    return _token;
}


void Token::setToken(string tokenStr) {
    _token = tokenStr;
}


    // Add more if necessary.
