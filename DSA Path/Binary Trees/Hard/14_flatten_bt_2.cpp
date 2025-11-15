#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Correct stack-based flatten (preorder order)
void flatten(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* prev = NULL;

    while (!st.empty()) {
        TreeNode* curr = st.top(); st.pop();

        if (prev) {
            prev->right = curr;
            prev->left = NULL;
        }

        // Push right first so left is processed first (preorder)
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);

        prev = curr;
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

    // Skewed left case
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    flatten(root2);
    cout << "Flattened (Skewed Left): ";
    printFlattened(root2);

    // Skewed right case
    TreeNode* root3 = new TreeNode(1);
    root3->right = new TreeNode(2);
    root3->right->right = new TreeNode(3);

    flatten(root3);
    cout << "Flattened (Skewed Right): ";
    printFlattened(root3);

    return 0;
}
