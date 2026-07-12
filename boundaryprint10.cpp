class Solution
{
public:

    /*
        Store the LEFT boundary of the tree
        - Excludes leaf nodes
        - Traverses from top to bottom
    */
    void printLeftBoundary(Node* root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->left != NULL)
        {
            ans.push_back(root->data);
            printLeftBoundary(root->left, ans);
        }
        else if (root->right != NULL)
        {
            ans.push_back(root->data);
            printLeftBoundary(root->right, ans);
        }

        // Leaf nodes are ignored
    }

    /*
        Store all LEAF nodes
        - Left to Right
    */
    void printLeafNodes(Node* root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        printLeafNodes(root->left, ans);

        if (root->left == NULL && root->right == NULL)
            ans.push_back(root->data);

        printLeafNodes(root->right, ans);
    }

    /*
        Store the RIGHT boundary
        - Excludes leaf nodes
        - Bottom to Top
    */
    void printRightBoundary(Node* root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->right != NULL)
        {
            printRightBoundary(root->right, ans);
            ans.push_back(root->data);
        }
        else if (root->left != NULL)
        {
            printRightBoundary(root->left, ans);
            ans.push_back(root->data);
        }

        // Leaf nodes are ignored
    }

    /*
        Boundary Traversal
        Order:
        1. Root
        2. Left Boundary
        3. Leaf Nodes
        4. Right Boundary
    */
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        // Root
        ans.push_back(root->data);

        // Left Boundary
        printLeftBoundary(root->left, ans);

        // Leaf Nodes
        printLeafNodes(root, ans);

        // Right Boundary
        printRightBoundary(root->right, ans);

        return ans;
    }
};
