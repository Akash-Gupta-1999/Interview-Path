#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper: Find rightmost node of a subtree
TreeNode* findLastRight(TreeNode* node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

// Helper: Handle deletion cases
TreeNode* helper(TreeNode* node) {
    if (!node->left) return node->right;
    if (!node->right) return node->left;

    TreeNode* lastRight = findLastRight(node->left);
    lastRight->right = node->right;
    return node->left;
}

// Iterative BST delete function
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;

    if (root->val == key) {
        return helper(root);
    }

    TreeNode* temp = root;
    while (root) {
        if (key < root->val) {
            if (root->left && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return temp;
}

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Inorder Traversal (to check BST validity after deletion)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
             5
            / \
           3   6
          / \    \
         2   4    7
    */
    vector<int> vals = {5, 3, 6, 2, 4, 7};
    TreeNode* root = NULL;
    for (int v : vals) root = insertBST(root, v);

    cout << "Original Inorder: ";
    inorder(root);
    cout << "\n";

    // 🔹 Test Case 1: Delete leaf node
    root = deleteNode(root, 2);
    cout << "After deleting 2: ";
    inorder(root);
    cout << "\n"; // Expected: 3 4 5 6 7

    // 🔹 Test Case 2: Delete node with one child
    root = deleteNode(root, 6);
    cout << "After deleting 6: ";
    inorder(root);
    cout << "\n"; // Expected: 3 4 5 7

    // 🔹 Test Case 3: Delete node with two children
    root = deleteNode(root, 3);
    cout << "After deleting 3: ";
    inorder(root);
    cout << "\n"; // Expected: 4 5 7

    // 🔹 Test Case 4: Delete root
    root = deleteNode(root, 5);
    cout << "After deleting 5: ";
    inorder(root);
    cout << "\n"; // Expected: 4 7

    return 0;
}
