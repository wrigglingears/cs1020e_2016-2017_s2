//=====================================================================
// FILE: BinarySearchTree.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "TreeNode.h"


class BinarySearchTree {
private:
    TreeNode* _root;  // Pointer to the root node of the BST.

public:
    BinarySearchTree();

    bool isEmpty();
    void insert(int elem);
    int findMin();
    int findMax();
    int findDepth(int elem);
};

#endif
