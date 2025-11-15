#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative Postorder Traversal (2 stacks)
vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};

    stack<TreeNode*> st1, st2;
    vector<int> ans;

    st1.push(root);

    while (!st1.empty()) {
        TreeNode* curr = st1.top(); st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }

    while (!st2.empty()) {
        ans.push_back(st2.top()->val);
        st2.pop();
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

    cout << "Postorder Traversal (Iterative, 2 stacks): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
