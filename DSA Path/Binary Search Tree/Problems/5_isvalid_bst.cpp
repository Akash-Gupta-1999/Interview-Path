#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return helper(root->left, minVal, root->val) &&
           helper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return helper(root, LLONG_MIN, LLONG_MAX);
}

/// ---------- Test cases ----------
int main() {
    /*
            5
           / \
          3   7
         / \   \
        2   4   8
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    cout << (isValidBST(root) ? "Valid BST" : "Not a BST") << endl;

    // Breaking BST rule: left child > parent
    root->left->right->val = 6;
    cout << (isValidBST(root) ? "Valid BST" : "Not a BST") << endl;

    return 0;
}
