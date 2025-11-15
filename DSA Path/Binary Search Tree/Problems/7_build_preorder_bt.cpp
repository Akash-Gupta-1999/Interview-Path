#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty()) return nullptr;

    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> st;
    st.push(root);

    for (int i = 1; i < preorder.size(); i++) {
        TreeNode* newnode = new TreeNode(preorder[i]);

        if (preorder[i] < st.top()->val) {
            // newnode is left child of top
            st.top()->left = newnode;
        } else {
            TreeNode* parent = nullptr;
            // Pop until we find correct parent
            while (!st.empty() && st.top()->val < preorder[i]) {
                parent = st.top();
                st.pop();
            }
            parent->right = newnode;
        }
        st.push(newnode); // always push the new node
    }

    return root;
}

// Utility: inorder traversal (should print sorted order for BST)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};
    TreeNode* root1 = bstFromPreorder(preorder1);

    cout << "Inorder traversal of constructed BST 1: ";
    inorder(root1); // Expected: 1 5 7 8 10 12
    cout << endl;

    vector<int> preorder2 = {10, 5, 1, 7, 40, 50};
    TreeNode* root2 = bstFromPreorder(preorder2);

    cout << "Inorder traversal of constructed BST 2: ";
    inorder(root2); // Expected: 1 5 7 10 40 50
    cout << endl;

    vector<int> preorder3 = {5, 4, 3, 2, 1}; // skewed left
    TreeNode* root3 = bstFromPreorder(preorder3);

    cout << "Inorder traversal of constructed BST 3: ";
    inorder(root3); // Expected: 1 2 3 4 5
    cout << endl;

    vector<int> preorder4 = {1, 2, 3, 4, 5}; // skewed right
    TreeNode* root4 = bstFromPreorder(preorder4);

    cout << "Inorder traversal of constructed BST 4: ";
    inorder(root4); // Expected: 1 2 3 4 5
    cout << endl;

    return 0;
}
