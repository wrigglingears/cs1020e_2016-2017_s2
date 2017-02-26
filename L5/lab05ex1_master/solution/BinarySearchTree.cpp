//=====================================================================
// FILE: BinarySearchTree.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <cstdlib>
#include "BinarySearchTree.h"
using namespace std;


BinarySearchTree::BinarySearchTree()
: _root(NULL) {
}


bool BinarySearchTree::isEmpty() {
    return (_root == NULL);
}


void BinarySearchTree::insert(int elem) {
    TreeNode *newNode = new TreeNode(elem);

    if (isEmpty()) {
        _root = newNode;
    } else {
        TreeNode* parentNode = NULL;
        TreeNode* currNode = _root;
        bool isLeftChild;

        while (currNode != NULL) {
            parentNode = currNode;
            if (elem <= currNode->getElement()) {
                currNode = currNode->getLeftChild();
                isLeftChild = true;
            } else {
                currNode = currNode->getRightChild();
                isLeftChild = false;
            }
        }

        if (isLeftChild)
            parentNode->setLeftChild(newNode);
        else
            parentNode->setRightChild(newNode);
    }
}


int BinarySearchTree::findMin() {
    if (isEmpty()) return 0;

    TreeNode* currNode = _root;
    while (currNode->getLeftChild() != NULL) 
        currNode = currNode->getLeftChild();
    return currNode->getElement();
}


int BinarySearchTree::findMax() {
    if (isEmpty()) return 0;

    TreeNode* currNode = _root;
    while (currNode->getRightChild() != NULL) 
        currNode = currNode->getRightChild();
    return currNode->getElement();
}


int BinarySearchTree::findDepth(int elem) {
    int height = 1;
    TreeNode* currNode = _root;

    while (currNode != NULL) {
        if (elem == currNode->getElement()) {
            return height;
        } else if (elem < currNode->getElement()) {
            currNode = currNode->getLeftChild();
        } else {
            currNode = currNode->getRightChild();
        }
        height++;
    }
    return 0;  // elem is not found in the tree.
}
