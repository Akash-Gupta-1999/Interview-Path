#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, TreeNode*& first, TreeNode*& middle, TreeNode*& last, TreeNode*& prev) {
    if (!root) return;
    inorder(root->left, first, middle, last, prev);

    if (prev && prev->val > root->val) {
        if (first == NULL) {
            first = prev;
            middle = root;
        } else {
            last = root;
        }
    }
    prev = root;

    inorder(root->right, first, middle, last, prev);
}

void recoverTree(TreeNode* root) {
    TreeNode *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    inorder(root, first, middle, last, prev);

    if (first && last) swap(first->val, last->val);
    else if (first && middle) swap(first->val, middle->val);
}

// Utility: inorder traversal print
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
           3
          / \
         1   4
            /
           2

    Original inorder = [1, 3, 2, 4] (incorrect, 3 and 2 are swapped)
    Correct inorder  = [1, 2, 3, 4]
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}
