
int countLeafNodes(node* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int leftLeaves = countLeafNodes(root->left);
    int rightLeaves = countLeafNodes(root->right);
    return leftLeaves + rightLeaves;
}
