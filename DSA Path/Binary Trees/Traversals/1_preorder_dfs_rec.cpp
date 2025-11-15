#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Preorder Traversal (Root → Left → Right)
void preorderRec(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->val);       // visit root
    preorderRec(root->left, ans);   // go left
    preorderRec(root->right, ans);  // go right
}

int main() {
    /*
            10
           /  \
          5    15
         / \   / \
        3   7 12 18
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    vector<int> preorder;
    preorderRec(root, preorder);

    cout << "Preorder Traversal: ";
    for (int x : preorder) cout << x << " ";
    cout << endl;

    return 0;
}
