#include <iostream>
#include <vector>
using namespace std;

/* ----------- Binary Tree Node Structure ----------- */
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* --------------------------------------------------
   Recursive function to find K-sum paths
   root  -> current node
   k     -> target sum
   path  -> stores path from root to current node
   count -> number of valid paths found
--------------------------------------------------- */
void solve(Node* root, int k, vector<int>& path, int& count) {

    // Base case: if node is NULL, stop recursion
    if (root == NULL)
        return;

    // 1️⃣ Add current node value to path
    path.push_back(root->data);

    // 2️⃣ Check all downward paths ending at this node
    int sum = 0;

    // Traverse path from current node to root
    for (int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];      // increment sum
        if (sum == k) {      // check if sum equals K
            count++;
        }
    }

    // 3️⃣ Recursively visit left subtree
    solve(root->left, k, path, count);

    // 4️⃣ Recursively visit right subtree
    solve(root->right, k, path, count);

    // 5️⃣ Backtracking: remove current node before returning
    path.pop_back();
}

/* ----------- Wrapper Function ----------- */
int kSumPaths(Node* root, int k) {
    vector<int> path;  // stores root → current path
    int count = 0;     // stores number of valid paths

    solve(root, k, path, count);
    return count;
}

/* ---------------- MAIN FUNCTION ---------------- */
int main() {

    /*
            4
           / \
          2   5
         / \
        1   3
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    int K = 6;

    int result = kSumPaths(root, K);

    cout << "Number of K-sum paths = " << result << endl;

    return 0;
}
