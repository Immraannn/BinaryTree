#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};


// Function to check whether the tree is a Sum Tree
bool isSumTree(node* root)
{
    // Empty tree is a Sum Tree
    if (root == NULL)
        return true;


    // Leaf node is automatically a Sum Tree
    if (root->left == NULL && root->right == NULL)
        return true;


    // Find sum of left subtree
    int leftSum = sum(root->left);


    // Find sum of right subtree
    int rightSum = sum(root->right);


    // Current node must equal
    // sum of left and right subtrees
    if (root->data != leftSum + rightSum)
        return false;


    // Check left subtree
    bool left = isSumTree(root->left);


    // Check right subtree
    bool right = isSumTree(root->right);


    // Both subtrees must also be Sum Trees
    return left && right;
}


// Function to calculate sum of all nodes
int sum(node* root)
{
    // Empty tree has sum 0
    if (root == NULL)
        return 0;

    return root->data
         + sum(root->left)
         + sum(root->right);
}


int main()
{
    /*
              16
             /  \
           10    6
          / \   / \
         4   6 3   3
    */

    node* root = new node(16);

    root->left = new node(10);
    root->right = new node(6);

    root->left->left = new node(4);
    root->left->right = new node(6);

    root->right->left = new node(3);
    root->right->right = new node(3);


    if (isSumTree(root))
        cout << "Tree is a Sum Tree" << endl;
    else
        cout << "Tree is not a Sum Tree" << endl;


    return 0;
}
