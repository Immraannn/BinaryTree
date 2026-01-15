// Global variable to store the maximum diameter found so far
int diameter = 0;

// Function to calculate height of tree and update diameter
int height(TreeNode* root) {

    // Base case: if current node is NULL
    // Height of an empty tree is 0
    if (root == NULL)
        return 0;

    // Recursively calculate height of left subtree
    int leftHeight = height(root->left);

    // Recursively calculate height of right subtree
    int rightHeight = height(root->right);

    // Diameter at current node is:
    // longest path going through this node
    // = left subtree height + right subtree height
    int currentDiameter = leftHeight + rightHeight;

    // Update the global diameter if current is larger
    diameter = max(diameter, currentDiameter);

    // Height of current node =
    // 1 (current node) + maximum height of its subtrees
    return 1 + max(leftHeight, rightHeight);
}

// Function that user calls to get diameter
int diameterOfBinaryTree(TreeNode* root) {

    // Initialize diameter to 0 before calculation
    diameter = 0;

    // Call height function to compute heights
    // Diameter is updated during recursion
    height(root);

    // Return the final diameter (in terms of edges)
    return diameter;
}
