#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Inorder Traversal (Left → Root → Right)
void inorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    inorder(root->left, ans);   // go left
    ans.push_back(root->val);   // visit root
    inorder(root->right, ans);  // go right
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

    vector<int> inorderAns;
    inorder(root, inorderAns);

    cout << "Inorder Traversal: ";
    for (int x : inorderAns) cout << x << " ";
    cout << endl;

    return 0;
}
