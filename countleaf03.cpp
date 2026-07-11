// Function to count total leaf nodes
int countLeafNodes(node* root)
{
    // Base Case: Empty tree
    if (root == NULL)
        return 0;

    // If current node has no children,
    // it is a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Count leaf nodes in left subtree
    int leftLeaves = countLeafNodes(root->left);

    // Count leaf nodes in right subtree
    int rightLeaves = countLeafNodes(root->right);

    // Total leaf nodes
    return leftLeaves + rightLeaves;
}
