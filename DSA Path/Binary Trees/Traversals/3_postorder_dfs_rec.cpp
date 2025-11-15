#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Postorder Traversal (Left → Right → Root)
void postorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    postorder(root->left, ans);   // go left
    postorder(root->right, ans);  // go right
    ans.push_back(root->val);     // visit root
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

    vector<int> postAns;
    postorder(root, postAns);

    cout << "Postorder Traversal: ";
    for (int x : postAns) cout << x << " ";
    cout << endl;

    return 0;
}
