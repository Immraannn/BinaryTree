bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    if(root1 == NULL || root2 == NULL) {
        return false;
    }
    if(root1->data != root2->data) {
        return false;
    }
    bool leftSame  = isIdentical(root1->left, root2->left);
    bool rightSame = isIdentical(root1->right, root2->right);
    // Trees are identical only if both subtrees are identical
    return leftSame && rightSame;
}
