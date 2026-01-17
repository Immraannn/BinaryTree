#include <iostream>
#include <map>
#include <queue>
using namespace std;

/*
  Structure of a binary tree node
*/
class Node {
public:
    int data;        // value of current node
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
  Function to print Bottom View of Binary Tree
*/
void bottomView(Node* root) {

    // Step 1: If tree is empty, nothing to print
    if (root == NULL)
        return;

    /*
      Step 2:
      Map to store bottommost node for each horizontal distance

      key   -> Horizontal Distance (HD)
      value -> Node data
    */
    map<int, int> bottomNode;

    /*
      Step 3:
      Queue for Level Order Traversal (BFS)

      Each element stores:
      (currentNode, itsHorizontalDistance)
    */
    queue<pair<Node*, int>> q;

    // Step 4: Start with root node at HD = 0
    q.push({root, 0});

    // Step 5: Traverse tree level by level
    while (!q.empty()) {

        // Get front element from queue
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* currentNode = temp.first; // actual node
        int hd = temp.second;            // its horizontal distance

        /*
          Step 6 (MOST IMPORTANT):
          Always overwrite the value for this HD.

          Why?
          Because deeper nodes appear later in BFS,
          and bottom view needs the deepest node.
        */
        bottomNode[hd] = currentNode->data;

        // Step 7: Move to left child (HD - 1)
        if (currentNode->left != NULL) {
            q.push({currentNode->left, hd - 1});
        }

        // Step 8: Move to right child (HD + 1)
        if (currentNode->right != NULL) {
            q.push({currentNode->right, hd + 1});
        }
    }

    /*
      Step 9:
      Print bottom view from leftmost HD to rightmost HD
    */
    for (auto it = bottomNode.begin(); it != bottomNode.end(); it++) {
        cout << it->second << " ";
    }
}