#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🔹 Helper function: computes max path sum through this node
int pathsum(TreeNode* root, int& maxpath) {
    if (!root) return 0;

    // Best sum from left & right, ignore negatives
    int left = max(0, pathsum(root->left, maxpath));
    int right = max(0, pathsum(root->right, maxpath));

    // Update global max: best path THROUGH this node
    maxpath = max(maxpath, left + right + root->val);

    // Return best single path to parent
    return root->val + max(left, right);
}

// 🔹 Main function to get max path sum
int maxPathSum(TreeNode* root) {
    int maxpath = INT_MIN;
    pathsum(root, maxpath);
    return maxpath;
}

// 🔹 Test cases
int main() {
    // Test case 1
    TreeNode* root1 = new TreeNode(-10);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Max Path Sum (TC1): " << maxPathSum(root1) << endl;
    // ✅ Expected: 42 (15 + 20 + 7)

    // Test case 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "Max Path Sum (TC2): " << maxPathSum(root2) << endl;
    // ✅ Expected: 6 (2 + 1 + 3)

    // Test case 3
    TreeNode* root3 = new TreeNode(-3);
    cout << "Max Path Sum (TC3): " << maxPathSum(root3) << endl;
    // ✅ Expected: -3 (only one node)

    // Test case 4
    TreeNode* root4 = new TreeNode(2);
    root4->left = new TreeNode(-1);
    cout << "Max Path Sum (TC4): " << maxPathSum(root4) << endl;
    // ✅ Expected: 2 (choose only node 2, ignore -1)

    return 0;
}
