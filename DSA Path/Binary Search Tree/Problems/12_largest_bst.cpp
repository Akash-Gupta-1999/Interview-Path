#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
    Info(bool isBST, int size, int minVal, int maxVal)
        : isBST(isBST), size(size), minVal(minVal), maxVal(maxVal) {}
};

Info dfs(TreeNode* root, int &maxSize) {
    if (!root) return Info(true, 0, INT_MAX, INT_MIN);

    Info left = dfs(root->left, maxSize);
    Info right = dfs(root->right, maxSize);

    if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
        int currSize = left.size + right.size + 1;
        maxSize = max(maxSize, currSize);
        return Info(true, currSize, min(root->val, left.minVal), max(root->val, right.maxVal));
    }

    return Info(false, max(left.size, right.size), 0, 0);
}

int largestBSTSubtree(TreeNode* root) {
    int maxSize = 0;
    dfs(root, maxSize);
    return maxSize;
}

// ---------- Test Utilities ----------
TreeNode* buildTestTree1() {
    /*
           10
          /  \
         5   15
        / \    \
       1   8    7

    Largest BST subtree = [5,1,8] → size = 3
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    return root;
}

TreeNode* buildTestTree2() {
    /*
           3
          / \
         2   4
        /
       1

    Whole tree is a BST → size = 4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    return root;
}

int main() {
    TreeNode* root1 = buildTestTree1();
    cout << "Largest BST size in Tree1: " << largestBSTSubtree(root1) << endl;

    TreeNode* root2 = buildTestTree2();
    cout << "Largest BST size in Tree2: " << largestBSTSubtree(root2) << endl;

    return 0;
}
