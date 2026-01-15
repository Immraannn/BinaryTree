#include <iostream>          // For input and output operations
#include <queue>             // For using queue in level order traversal
using namespace std;         // To avoid writing std:: again and again

// Class to represent each node of the binary tree
class Node {
public:
    int data;               // Stores value of the node
    Node* left;             // Pointer to left child
    Node* right;            // Pointer to right child

    // Constructor to initialize node
    Node(int d) {
        data = d;           // Assign data to node
        left = NULL;        // Initialize left child as NULL
        right = NULL;       // Initialize right child as NULL
    }
};

// Function to build binary tree using level order input
Node* buildTree() {
    int data;                                   // Variable to store node data
    cout << "Enter root data: ";                // Ask user for root value
    cin >> data;                                // Read root value

    // If user enters -1, tree is empty
    if (data == -1)
        return NULL;

    // Create root node
    Node* root = new Node(data);

    // Queue to store nodes for level order construction
    queue<Node*> q;
    q.push(root);                               // Push root node into queue

    // Loop until all nodes are processed
    while (!q.empty()) {

        Node* temp = q.front();                 // Take front node from queue
        q.pop();                                // Remove it from queue

        int leftData, rightData;                // Variables for children data

        // Input left child
        cout << "Enter left child of " << temp->data << ": ";
        cin >> leftData;

        // If left child exists
        if (leftData != -1) {
            temp->left = new Node(leftData);    // Create left child node
            q.push(temp->left);                 // Push left child into queue
        }

        // Input right child
        cout << "Enter right child of " << temp->data << ": ";
        cin >> rightData;

        // If right child exists
        if (rightData != -1) {
            temp->right = new Node(rightData);  // Create right child node
            q.push(temp->right);                // Push right child into queue
        }
    }

    return root;                                // Return root of constructed tree
}

// Function that checks Sum Tree property and returns subtree sum
int checkSumTree(Node* root) {

    // Base case: empty tree has sum = 0
    if (root == NULL)
        return 0;

    // If node is a leaf, it is always a Sum Tree
    if (root->left == NULL && root->right == NULL)
        return root->data;

    // Recursively calculate sum of left subtree
    int leftSum = checkSumTree(root->left);

    // Recursively calculate sum of right subtree
    int rightSum = checkSumTree(root->right);

    // If any subtree is not a Sum Tree
    if (leftSum == -1 || rightSum == -1)
        return -1;

    // Check Sum Tree condition for current node
    if (root->data != leftSum + rightSum)
        return -1;

    // Return sum of current subtree (node + children)
    return root->data + leftSum + rightSum;
}

// Wrapper function to check Sum Tree
bool isSumTree(Node* root) {

    // If checkSumTree does not return -1, it is a Sum Tree
    return checkSumTree(root) != -1;
}

// Main function
int main() {

    // Build binary tree from user input
    Node* root = buildTree();

    // Check and print result
    if (isSumTree(root))
        cout << "\nTree is a SUM TREE ✅" << endl;
    else
        cout << "\nTree is NOT a SUM TREE ❌" << endl;

    return 0;                                   // End of program
}
