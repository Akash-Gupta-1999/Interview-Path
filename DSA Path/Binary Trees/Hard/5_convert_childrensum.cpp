#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 Intuition:
 - Traverse tree top-down.
 - If parent > sum(children), push parent value down to children.
 - If parent < sum(children), update parent value.
 - Do postorder so that after fixing children, parent gets the correct sum.
*/
void convertToChildrenSumProperty(TreeNode* root) {
    if(!root) return;

    // Step 1: Calculate child sum
    int childsum = 0;
    if(root->left) childsum+=root->left->val;
    if(root->right) childsum+=root->right->val;

    // If children sum is greater → update parent
    if(childsum > root->val) root->val = childsum;
    else{
        // Step 2: If parent is greater → push parent down to children
        if(root->left) root->left->val = root->val;
        else if(root->right) root->right->val = root->val;
    } 

    // Step 3: Recurse (postorder)
    convertToChildrenSumProperty(root->left);
    convertToChildrenSumProperty(root->right);

    // Step 4: After recursion, fix parent = left + right
    int total = 0;
    if(root->left) total+=root->left->val;
    if(root->right) total+=root->right->val;
    if(root->left || root->right) root->val = total;
}

// Helper: Print inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
            50
           /  \
          7    2
         / \  / \
        3  5 1   30
    */
    TreeNode* root1 = new TreeNode(50);
    root1->left = new TreeNode(7);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(30);

    cout << "Before Conversion (Inorder): ";
    inorder(root1);
    cout << endl;

    convertToChildrenSumProperty(root1);

    cout << "After Conversion (Inorder): ";
    inorder(root1);
    cout << endl;

    /*
            10
           /
          8
    */
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(8);

    cout << "\nBefore Conversion (Inorder): ";
    inorder(root2);
    cout << endl;

    convertToChildrenSumProperty(root2);

    cout << "After Conversion (Inorder): ";
    inorder(root2);
    cout << endl;

    return 0;
}
