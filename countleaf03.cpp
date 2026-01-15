void inorder(BinaryTreeNode<int> *root, int &count) {
    
    // Base case: if current node is NULL, stop recursion
    if(root == NULL) {
        return;
    }

    // Step 1: Traverse the left subtree
    inorder(root->left, count);
    
    // Step 2: Check if current node is a leaf node
    // A leaf node has no left child and no right child
    if(root->left == NULL && root->right == NULL) {
        count++;   // Increment leaf node count
    }

    // Step 3: Traverse the right subtree
    inorder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root) {
    
    int cnt = 0;          // Initialize leaf node counter
    
    inorder(root, cnt);  // Call inorder traversal to count leaf nodes
    
    return cnt;          // Return total number of leaf nodes
}