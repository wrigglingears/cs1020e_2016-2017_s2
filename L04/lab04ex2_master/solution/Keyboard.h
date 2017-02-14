//=====================================================================
// FILE: Keyboard.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef keyboard_h
#define keyboard_h

class Keyboard {
private:
    struct Node {
        char letter;
        Node *prev;
        Node *next;
    };

    Node *_head;
    Node *_tail;
    Node *_cursor;

public:
    Keyboard();
    void moveCursorLeft(int k);
    void moveCursorRight(int k);
    void insertChar(char newLetter);
    void deleteChar();
    void printLine();
};

#endif
