vector<int> verticalOrder(node* root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    // HD -> nodes
    map<int, vector<int>> mp;

    // Node -> HD
    queue<pair<node*, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        pair<node*, int> temp = q.front();
        q.pop();

        node* current = temp.first;
        int hd = temp.second;

        mp[hd].push_back(current->data);

        // Left child gets HD - 1
        if (current->left)
            q.push({current->left, hd - 1});

        // Right child gets HD + 1
        if (current->right)
            q.push({current->right, hd + 1});
    }

    // Traverse map from smallest HD to largest HD
    for (auto it : mp)
    {
        for (int value : it.second)
        {
            ans.push_back(value);
        }
    }

    return ans;
}
