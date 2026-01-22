#include <iostream>
using namespace std;

/*
    Definition of a Binary Tree Node
*/
struct Node {
    int data;            // Value of node
    Node* left;          // Pointer to left child
    Node* right;         // Pointer to right child

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/*
    Function to find Lowest Common Ancestor (LCA)
    of two nodes n1 and n2 in a Binary Tree
*/
Node* findLCA(Node* root, int n1, int n2) {

    // 1️⃣ Base Case: empty tree
    if (root == NULL)
        return NULL;

    // 2️⃣ If current node is one of the required nodes,
    // return it directly
    if (root->data == n1 || root->data == n2)
        return root;

    // 3️⃣ Recursively search in left subtree
    // (this call COMPLETES fully before moving ahead)
    Node* leftResult = findLCA(root->left, n1, n2);

    // 4️⃣ Recursively search in right subtree
    // (this call starts only after leftResult is ready)
    Node* rightResult = findLCA(root->right, n1, n2);

    // 5️⃣ If both left and right return non-NULL,
    // current node is the Lowest Common Ancestor
    if (leftResult != NULL && rightResult != NULL)
        return root;

    // 6️⃣ Otherwise, return the non-NULL child (if any)
    if (leftResult != NULL)
        return leftResult;

    return rightResult;   // may be NULL or valid node
}
