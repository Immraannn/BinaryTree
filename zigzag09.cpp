
class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> result;

        // If tree is empty
        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);

        // true  -> Left to Right
        // false -> Right to Left
        bool leftToRight = true;

        while (!q.empty())
        {
            // Number of nodes in current level
            int size = q.size();

            // Store current level's nodes
            vector<int> ans(size);

            // Process every node of current level
            for (int i = 0; i < size; i++)
            {
                Node *frontNode = q.front();
                q.pop();

                // Decide correct index based on traversal direction
                int index = leftToRight ? i : size - i - 1;

                // Store node at correct position
                ans[index] = frontNode->data;

                // Push left child
                if (frontNode->left)
                    q.push(frontNode->left);

                // Push right child
                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // Copy current level into final answer
            for (auto i : ans)
                result.push_back(i);

            // Change direction for next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};
