pair<bool, int> isSumTreeFast(Node* root)
{
    // Base case: Empty tree
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // Base case: Leaf node
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // Get result from left subtree
    pair<bool, int> leftAns = isSumTreeFast(root->left);

    // Get result from right subtree
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    // Check Sum Tree property at current node
    bool condn = (root->data == leftAns.second + rightAns.second);

    pair<bool, int> ans;

    if (left && right && condn)
    {
        ans.first = true;

        // Sum of current subtree
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;
}
