#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative Postorder Traversal using 1 stack
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr || !st.empty()) {
        if (curr) {
            st.push(curr);
            curr = curr->left;   // go as left as possible
        } else {
            TreeNode* node = st.top();
            if (node->right && lastVisited != node->right) {
                // go to right subtree if not visited yet
                curr = node->right;
            } else {
                ans.push_back(node->val);  // process
                lastVisited = node;
                st.pop();
            }
        }
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

        Expected Postorder: [4, 5, 2, 6, 3, 1]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = postorderTraversal(root);

    cout << "Postorder Traversal (Iterative, 1 stack): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
