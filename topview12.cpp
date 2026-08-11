vector<int> topView(node* root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    // HD -> first node at that HD
    map<int, int> mp;

    // Node + Horizontal Distance
    queue<pair<node*, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        node* current = temp.first;
        int hd = temp.second;

        // First node at this horizontal distance
        if (mp.find(hd) == mp.end())
        {
            mp[hd] = current->data;
        }

        // Left child → HD - 1
        if (current->left)
        {
            q.push({current->left, hd - 1});
        }

        // Right child → HD + 1
        if (current->right)
        {
            q.push({current->right, hd + 1});
        }
    }

    // map automatically gives HD from smallest to largest
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
