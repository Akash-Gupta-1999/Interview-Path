#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🔹 Recursive Insert into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val); // If tree empty, create new node
    if (val < root->val) 
        root->left = insertIntoBST(root->left, val);  // Insert in left subtree
    else 
        root->right = insertIntoBST(root->right, val); // Insert in right subtree
    return root;
}

// 🔹 Inorder Traversal (for checking correctness)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;

    // Insert values into BST
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int v : values) {
        root = insertIntoBST(root, v);
    }

    // ✅ Expected BST:
    /*
               8
             /   \
            3     10
           / \      \
          1   6      14
             / \     /
            4   7   13
    */

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;
    // ✅ Expected Output: 1 3 4 6 7 8 10 13 14

    // Insert another value
    root = insertIntoBST(root, 5);
    cout << "Inorder after inserting 5: ";
    inorder(root);
    cout << endl;
    // ✅ Expected Output: 1 3 4 5 6 7 8 10 13 14

    return 0;
}
