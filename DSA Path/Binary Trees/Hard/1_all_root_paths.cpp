#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive helper to collect paths
void pathFinder(TreeNode* root, vector<int>& path, vector<vector<int>>& result) {
    if (!root) return;

    // Add current node to path
    path.push_back(root->val);

    // If it's a leaf, store the path
    if (!root->left && !root->right) {
        result.push_back(path);
    } else {
        // Recurse left and right
        pathFinder(root->left, path, result);
        pathFinder(root->right, path, result);
    }

    // Backtrack
    path.pop_back();
}

// Function to return all root-to-leaf paths
vector<vector<int>> allRootToLeafPaths(TreeNode* root) {
    vector<vector<int>> result;
    vector<int> path;
    pathFinder(root, path, result);
    return result;
}

// Helper function to print paths
void printPaths(const vector<vector<int>>& paths) {
    for (auto& path : paths) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
}

int main() {
    // 🌳 Test Case 1
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(6);

    cout << "Test Case 1 - All root-to-leaf paths:\n";
    printPaths(allRootToLeafPaths(root1));

    // 🌳 Test Case 2
    /*
            10
            /
           8
          /
         7
        /
       6
    */
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(8);
    root2->left->left = new TreeNode(7);
    root2->left->left->left = new TreeNode(6);

    cout << "\nTest Case 2 - All root-to-leaf paths:\n";
    printPaths(allRootToLeafPaths(root2));

    // 🌳 Test Case 3
    /*
            5
           / \
          4   8
         /   / \
        11  13  4
       /  \      \
      7    2      1
    */
    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(4);
    root3->right = new TreeNode(8);
    root3->left->left = new TreeNode(11);
    root3->left->left->left = new TreeNode(7);
    root3->left->left->right = new TreeNode(2);
    root3->right->left = new TreeNode(13);
    root3->right->right = new TreeNode(4);
    root3->right->right->right = new TreeNode(1);

    cout << "\nTest Case 3 - All root-to-leaf paths:\n";
    printPaths(allRootToLeafPaths(root3));

    return 0;
}
