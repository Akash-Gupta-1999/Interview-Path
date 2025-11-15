#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative Preorder Traversal
vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* temp = st.top(); 
        st.pop();
        ans.push_back(temp->val);

        // Push right first so left is processed first
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
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

        Expected Preorder: [1, 2, 4, 5, 3, 6]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = preorderTraversal(root);

    cout << "Preorder Traversal (Iterative): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
