#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Successor
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* succ = nullptr;
    while (root) {
        if (p->val < root->val) {
            succ = root;      // potential successor
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

// Inorder Predecessor
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* pred = nullptr;
    while (root) {
        if (p->val > root->val) {
            pred = root;      // potential predecessor
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

int main() {
    /*
             20
            /  \
          10    30
         / \   /  \
        5  15 25  35
           /
          13
    */
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);
    root->left->right->left = new TreeNode(13);

    // Test 1: successor of 15
    TreeNode* p = root->left->right; // 15
    TreeNode* succ = inorderSuccessor(root, p);
    cout << "Successor of 15 = " << (succ ? to_string(succ->val) : "None") << endl;

    // Test 2: predecessor of 15
    TreeNode* pred = inorderPredecessor(root, p);
    cout << "Predecessor of 15 = " << (pred ? to_string(pred->val) : "None") << endl;

    // Test 3: successor of 30
    p = root->right; // 30
    succ = inorderSuccessor(root, p);
    cout << "Successor of 30 = " << (succ ? to_string(succ->val) : "None") << endl;

    // Test 4: predecessor of 10
    p = root->left; // 10
    pred = inorderPredecessor(root, p);
    cout << "Predecessor of 10 = " << (pred ? to_string(pred->val) : "None") << endl;

    // Test 5: successor of max element (35)
    p = root->right->right; // 35
    succ = inorderSuccessor(root, p);
    cout << "Successor of 35 = " << (succ ? to_string(succ->val) : "None") << endl;

    return 0;
}
