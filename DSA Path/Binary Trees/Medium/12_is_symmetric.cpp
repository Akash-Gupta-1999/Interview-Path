#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------------- RECURSIVE APPROACH ----------------
bool isSame(TreeNode* lnode, TreeNode* rnode) {
    if (!lnode && !rnode) return true;
    if (!lnode || !rnode || lnode->val != rnode->val) return false;
    
    return isSame(lnode->left, rnode->right) &&
           isSame(lnode->right, rnode->left);
}

bool isSymmetricRecursive(TreeNode* root) {
    if (!root) return true;
    return isSame(root->left, root->right);
}

// ---------------- ITERATIVE APPROACH ----------------
bool isSymmetricIterative(TreeNode* root) {
    if (!root) return true;
    
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    
    while (!q.empty()) {
        TreeNode* leftNode = q.front(); q.pop();
        TreeNode* rightNode = q.front(); q.pop();
        
        if (!leftNode && !rightNode) continue;
        if (!leftNode || !rightNode || leftNode->val != rightNode->val)
            return false;
        
        // Mirror check: push children in opposite order
        q.push(leftNode->left);
        q.push(rightNode->right);
        q.push(leftNode->right);
        q.push(rightNode->left);
    }
    
    return true;
}

// ---------------- MAIN WITH TEST CASE ----------------
int main() {
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Test Recursive
    cout << "Recursive: ";
    if (isSymmetricRecursive(root))
        cout << "Tree is Symmetric ✅" << endl;
    else
        cout << "Tree is NOT Symmetric ❌" << endl;

    // Test Iterative
    cout << "Iterative: ";
    if (isSymmetricIterative(root))
        cout << "Tree is Symmetric ✅" << endl;
    else
        cout << "Tree is NOT Symmetric ❌" << endl;

    // ✅ Expected output:
    // Recursive: Tree is Symmetric ✅
    // Iterative: Tree is Symmetric ✅

    return 0;
}
