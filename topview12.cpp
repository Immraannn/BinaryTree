#include <iostream>
#include <map>
#include <queue>
using namespace std;

/*
 A node of binary tree
*/
class Node {
public:
    int data;        // value stored in the node
    Node* left;      // pointer to left child
    Node* right;     // pointer to right child

    // constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

/*
 Function to print top view of binary tree
*/
void topView(Node* root) {

    // Step 1: If tree is empty, nothing to print
    if (root == NULL)
        return;

    /*
     Step 2:
     map<HD, nodeValue>

     HD (Horizontal Distance):
     root -> 0
     left child -> HD - 1
     right child -> HD + 1

     map automatically stores keys in sorted order
    */
    map<int, int> topNode;

    /*
     Step 3:
     Queue stores pair of:
     (currentNode, itsHorizontalDistance)

     Queue is used for LEVEL ORDER traversal
    */
    queue<pair<Node*, int>> q;

    // Step 4: Start with root at horizontal distance 0
    q.push({root, 0});

    // Step 5: Level order traversal
    while (!q.empty()) {

        // Take front element from queue
        pair<Node*, int> current = q.front();
        q.pop();

        Node* currentNode = current.first; // actual tree node
        int hd = current.second;            // horizontal distance

        /*
         Step 6:
         If this horizontal distance is seen for the first time,
         store the node value.
         This ensures TOPMOST node is stored.
        */
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = currentNode->data;
        }

        // Step 7: Push left child with HD - 1
        if (currentNode->left != NULL) {
            q.push({currentNode->left, hd - 1});
        }

        // Step 8: Push right child with HD + 1
        if (currentNode->right != NULL) {
            q.push({currentNode->right, hd + 1});
        }
    }

    /*
     Step 9:
     Print the stored nodes from leftmost HD to rightmost HD
    */
    for (auto it = topNode.begin(); it != topNode.end(); it++) {
        cout << it->second << " ";
    }
}