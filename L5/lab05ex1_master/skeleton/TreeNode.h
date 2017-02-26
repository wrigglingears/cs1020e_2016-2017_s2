//=====================================================================
// FILE: TreeNode.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <your name>
// MATRIC NO.  : <matric no.>
// NUS EMAIL   : <your NUS email address>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef TreeNode_h
#define TreeNode_h

class TreeNode {
private:
    int _elem;         // The integer element in the node.
    TreeNode* _left;   // Pointer to the left child node.
    TreeNode* _right;  // Pointer to the right child node.

public:
    TreeNode();
    TreeNode(int elem);

    int getElement();
    TreeNode* getLeftChild();
    TreeNode* getRightChild();
    void setElement(int elem);
    void setLeftChild(TreeNode* node);
    void setRightChild(TreeNode* node);

    // Add more if necessary.

};

#endif
