#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper recursive function
void flattenRec(TreeNode* node, TreeNode*& prev) {
    if (!node) return;

    // Process right first (reverse preorder: right → left → root)
    flattenRec(node->right, prev);
    flattenRec(node->left, prev);

    // Rewire pointers
    node->right = prev;  // current node's right → previously visited node
    node->left = NULL;   // left must always be NULL
    prev = node;         // update prev to current
}

// Main function
void flatten(TreeNode* root) {
    TreeNode* prev = NULL;
    flattenRec(root, prev);
}

// Helper to print flattened linked list
void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << "\n";
}

int main() {
    /*
            1
           / \
          2   5
         / \   \
        3   4   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    cout << "Flattened tree (linked list): ";
    printFlattened(root);
    // ✅ Expected: 1 2 3 4 5 6

    return 0;
}
