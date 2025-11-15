#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Morris Preorder Traversal (O(1) space, O(n) time)
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left) {
            // Find inorder predecessor (rightmost node in left subtree)
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                // Preorder: Visit the node BEFORE going left
                preorder.push_back(curr->val);
                // Create thread (temporary link back to curr)
                prev->right = curr;
                curr = curr->left;
            } else {
                // Thread already exists → remove it
                prev->right = NULL;
                curr = curr->right;
            }
        } else {
            // No left child → visit directly
            preorder.push_back(curr->val);
            curr = curr->right;
        }
    }

    return preorder;
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

    cout << "Preorder (Test Case 1): ";
    printVector(preorderTraversal(root1));
    // ✅ Expected: 1 2 4 5 3

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

    cout << "Preorder (Test Case 2): ";
    printVector(preorderTraversal(root2));
    // ✅ Expected: 5 4 3

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

    cout << "Preorder (Test Case 3): ";
    printVector(preorderTraversal(root3));
    // ✅ Expected: 10 20 30

    return 0;
}
