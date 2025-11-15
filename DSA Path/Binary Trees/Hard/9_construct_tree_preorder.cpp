#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive function to build tree
TreeNode* buildRec(int low, int high, int& preIdx, vector<int>& preorder, unordered_map<int,int>& idxMap) {
    if (low > high) return NULL;

    int rootVal = preorder[preIdx++];
    TreeNode* root = new TreeNode(rootVal);

    int idx = idxMap[rootVal];

    root->left = buildRec(low, idx - 1, preIdx, preorder, idxMap);
    root->right = buildRec(idx + 1, high, preIdx, preorder, idxMap);

    return root;
}

// Main build function
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> idxMap;
    for (int i = 0; i < inorder.size(); i++) {
        idxMap[inorder[i]] = i;
    }

    int preIdx = 0;
    return buildRec(0, inorder.size() - 1, preIdx, preorder, idxMap);
}

// Helper to print inorder traversal (to verify correctness)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper to print preorder traversal
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // 🌳 Test Case 1
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1  = {9, 3, 15, 20, 7};

    TreeNode* root1 = buildTree(preorder1, inorder1);

    cout << "Test Case 1 - Inorder: ";
    printInorder(root1);
    cout << "\nExpected: 9 3 15 20 7\n";

    cout << "Test Case 1 - Preorder: ";
    printPreorder(root1);
    cout << "\nExpected: 3 9 20 15 7\n\n";

    // 🌳 Test Case 2 (Skewed tree - like a linked list)
    vector<int> preorder2 = {1, 2, 3, 4};
    vector<int> inorder2  = {1, 2, 3, 4};

    TreeNode* root2 = buildTree(preorder2, inorder2);

    cout << "Test Case 2 - Inorder: ";
    printInorder(root2);
    cout << "\nExpected: 1 2 3 4\n";

    cout << "Test Case 2 - Preorder: ";
    printPreorder(root2);
    cout << "\nExpected: 1 2 3 4\n\n";

    // 🌳 Test Case 3 (Balanced tree)
    vector<int> preorder3 = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder3  = {4, 2, 5, 1, 6, 3, 7};

    TreeNode* root3 = buildTree(preorder3, inorder3);

    cout << "Test Case 3 - Inorder: ";
    printInorder(root3);
    cout << "\nExpected: 4 2 5 1 6 3 7\n";

    cout << "Test Case 3 - Preorder: ";
    printPreorder(root3);
    cout << "\nExpected: 1 2 4 5 3 6 7\n";

    return 0;
}
