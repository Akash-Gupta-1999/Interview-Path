#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive LCA
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;   // p and q found in different subtrees
    return left ? left : right;       // either one side has both or NULL
}

// Helper: find a node by value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    return left ? left : findNode(root->right, val);
}

int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Test Case 1
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);
    cout << "LCA(5, 1) = " << lowestCommonAncestor(root, p, q)->val << "\n"; // ✅ Expected: 3

    // Test Case 2
    p = findNode(root, 6);
    q = findNode(root, 4);
    cout << "LCA(6, 4) = " << lowestCommonAncestor(root, p, q)->val << "\n"; // ✅ Expected: 5

    // Test Case 3
    p = findNode(root, 7);
    q = findNode(root, 8);
    cout << "LCA(7, 8) = " << lowestCommonAncestor(root, p, q)->val << "\n"; // ✅ Expected: 3

    return 0;
}
