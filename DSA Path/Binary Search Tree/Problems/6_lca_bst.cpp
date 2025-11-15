#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);

    if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise root is the split point → LCA
    return root;
}

int main() {
    /*
             6
            / \
           2   8
          / \ / \
         0  4 7  9
           / \
          3   5
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Test cases
    TreeNode* p = root->left;           // 2
    TreeNode* q = root->right;          // 8
    cout << "LCA(2, 8) = " << lowestCommonAncestor(root, p, q)->val << endl; // 6

    p = root->left;                     // 2
    q = root->left->right;              // 4
    cout << "LCA(2, 4) = " << lowestCommonAncestor(root, p, q)->val << endl; // 2

    p = root->left->right->left;        // 3
    q = root->left->right->right;       // 5
    cout << "LCA(3, 5) = " << lowestCommonAncestor(root, p, q)->val << endl; // 4

    p = root->left;                     // 2
    q = root->left->right->left;        // 3
    cout << "LCA(2, 3) = " << lowestCommonAncestor(root, p, q)->val << endl; // 2

    return 0;
}
