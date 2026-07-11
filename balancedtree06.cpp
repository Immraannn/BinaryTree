// Balanced Binary Tree
// A Binary Tree is balanced if for every node, the difference between the heights of its left and right subtrees is at most 1.
// Mathematically,
// | Height(Left Subtree) - Height(Right Subtree) | ≤ 1


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
bool isBalanced(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}
