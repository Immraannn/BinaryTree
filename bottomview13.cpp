vector<int> bottomView(node* root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> mp;

    queue<pair<node*, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        node* current = temp.first;
        int hd = temp.second;

        // Always update
        mp[hd] = current->data;

        if (current->left)
        {
            q.push({current->left, hd - 1});
        }

        if (current->right)
        {
            q.push({current->right, hd + 1});
        }
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
