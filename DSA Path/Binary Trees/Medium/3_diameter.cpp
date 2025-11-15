#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper: returns height, updates diameter
int height(TreeNode* root, int &diameter) {
    if (!root) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    // Update diameter: longest path through this node
    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5

        Longest path = 4 -> 2 -> 1 -> 3  (length = 3 edges)
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;
    // ✅ Expected: 3

    /*
            1
             \
              2
               \
                3
                 \
                  4

        Longest path = 1 -> 2 -> 3 -> 4 (length = 3 edges)
    */
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);
    root2->right->right->right = new TreeNode(4);

    cout << "Diameter: " << diameterOfBinaryTree(root2) << endl;
    // ✅ Expected: 3

    return 0;
}
