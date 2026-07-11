// Diameter of a Binary Tree
// The diameter of a binary tree is the length of the longest path between any two nodes.
// The longest path may or may not pass through the root.


#include <iostream>
using namespace std;

// Returns height of tree
int height(node* root)
{
    // Empty tree has height 0
    if(root == NULL)
        return 0;

    // Height of left subtree
    int leftHeight = height(root->left);

    // Height of right subtree
    int rightHeight = height(root->right);

    // Height of current node
    return 1 + max(leftHeight, rightHeight);
}

// Returns diameter of tree
int diameter(node* root)
{
    // Empty tree
    if(root == NULL)
        return 0;

    // Diameter in left subtree
    int leftDiameter = diameter(root->left);

    // Diameter in right subtree
    int rightDiameter = diameter(root->right);

    // Height of left subtree
    int leftHeight = height(root->left);

    // Height of right subtree
    int rightHeight = height(root->right);

    // Diameter passing through current node
    int currentDiameter = leftHeight + rightHeight + 1;

    // Return maximum among all possibilities
    return max(currentDiameter,
               max(leftDiameter, rightDiameter));
}
