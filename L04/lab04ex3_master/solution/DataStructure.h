//=====================================================================
// FILE: DataStructure.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

class DataStructure {
private:
    int _id;
    DataStructure* next;
    DataStructure* prev;

public:
    DataStructure();
    DataStructure(int ID);
    DataStructure(int ID, DataStructure* Prev, DataStructure* Next);

    int getID();
    DataStructure* del();
    void insert(int ID);
    DataStructure* move();
};

#endif
