#include <bits/stdc++.h>
using namespace std;

/* 
   Definition of a Binary Tree Node
*/
struct Node {
    int data;        // Value of current node
    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child

    // Constructor to initialize node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
private:

    /*
        Recursive helper function
        root    → current node
        currLen → length of current root-to-node path
        currSum → sum of current root-to-node path
        maxLen  → maximum length found so far (passed by reference)
        maxSum  → sum corresponding to maximum length (passed by reference)
    */
    void solve(Node* root, int currLen, int currSum,
               int &maxLen, int &maxSum) {

        // Base case: if current node is NULL, stop recursion
        if (root == NULL)
            return;

        // Increase path length as we go down
        currLen++;

        // Add current node value to path sum
        currSum += root->data;

        // Check if current node is a leaf node
        if (root->left == NULL && root->right == NULL) {

            // If current path length is greater than maximum length found
            if (currLen > maxLen) {
                maxLen = currLen;      // Update maximum length
                maxSum = currSum;      // Update sum for this length
            }
            // If path length is same as maximum, choose max sum
            else if (currLen == maxLen) {
                maxSum = max(maxSum, currSum);
            }
        }

        // Recur for left subtree
        solve(root->left, currLen, currSum, maxLen, maxSum);

        // Recur for right subtree
        solve(root->right, currLen, currSum, maxLen, maxSum);
    }

public:

    /*
        Main function to return sum of longest bloodline
    */
    int sumOfLongestBloodline(Node* root) {

        // Stores maximum path length from root to leaf
        int maxLen = 0;

        // Stores sum of nodes on the longest path
        int maxSum = 0;

        // Start recursive traversal from root
        solve(root, 0, 0, maxLen, maxSum);

        // Return final answer
        return maxSum;
    }
};
