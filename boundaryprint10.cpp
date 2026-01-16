#include<iostream>
using namespace std;

/*
    Definition of a Binary Tree Node
*/
class Node {
public:
    int data;       // Stores value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to initialize a node
    Node(int d) {
        data = d;       // Assign data to node
        left = NULL;    // Initially, left child is NULL
        right = NULL;   // Initially, right child is NULL
    }
};

/*
    Function to print the LEFT boundary of the tree
    - Excludes leaf nodes
    - Traverses from top to bottom
*/
void printLeftBoundary(Node* root) {

    // Base case: if current node is NULL, stop recursion
    if (root == NULL) {
        return;
    }

    // If left child exists, this node is part of left boundary
    if (root->left != NULL) {

        // Print current node because it is NOT a leaf
        cout << root->data << " ";

        // Move to the left child
        printLeftBoundary(root->left);
    }

    // If left child does not exist but right child exists
    else if (root->right != NULL) {

        // Print current node because it is still part of left boundary
        cout << root->data << " ";

        // Move to the right child
        printLeftBoundary(root->right);
    }

    // If both children are NULL, it is a leaf node
    // We DO NOT print leaf nodes in left boundary
}

/*
    Function to print ALL leaf nodes of the tree
    - Uses inorder traversal
    - Prints from leftmost leaf to rightmost leaf
*/
void printLeafNodes(Node* root) {

    // Base case: if node is NULL, stop recursion
    if (root == NULL) {
        return;
    }

    // First, traverse left subtree
    printLeafNodes(root->left);

    // Check if current node is a leaf node
    if (root->left == NULL && root->right == NULL) {

        // Print the leaf node
        cout << root->data << " ";
    }

    // Finally, traverse right subtree
    printLeafNodes(root->right);
}

/*
    Function to print the RIGHT boundary of the tree
    - Excludes leaf nodes
    - Traverses bottom to top (reverse order)
*/
void printRightBoundary(Node* root) {

    // Base case: if current node is NULL, stop recursion
    if (root == NULL) {
        return;
    }

    // If right child exists, go down first
    if (root->right != NULL) {

        // First recurse to the right child
        printRightBoundary(root->right);

        // Print current node AFTER recursion (bottom-up order)
        cout << root->data << " ";
    }

    // If right child does not exist but left child exists
    else if (root->left != NULL) {

        // First recurse to the left child
        printRightBoundary(root->left);

        // Print current node AFTER recursion
        cout << root->data << " ";
    }

    // If both children are NULL, it is a leaf node
    // We DO NOT print leaf nodes in right boundary
}

/*
    Main function to perform BOUNDARY TRAVERSAL
    Order:
    1. Root
    2. Left Boundary
    3. Leaf Nodes
    4. Right Boundary (Reverse)
*/
void boundaryTraversal(Node* root) {

    // If tree is empty, nothing to print
    if (root == NULL) {
        return;
    }

    // Step 1: Print the root node
    cout << root->data << " ";

    // Step 2: Print left boundary starting from root's left child
    printLeftBoundary(root->left);

    // Step 3: Print all leaf nodes
    // Root is passed so both left and right subtree are covered
    printLeafNodes(root);

    // Step 4: Print right boundary starting from root's right child
    printRightBoundary(root->right);
}
