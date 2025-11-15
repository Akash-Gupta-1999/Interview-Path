#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🔹 Function to check if two trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) 
        return true;
    if (p == NULL || q == NULL || p->val != q->val) 
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// 🔹 Test cases
int main() {
    // Test case 1: Same structure & values
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    cout << "TC1: " << (isSameTree(p1, q1) ? "true" : "false") << endl;
    // ✅ Expected: true

    // Test case 2: Different structure
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    cout << "TC2: " << (isSameTree(p2, q2) ? "true" : "false") << endl;
    // ✅ Expected: false

    // Test case 3: Different values
    TreeNode* p3 = new TreeNode(1);
    p3->left = new TreeNode(2);

    TreeNode* q3 = new TreeNode(1);
    q3->left = new TreeNode(3);

    cout << "TC3: " << (isSameTree(p3, q3) ? "true" : "false") << endl;
    // ✅ Expected: false

    // Test case 4: Both NULL
    cout << "TC4: " << (isSameTree(NULL, NULL) ? "true" : "false") << endl;
    // ✅ Expected: true

    return 0;
}
