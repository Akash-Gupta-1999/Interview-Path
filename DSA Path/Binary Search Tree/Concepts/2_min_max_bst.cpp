#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Function to find minimum in BST (leftmost node)
TreeNode* findMin(TreeNode* root) {
    if (!root) return NULL;
    while (root->left) {
        root = root->left;
    }
    return root;
}

// ✅ Function to find maximum in BST (rightmost node)
TreeNode* findMax(TreeNode* root) {
    if (!root) return NULL;
    while (root->right) {
        root = root->right;
    }
    return root;
}

int main() {
    /*
              8
             / \
            3   10
           / \     \
          1   6     14
             / \    /
            4   7  13
    */

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    TreeNode* minNode = findMin(root);
    TreeNode* maxNode = findMax(root);

    cout << "Min in BST = " << (minNode ? minNode->val : -1) << endl;
    cout << "Max in BST = " << (maxNode ? maxNode->val : -1) << endl;

    // ✅ Expected: Min = 1, Max = 14

    return 0;
}
