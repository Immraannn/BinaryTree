#include <iostream>
using namespace std;
int height(node* root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Iterative way

int height(BinaryTreeNode<int>* root) {

    // Case 1: Empty tree
    if(root == NULL) {
        return 0;
    }

    queue<BinaryTreeNode<int>*> q;

    // Step 1: Push root into queue
    q.push(root);

    int height = 0;

    // Step 2: Loop until all levels are processed
    while(!q.empty()) {

        // Number of nodes in current level
        int levelSize = q.size();

        // Step 3: Process all nodes of this level
        for(int i = 0; i < levelSize; i++) {

            BinaryTreeNode<int>* temp = q.front();
            q.pop();

            // Push left child
            if(temp->left != NULL) {
                q.push(temp->left);
            }

            // Push right child
            if(temp->right != NULL) {
                q.push(temp->right);
            }
        }

        // Step 4: One complete level finished
        height++;
    }

    return height;
}
