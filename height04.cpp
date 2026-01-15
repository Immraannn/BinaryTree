int height(BinaryTreeNode<int>* root) {

    // Base case:
    // Empty tree has height 0
    if(root == NULL) {
        return 0;
    }

    // Find height of left subtree
    int leftHeight = height(root->left);

    // Find height of right subtree
    int rightHeight = height(root->right);

    // Height of current node =
    // 1 (current node) + maximum of both subtrees
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
