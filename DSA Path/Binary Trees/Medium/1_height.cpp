#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to calculate maximum depth
int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;  
    // 1 for current node + max depth of left/right subtree
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5

        Depth = 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Max Depth: " << maxDepth(root) << endl;  // ✅ Expected: 3

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);
    root2->right->right->right = new TreeNode(4);

    cout << "Max Depth: " << maxDepth(root2) << endl;  // ✅ Expected: 4 (skewed tree)

    return 0;
}
