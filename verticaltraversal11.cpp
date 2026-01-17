#include <iostream>     // For input/output
#include <map>          // To store nodes according to horizontal distance (HD)
#include <queue>        // For level order traversal (BFS)
#include <vector>       // To store multiple nodes in same vertical line
using namespace std;

/*
    Definition of Binary Tree Node
*/
class Node {
public:
    int data;       // Value stored in the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to initialize node
    Node(int d) {
        data = d;           // Assign data
        left = NULL;        // Initially left child is NULL
        right = NULL;       // Initially right child is NULL
    }
};

/*
    Function: verticalOrderTraversal
    Purpose : Print nodes of binary tree in vertical order
*/
void verticalOrderTraversal(Node* root) {

    // If tree is empty, nothing to print
    if (root == NULL)
        return;

    /*
        Map to store nodes based on Horizontal Distance (HD)
        Key   -> Horizontal Distance
        Value -> List of nodes present at that HD
    */
    map<int, vector<int>> mp;

    /*
        Queue for level order traversal
        Each element stores:
        - Node pointer
        - Horizontal Distance of that node
    */
    queue<pair<Node*, int>> q;

    // Push root node with Horizontal Distance = 0
    q.push({root, 0});

    /*
        Perform level order traversal
    */
    while (!q.empty()) {

        // Get front element of queue
        pair<Node*, int> temp = q.front();
        q.pop();

        // Extract node and its horizontal distance
        Node* curr = temp.first;
        int hd = temp.second;

        // Store current node's data in map at its HD
        mp[hd].push_back(curr->data);

        /*
            If left child exists:
            - Horizontal Distance decreases by 1
            - Push left child into queue
        */
        if (curr->left != NULL) {
            q.push({curr->left, hd - 1});
        }

        /*
            If right child exists:
            - Horizontal Distance increases by 1
            - Push right child into queue
        */
        if (curr->right != NULL) {
            q.push({curr->right, hd + 1});
        }
    }

    /*
        Map stores keys in sorted order automatically
        So we print from leftmost vertical line to rightmost
    */
    for (auto it = mp.begin(); it != mp.end(); it++) {

        // Print all nodes present in one vertical line
        for (int value : it->second) {
            cout << value << " ";
        }

        // Move to next vertical line
        cout << endl;
    }
}