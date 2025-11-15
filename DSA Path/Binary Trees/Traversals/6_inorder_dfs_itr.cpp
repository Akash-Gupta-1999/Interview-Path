#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {
        // Go to the leftmost node
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); 
        st.pop();
        ans.push_back(curr->val);

        // Move to the right subtree
        curr = curr->right;
    }
    return ans;
}

int main() {
    /*
        Example Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Expected Inorder: [4, 2, 5, 1, 3, 6]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal (Iterative): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
