#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to get preorder, inorder, postorder in one traversal
tuple<vector<int>, vector<int>, vector<int>> allTraversals(TreeNode* root) {
    vector<int> preorder, inorder, postorder;
    if (!root) return {preorder, inorder, postorder};

    // stack stores {node, state}
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto& [node, state] = st.top();

        if (state == 1) {
            // Preorder
            preorder.push_back(node->val);
            state++;
            if (node->left) st.push({node->left, 1});
        } 
        else if (state == 2) {
            // Inorder
            inorder.push_back(node->val);
            state++;
            if (node->right) st.push({node->right, 1});
        } 
        else {
            // Postorder
            postorder.push_back(node->val);
            st.pop();
        }
    }

    return {preorder, inorder, postorder};
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6

        Preorder  : 1 2 4 5 3 6
        Inorder   : 4 2 5 1 3 6
        Postorder : 4 5 2 6 3 1
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    auto [pre, in, post] = allTraversals(root);

    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << "\nInorder: ";
    for (int x : in) cout << x << " ";
    cout << "\nPostorder: ";
    for (int x : post) cout << x << " ";
    cout << endl;

    return 0;
}
