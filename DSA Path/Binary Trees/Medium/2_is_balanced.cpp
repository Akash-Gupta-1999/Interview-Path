#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function: returns height if balanced, -1 otherwise
int checkHeight(TreeNode* root) {
    if (!root) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;  // left subtree unbalanced

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1; // right subtree unbalanced

    if (abs(leftHeight - rightHeight) > 1)
        return -1; // current node unbalanced

    return 1 + max(leftHeight, rightHeight); // height of current node
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << (isBalanced(root) ? "Balanced" : "Not Balanced") << endl;  
    // ✅ Expected: Balanced

    /*
            1
             \
              2
               \
                3
                 \
                  4
    */
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);
    root2->right->right->right = new TreeNode(4);

    cout << (isBalanced(root2) ? "Balanced" : "Not Balanced") << endl;  
    // ✅ Expected: Not Balanced

    return 0;
}
