#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper: Check leaf
bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

// Add Left Boundary (excluding leaves)
void addLeftBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->val);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

// Add Right Boundary (excluding leaves, reversed)
void addRightBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->right;
    vector<int> temp;
    while (cur) {
        if (!isLeaf(cur)) temp.push_back(cur->val);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

// Add all Leaves (DFS)
void addLeaves(TreeNode* root, vector<int>& res) {
    if (!root) return;
    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

// Main Function
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->val);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

// Utility: Print Vector
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           / \
          7   8
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);

    cout << "Boundary Traversal: ";
    vector<int> res = boundaryTraversal(root);
    printVector(res);  // Expected: 1 2 4 7 8 6 3

    return 0;
}
