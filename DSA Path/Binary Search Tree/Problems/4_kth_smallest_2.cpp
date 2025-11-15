#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int k) {
    TreeNode* curr = root;
    int ans = -1;

    while (curr) {
        if (curr->left) {
            // Find inorder predecessor
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                // Create temporary thread
                pred->right = curr;
                curr = curr->left;
            } else {
                // Remove thread
                pred->right = NULL;
                k--;
                if (k == 0) ans = curr->val;
                curr = curr->right;
            }
        } else {
            // Visit this node
            k--;
            if (k == 0) ans = curr->val;
            curr = curr->right;
        }
    }

    return ans;
}

/// ---------- Test cases ----------
int main() {
    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    cout << kthSmallest(root, 1) << endl; // 1
    cout << kthSmallest(root, 3) << endl; // 3
    cout << kthSmallest(root, 5) << endl; // 5

    return 0;
}
