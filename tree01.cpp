#include<iostream>          // For input-output operations (cin, cout)
#include<queue>             // For using queue STL
using namespace std;        // To avoid writing std:: repeatedly

// Class representing a single node of Binary Tree
class node {
    public:
        int data;           // Stores data of the node
        node* left;         // Pointer to left child
        node* right;        // Pointer to right child

    // Constructor to initialize a node
    node(int d) {
        this->data = d;     // Assign data to node
        this->left = NULL; // Initialize left child as NULL
        this->right = NULL;// Initialize right child as NULL
    }
};

// Function to build tree using recursion (Preorder style)
node* buildTree(node* root) {

    cout << "Enter the data: " << endl; // Ask user for node data
    int data;
    cin >> data;                        // Take input

    // If user enters -1, this node does not exist
    if(data == -1) {
        return NULL;                    // Return NULL pointer
    }

    // Create a new node with given data
    root = new node(data);    

    // Build left subtree
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    // Build right subtree
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;                        // Return root of subtree
}

// Function to print tree level by level
void levelOrderTraversal(node* root) {

    queue<node*> q;                     // Queue to store nodes
    q.push(root);                       // Push root node
    q.push(NULL);                       // NULL marks end of level

    while(!q.empty()) {                 // Loop until queue is empty

        node* temp = q.front();         // Get front node
        q.pop();                        // Remove it from queue

        // If NULL encountered, one level is completed
        if(temp == NULL) { 
            cout << endl;               // Move to next line

            // If queue still has nodes, push NULL again
            if(!q.empty()) { 
                q.push(NULL);
            }  
        }
        else {
            cout << temp->data << " ";  // Print current node data

            // If left child exists, push into queue
            if(temp->left) {
                q.push(temp->left);
            }

            // If right child exists, push into queue
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Inorder Traversal: Left → Root → Right
void inorder(node* root) {

    // Base case: if tree is empty
    if(root == NULL) {
        return;
    }

    inorder(root->left);               // Visit left subtree
    cout << root->data << " ";         // Print root
    inorder(root->right);              // Visit right subtree
}

// Preorder Traversal: Root → Left → Right
void preorder(node* root) {

    // Base case
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";         // Print root
    preorder(root->left);              // Visit left subtree
    preorder(root->right);             // Visit right subtree
}

// Postorder Traversal: Left → Right → Root
void postorder(node* root) {

    // Base case
    if(root == NULL) {
        return;
    }

    postorder(root->left);             // Visit left subtree
    postorder(root->right);            // Visit right subtree
    cout << root->data << " ";         // Print root
}

// Function to build tree using Level Order Traversal
void buildFromLevelOrder(node* &root) {

    queue<node*> q;                    // Queue for level order build

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;                       // Read root data

    root = new node(data);             // Create root node
    q.push(root);                      // Push root into queue

    while(!q.empty()) {                // Loop till queue is empty

        node* temp = q.front();        // Get front node
        q.pop();                       // Remove it

        // Input for left child
        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        // If left child exists
        if(leftData != -1) {
            temp->left = new node(leftData); // Create left child
            q.push(temp->left);              // Push into queue
        }

        // Input for right child
        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        // If right child exists
        if(rightData != -1) {
            temp->right = new node(rightData); // Create right child
            q.push(temp->right);               // Push into queue
        }
    }
}

int main() {

    node* root = NULL;                 // Initialize root pointer

    // Build tree using level order input
    buildFromLevelOrder(root);

    // Print level order traversal
    levelOrderTraversal(root);

    // Sample Input:
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    /*
    // Alternative: Build tree using recursion
    root = buildTree(root);

    // Sample Input:
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout << "Printing the level order traversal output" << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal is: ";
    inorder(root);

    cout << endl << "Preorder traversal is: ";
    preorder(root);

    cout << endl << "Postorder traversal is: ";
    postorder(root);
    */

    return 0;                          // Program ends
}
