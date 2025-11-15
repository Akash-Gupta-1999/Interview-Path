#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to compute maximum width of a binary tree
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, long long>> q;
    long long max_width = 0;
    q.push({root, 0}); // start index from 0 for safety

    while (!q.empty()) {
        int s = q.size();
        long long left = q.front().second, right = left;
        for (int i = 0; i < s; i++) {
            auto [n, idx] = q.front(); q.pop();
            right = idx;
            if (n->left) q.push({n->left, 2 * (idx - left)});
            if (n->right) q.push({n->right, 2 * (idx - left) + 1});
        }
        max_width = max(max_width, right - left + 1);
    }
    return (int)max_width;
}

// ---------------------- MAIN + TEST CASES ----------------------
int main() {
    // 🌳 Test Case 1
    /*
            1
           / \
          3   2
         /     \
        5       9
       /         \
      6           7
    */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    root1->right->right = new TreeNode(9);
    root1->left->left->left = new TreeNode(6);
    root1->right->right->right = new TreeNode(7);

    cout << "Test Case 1 Width: " << widthOfBinaryTree(root1) << endl;
    // ✅ Expected: 8

    // 🌳 Test Case 2
    /*
            1
           / \
          3   2
         /
        5
    */
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(5);

    cout << "Test Case 2 Width: " << widthOfBinaryTree(root2) << endl;
    // ✅ Expected: 2

    // 🌳 Test Case 3
    /*
            1
           /
          3
         /
        5
    */
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(3);
    root3->left->left = new TreeNode(5);

    cout << "Test Case 3 Width: " << widthOfBinaryTree(root3) << endl;
    // ✅ Expected: 1

    // 🌳 Test Case 4
    /*
            1
             \
              2
               \
                3
                 \
                  4
    */
    TreeNode* root4 = new TreeNode(1);
    root4->right = new TreeNode(2);
    root4->right->right = new TreeNode(3);
    root4->right->right->right = new TreeNode(4);

    cout << "Test Case 4 Width: " << widthOfBinaryTree(root4) << endl;
    // ✅ Expected: 1

    return 0;
}
