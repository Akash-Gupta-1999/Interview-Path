#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, k, ans);
        return ans;
    }

private:
    bool dfs(TreeNode* root, int& k, int& ans) {
        if (!root) return false;

        // Traverse left subtree
        if (dfs(root->left, k, ans)) return true;

        // Process current node
        k--;
        if (k == 0) {
            ans = root->val;
            return true; // Found, stop traversal
        }

        // Traverse right subtree
        return dfs(root->right, k, ans);
    }
};

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

    Solution sol;
    cout << sol.kthSmallest(root, 1) << endl; // 1
    cout << sol.kthSmallest(root, 3) << endl; // 3
    cout << sol.kthSmallest(root, 5) << endl; // 5

    return 0;
}
