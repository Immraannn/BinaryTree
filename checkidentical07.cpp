bool isIdentical(Node* root1, Node* root2) {

    // Case 1: If both trees are empty, they are identical
    if(root1 == NULL && root2 == NULL) {
        return true;
    }

    // Case 2: If one tree is empty and the other is not, not identical
    if(root1 == NULL || root2 == NULL) {
        return false;
    }

    // Case 3: If data of current nodes is not same, not identical
    if(root1->data != root2->data) {
        return false;
    }

    // Recursively check left subtree and right subtree
    bool leftSame  = isIdentical(root1->left, root2->left);
    bool rightSame = isIdentical(root1->right, root2->right);

    // Trees are identical only if both subtrees are identical
    return leftSame && rightSame;
}
