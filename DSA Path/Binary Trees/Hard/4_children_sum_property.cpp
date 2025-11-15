#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check Children Sum Property
bool hasChildrenSumProperty(TreeNode* root) {
    if(!root || (!root->left && !root->right))
        return true;
    int sum = 0;
    if(root->left) sum+=root->left->val;
    if(root->right) sum+=root->right->val;
    if(sum!=root->val) return false;
    return hasChildrenSumProperty(root->left) && hasChildrenSumProperty(root->right);
}

int main() {
    /*
            10
           /  \
          8    2
         / \    \
        3   5    2
    */
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(8);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(2);

    cout << "Test Case 1: " 
         << (hasChildrenSumProperty(root1) ? "Yes" : "No") << endl;

    /*
            1
           / \
          4   3
    */
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(3);

    cout << "Test Case 2: " 
         << (hasChildrenSumProperty(root2) ? "Yes" : "No") << endl;

    return 0;
}
