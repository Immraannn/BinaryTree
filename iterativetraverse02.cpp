// ================= ITERATIVE INORDER TRAVERSAL =================
// Left -> Root -> Right
void inorderIterative(node* root) {

    stack<node*> s;            // Stack to store nodes (simulates recursion)
    node* curr = root;         // Start traversal from root node

    // Loop runs until all nodes are processed
    while(curr != NULL || !s.empty()) {

        // Move to the extreme left node
        while(curr != NULL) {
            s.push(curr);      // Save current node in stack
            curr = curr->left;// Move to left child
        }

        // Now leftmost node is reached
        curr = s.top();        // Get top node from stack
        s.pop();               // Remove it from stack

        cout << curr->data << " "; // Print node data (Root)

        curr = curr->right;    // Move to right subtree
    }
}


// ================= ITERATIVE PREORDER TRAVERSAL =================
// Root -> Left -> Right
void preorderIterative(node* root) {

    if(root == NULL)           // If tree is empty
        return;                // Nothing to traverse

    stack<node*> s;            // Stack to store nodes
    s.push(root);              // Push root node first

    // Continue until stack becomes empty
    while(!s.empty()) {

        node* curr = s.top();  // Get top node
        s.pop();               // Remove it from stack

        cout << curr->data << " "; // Print root data first

        // Push right child first
        // So that left child is processed first
        if(curr->right) {
            s.push(curr->right);
        }

        // Push left child
        if(curr->left) {
            s.push(curr->left);
        }
    }
}


// ================= ITERATIVE POSTORDER TRAVERSAL =================
// Left -> Right -> Root (Using Two Stacks)
void postorderIterative(node* root) {

    if(root == NULL)           // If tree is empty
        return;

    stack<node*> s1;           // First stack for processing
    stack<node*> s2;           // Second stack for output order

    s1.push(root);             // Push root into first stack

    // Process until first stack is empty
    while(!s1.empty()) {

        node* curr = s1.top();// Get top node
        s1.pop();              // Remove it from first stack

        s2.push(curr);         // Push node into second stack

        // Push left child into first stack
        if(curr->left) {
            s1.push(curr->left);
        }

        // Push right child into first stack
        if(curr->right) {
            s1.push(curr->right);
        }
    }

    // Print nodes from second stack
    while(!s2.empty()) {
        cout << s2.top()->data << " "; // Print root after children
        s2.pop();                      // Remove printed node
    }
}


// ================= ITERATIVE LEVEL ORDER TRAVERSAL =================
// Breadth First Search (BFS)
void levelOrderIterative(node* root) {

    if(root == NULL)           // If tree is empty
        return;

    queue<node*> q;            // Queue for BFS
    q.push(root);              // Insert root node

    // Continue until queue becomes empty
    while(!q.empty()) {

        node* curr = q.front();// Get front node
        q.pop();               // Remove it from queue

        cout << curr->data << " "; // Print node data

        // Insert left child if exists
        if(curr->left) {
            q.push(curr->left);
        }

        // Insert right child if exists
        if(curr->right) {
            q.push(curr->right);
        }
    }
}
