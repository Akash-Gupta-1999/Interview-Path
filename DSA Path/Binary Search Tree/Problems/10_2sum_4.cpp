#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterator for BST: supports next() in sorted or reverse-sorted order
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool forward; // true -> inorder, false -> reverse inorder
    
    BSTIterator(TreeNode* root, bool isForward) {
        forward = isForward;
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (forward) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = forward ? node->left : node->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, true);   // smallest
        BSTIterator r(root, false);  // largest

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) {
                if (l.hasNext()) i = l.next();
                else break;
            } else {
                if (r.hasNext()) j = r.next();
                else break;
            }
        }
        return false;
    }
};

int main() {
    /*
           5
          / \
         3   6
        / \    \
       2   4    7
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << (sol.findTarget(root, 9) ? "true" : "false") << endl;  // true (2+7)
    cout << (sol.findTarget(root, 28) ? "true" : "false") << endl; // false
    cout << (sol.findTarget(root, 11) ? "true" : "false") << endl; // true (4+7)

    return 0;
}
