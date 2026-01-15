#include <algorithm>
using namespace std;

/*
    Definition of a Binary Tree Node
*/
class Node {
public:
    int data;        // Value stored in the node
    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child

    // Constructor to initialize node
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

/*
    Function: checkHeight
    ---------------------
    This function checks whether the subtree rooted at 'root'
    is height-balanced or not.

    Return value:
    - Returns height of subtree if it is balanced
    - Returns -1 if subtree is NOT balanced
*/
int checkHeight(Node* root) {

    // Base Case:
    // If current node is NULL, height is 0 and tree is balanced
    if (root == NULL) {
        return 0;
    }

    // Recursively check height of left subtree
    int leftHeight = checkHeight(root->left);

    // If left subtree is unbalanced, propagate -1 upward
    if (leftHeight == -1) {
        return -1;
    }

    // Recursively check height of right subtree
    int rightHeight = checkHeight(root->right);

    // If right subtree is unbalanced, propagate -1 upward
    if (rightHeight == -1) {
        return -1;
    }

    // Check balance condition at current node
    // If height difference is more than 1, tree is unbalanced
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    // If current node is balanced,
    // return height of subtree rooted at this node
    return max(leftHeight, rightHeight) + 1;
}

/*
    Function: isBalanced
    --------------------
    This function checks if the entire binary tree is balanced.

    Logic:
    - If checkHeight returns -1 → tree is unbalanced
    - Otherwise → tree is balanced
*/
bool isBalanced(Node* root) {

    // Call helper function and check its return value
    if (checkHeight(root) == -1) {
        return false;   // Tree is NOT balanced
    } else {
        return true;    // Tree IS balanced
    }
}
