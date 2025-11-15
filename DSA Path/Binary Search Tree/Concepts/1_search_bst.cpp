#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Recursive BST Search
TreeNode* searchBSTRecursive(TreeNode* root, int val) {
    if (root == NULL) return NULL;          // Base case: not found
    
    if (root->val == val) return root;      // Found node
    
    else if (root->val > val)               // Value lies in left subtree
        return searchBSTRecursive(root->left, val);
    
    return searchBSTRecursive(root->right, val);  // Value lies in right subtree
}

// ✅ Iterative BST Search
TreeNode* searchBSTIterative(TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) return root;        // Found
        else if (root->val > val) root = root->left;  // Move left
        else root = root->right;                      // Move right
    }
    return NULL; // Not found
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

    // 🔎 Test 1: Recursive search
    int key1 = 6;
    TreeNode* res1 = searchBSTRecursive(root, key1);
    cout << "Recursive Search for " << key1 << ": ";
    cout << (res1 ? "Found -> " + to_string(res1->val) : "Not Found") << endl;

    // 🔎 Test 2: Iterative search
    int key2 = 13;
    TreeNode* res2 = searchBSTIterative(root, key2);
    cout << "Iterative Search for " << key2 << ": ";
    cout << (res2 ? "Found -> " + to_string(res2->val) : "Not Found") << endl;

    // 🔎 Test 3: Not found case
    int key3 = 5;
    TreeNode* res3 = searchBSTIterative(root, key3);
    cout << "Iterative Search for " << key3 << ": ";
    cout << (res3 ? "Found -> " + to_string(res3->val) : "Not Found") << endl;

    return 0;
}
