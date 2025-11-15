#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Morris-based Flatten (O(1) extra space)
void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            // Find predecessor: rightmost node of left subtree
            TreeNode* pred = curr->left;
            while (pred->right) {
                pred = pred->right;
            }

            // Rewire connections
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        // Move to next node (like Morris traversal)
        curr = curr->right;
    }
}

// Helper function to print flattened tree
void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << "\n";
}

int main() {
    /*
            1
           / \
          2   5
         / \   \
        3   4   6
    Expected preorder: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);

    flatten(root1);
    cout << "Flattened Tree: ";
    printFlattened(root1);

    // 🌳 Skewed left case
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    flatten(root2);
    cout << "Flattened (Skewed Left): ";
    printFlattened(root2);

    // 🌳 Skewed right case
    TreeNode* root3 = new TreeNode(1);
    root3->right = new TreeNode(2);
    root3->right->right = new TreeNode(3);

    flatten(root3);
    cout << "Flattened (Skewed Right): ";
    printFlattened(root3);

    return 0;
}
