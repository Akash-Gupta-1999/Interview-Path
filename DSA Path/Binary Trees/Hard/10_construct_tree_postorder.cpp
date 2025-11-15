#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive function to build tree
TreeNode* buildRec(int low, int high, int& postIdx, vector<int>& postorder, unordered_map<int,int>& idxMap) {
    if (low > high) return NULL;

    int rootVal = postorder[postIdx--];
    TreeNode* root = new TreeNode(rootVal);

    int idx = idxMap[rootVal];

    // ⚠️ Important: Postorder processes RIGHT subtree before LEFT (reverse of preorder)
    root->right = buildRec(idx + 1, high, postIdx, postorder, idxMap);
    root->left  = buildRec(low, idx - 1, postIdx, postorder, idxMap);

    return root;
}

// Main build function
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> idxMap;
    for (int i = 0; i < inorder.size(); i++) {
        idxMap[inorder[i]] = i;
    }

    int postIdx = postorder.size() - 1;
    return buildRec(0, inorder.size() - 1, postIdx, postorder, idxMap);
}

// Helper to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper to print postorder traversal
void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    // 🌳 Test Case 1
    vector<int> inorder1   = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};

    TreeNode* root1 = buildTree(inorder1, postorder1);

    cout << "Test Case 1 - Inorder: ";
    printInorder(root1);
    cout << "\nExpected: 9 3 15 20 7\n";

    cout << "Test Case 1 - Postorder: ";
    printPostorder(root1);
    cout << "\nExpected: 9 15 7 20 3\n\n";

    // 🌳 Test Case 2 (Skewed tree - like a linked list)
    vector<int> inorder2   = {1, 2, 3, 4};
    vector<int> postorder2 = {1, 2, 3, 4};

    TreeNode* root2 = buildTree(inorder2, postorder2);

    cout << "Test Case 2 - Inorder: ";
    printInorder(root2);
    cout << "\nExpected: 1 2 3 4\n";

    cout << "Test Case 2 - Postorder: ";
    printPostorder(root2);
    cout << "\nExpected: 1 2 3 4\n\n";

    // 🌳 Test Case 3 (Balanced tree)
    vector<int> inorder3   = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder3 = {4, 5, 2, 6, 7, 3, 1};

    TreeNode* root3 = buildTree(inorder3, postorder3);

    cout << "Test Case 3 - Inorder: ";
    printInorder(root3);
    cout << "\nExpected: 4 2 5 1 6 3 7\n";

    cout << "Test Case 3 - Postorder: ";
    printPostorder(root3);
    cout << "\nExpected: 4 5 2 6 7 3 1\n";

    return 0;
}
