#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Morris Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left) {
            // Find inorder predecessor
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                // Make thread (temporary link)
                prev->right = curr;
                curr = curr->left;
            } else {
                // Thread already exists -> remove it
                prev->right = NULL;
                inorder.push_back(curr->val); // Process node
                curr = curr->right;
            }
        } else {
            // No left child, visit directly
            inorder.push_back(curr->val);
            curr = curr->right;
        }
    }

    return inorder;
}

// Helper function to print traversal
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    // 🌳 Test Case 1
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    cout << "Inorder (Test Case 1): ";
    printVector(inorderTraversal(root1));
    // ✅ Expected: 4 2 5 1 3

    // 🌳 Test Case 2 (skewed left)
    /*
            5
           /
          4
         /
        3
    */
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->left->left = new TreeNode(3);

    cout << "Inorder (Test Case 2): ";
    printVector(inorderTraversal(root2));
    // ✅ Expected: 3 4 5

    // 🌳 Test Case 3 (skewed right)
    /*
        10
          \
           20
             \
              30
    */
    TreeNode* root3 = new TreeNode(10);
    root3->right = new TreeNode(20);
    root3->right->right = new TreeNode(30);

    cout << "Inorder (Test Case 3): ";
    printVector(inorderTraversal(root3));
    // ✅ Expected: 10 20 30

    return 0;
}
