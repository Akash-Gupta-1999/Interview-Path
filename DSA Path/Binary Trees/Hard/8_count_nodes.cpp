#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Compute height by always going left
int leftsubtree(TreeNode* root) {
    if (!root) return 0;
    return 1 + leftsubtree(root->left);
}

// Compute height by always going right
int rightsubtree(TreeNode* root) {
    if (!root) return 0;
    return 1 + rightsubtree(root->right);
}

// Count total nodes in a Complete Binary Tree
int countNodes(TreeNode* root) {
    if (!root) return 0;

    int lh = leftsubtree(root);   // height from leftmost path
    int rh = rightsubtree(root);  // height from rightmost path

    // ✅ Case 1: If left height == right height → it's a perfect binary tree
    // Formula: nodes = 2^h - 1
    if (lh == rh) return (1 << lh) - 1;

    // ❌ Case 2: Not perfect → recurse on left + right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ---------------- MAIN + TEST CASES ----------------
int main() {
    // 🌳 Test Case 1: Perfect binary tree
    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    cout << "Test Case 1 - Perfect Tree: " << countNodes(root1) << endl;
    // ✅ Expected: 7

    // 🌳 Test Case 2: Complete binary tree (not perfect)
    /*
              1
             / \
            2   3
           / \  /
          4  5 6
    */
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);

    cout << "Test Case 2 - Complete Tree: " << countNodes(root2) << endl;
    // ✅ Expected: 6

    // 🌳 Test Case 3: Skewed tree (like a linked list)
    /*
        1
         \
          2
           \
            3
             \
              4
    */
    TreeNode* root3 = new TreeNode(1);
    root3->right = new TreeNode(2);
    root3->right->right = new TreeNode(3);
    root3->right->right->right = new TreeNode(4);

    cout << "Test Case 3 - Skewed Tree: " << countNodes(root3) << endl;
    // ✅ Expected: 4

    return 0;
}
