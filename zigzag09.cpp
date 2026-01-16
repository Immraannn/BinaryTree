#include <iostream>          // Required for input and output
#include <stack>             // Required to use stack data structure
using namespace std;

// Definition of a Binary Tree node
class Node {
public:
    int data;                // Stores value of the node
    Node* left;              // Pointer to left child
    Node* right;             // Pointer to right child

    // Constructor to initialize node
    Node(int val) {
        data = val;          // Assign value to data
        left = NULL;         // Initialize left child as NULL
        right = NULL;        // Initialize right child as NULL
    }
};

// Function to perform zigzag traversal
void zigzagTraversal(Node* root) {

    // If tree is empty, traversal is not possible
    if (root == NULL)
        return;

    // Stack to store nodes of current level
    stack<Node*> currentLevel;

    // Stack to store nodes of next level
    stack<Node*> nextLevel;

    // Boolean flag to control traversal direction
    // true  -> left to right
    // false -> right to left
    bool leftToRight = true;

    // Push root node into current level stack
    currentLevel.push(root);

    // Loop continues until all nodes are traversed
    while (!currentLevel.empty()) {

        // Take top node from current level stack
        Node* temp = currentLevel.top();

        // Remove that node from stack
        currentLevel.pop();

        // Print the value of the node
        cout << temp->data << " ";

        // If direction is left to right
        if (leftToRight) {

            // Push left child first into next level stack
            if (temp->left)
                nextLevel.push(temp->left);

            // Push right child after left child
            if (temp->right)
                nextLevel.push(temp->right);
        }
        // If direction is right to left
        else {

            // Push right child first into next level stack
            if (temp->right)
                nextLevel.push(temp->right);

            // Push left child after right child
            if (temp->left)
                nextLevel.push(temp->left);
        }

        // If current level stack becomes empty
        if (currentLevel.empty()) {

            // Move to next line for new level output
            cout << endl;

            // Change traversal direction
            leftToRight = !leftToRight;

            // Swap current level stack with next level stack
            swap(currentLevel, nextLevel);
        }
    }
}
