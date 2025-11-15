#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🔹 Function to find floor and ceil in BST
// Returns vector of size 2: {floor, ceil}
vector<int> findFloorCeil(TreeNode* root, int key) {
    TreeNode *floorNode = NULL, *ceilNode = NULL;

    while (root) {
        if (root->val == key) {
            floorNode = ceilNode = root;
            break;
        } else if (root->val > key) {
            ceilNode = root; 
            root = root->left;
        } else {
            floorNode = root; 
            root = root->right;
        }
    }

    return {floorNode ? floorNode->val : -1,
            ceilNode ? ceilNode->val : -1};
}

// Helper to build a sample BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    /*
              8
             / \
            4   12
           / \   / \
          2   6 10  14
    */
    TreeNode* root = NULL;
    vector<int> vals = {8, 4, 12, 2, 6, 10, 14};
    for (int v : vals) root = insertBST(root, v);

    // 🔹 Test Case 1
    int key1 = 5;
    vector<int> res1 = findFloorCeil(root, key1);
    cout << "Key: " << key1 << " -> Floor: " << res1[0] << ", Ceil: " << res1[1] << endl;
    // Expected: Floor = 4, Ceil = 6

    // 🔹 Test Case 2
    int key2 = 13;
    vector<int> res2 = findFloorCeil(root, key2);
    cout << "Key: " << key2 << " -> Floor: " << res2[0] << ", Ceil: " << res2[1] << endl;
    // Expected: Floor = 12, Ceil = 14

    // 🔹 Test Case 3
    int key3 = 1;
    vector<int> res3 = findFloorCeil(root, key3);
    cout << "Key: " << key3 << " -> Floor: " << res3[0] << ", Ceil: " << res3[1] << endl;
    // Expected: Floor = -1, Ceil = 2

    // 🔹 Test Case 4
    int key4 = 15;
    vector<int> res4 = findFloorCeil(root, key4);
    cout << "Key: " << key4 << " -> Floor: " << res4[0] << ", Ceil: " << res4[1] << endl;
    // Expected: Floor = 14, Ceil = -1

    return 0;
}
