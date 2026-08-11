#include <iostream>
#include <utility>
using namespace std;

// Node of Binary Tree
class node
{
public:
    int data;
    node* left;
    node* right;

    // Constructor
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};


// Function to find:
// 1. Length of longest root-to-leaf path
// 2. Sum of nodes on that path
pair<int, int> solve(node* root)
{
    // Base case:
    // Empty tree has length 0 and sum 0
    if (root == NULL)
    {
        return {0, 0};
    }


    // Recursively find longest path in left subtree
    pair<int, int> left = solve(root->left);


    // Recursively find longest path in right subtree
    pair<int, int> right = solve(root->right);


    // If left path is longer
    if (left.first > right.first)
    {
        return {
            left.first + 1,          // Increase length by 1
            left.second + root->data // Add current node's value
        };
    }


    // If right path is longer
    else if (right.first > left.first)
    {
        return {
            right.first + 1,          // Increase length by 1
            right.second + root->data // Add current node's value
        };
    }


    // If both paths have the same length
    else
    {
        // Choose the path having the greater sum
        return {
            left.first + 1,
            root->data + max(left.second, right.second)
        };
    }
}


int main()
{
    /*
                1
               / \
              2   3
             / \
            4   5
    */

    // Create tree
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);


    // Call solve()
    pair<int, int> answer = solve(root);


    // answer.first = length
    // answer.second = sum
    cout << "Length of longest bloodline: "
         << answer.first << endl;

    cout << "Sum of longest bloodline: "
         << answer.second << endl;


    return 0;
}
