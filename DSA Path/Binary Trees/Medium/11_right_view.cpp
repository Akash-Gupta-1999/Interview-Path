#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper DFS function
void rightViewDFS(TreeNode* root, vector<int>& ans, int depth, int& maxDepth) {
    if (!root) return;
    
    if (depth > maxDepth) {   // first node at this depth
        ans.push_back(root->val);
        maxDepth = depth;
    }
    
    // visit right subtree first
    rightViewDFS(root->right, ans, depth + 1, maxDepth);
    rightViewDFS(root->left, ans, depth + 1, maxDepth);
}

// Main function to get Right Side View
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    int maxDepth = -1;
    rightViewDFS(root, ans, 0, maxDepth);
    return ans;
}

int main() {
    /*
            1
           / \
          2   3
           \    \
            4    5
             \
              6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    // Call rightSideView function
    vector<int> result = rightSideView(root);

    // Print result
    cout << "Right View: ";
    for (int v : result) cout << v << " ";
    cout << endl;

    // ✅ Expected Output:
    // Right View: 1 3 5 6

    return 0;
}
