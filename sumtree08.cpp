#include <iostream>
using namespace std;

// Returns true if tree is a Sum Tree
bool isSumTree(Node* root)
{
    // Empty tree is a Sum Tree
    if (root == NULL)
        return true;

    // Leaf node is always a Sum Tree
    if (root->left == NULL && root->right == NULL)
        return true;

    // Find sum of left subtree
    int leftSum = sum(root->left);

    // Find sum of right subtree
    int rightSum = sum(root->right);

    // Check current node
    bool current = (root->data == leftSum + rightSum);

    // Check left subtree
    bool left = isSumTree(root->left);

    // Check right subtree
    bool right = isSumTree(root->right);

    // Tree is Sum Tree only if
    // current node, left subtree and right subtree satisfy the condition
    return current && left && right;
}
