#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    TreeNode* curr;

    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        int ans = -1;
        while (curr) {
            if (curr->left) {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                
                if (!pred->right) {
                    pred->right = curr;   // make thread
                    curr = curr->left;
                } else {
                    pred->right = NULL;   // remove thread
                    ans = curr->val;      // visit
                    curr = curr->right;
                    break;
                }
            } else {
                ans = curr->val;          // visit
                curr = curr->right;
                break;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return curr != nullptr;
    }
};

// Utility: run iterator and print inorder traversal
void testCase(TreeNode* root, const string& caseName) {
    cout << caseName << ": ";
    BSTIterator it(root);
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;
}

int main() {
    // 1. Balanced BST
    /*
             7
            / \
           3   15
              /  \
             9    20
    */
    TreeNode* root1 = new TreeNode(7);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(15);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(20);
    testCase(root1, "Balanced BST"); // Expected: 3 7 9 15 20

    // 2. Single node tree
    TreeNode* root2 = new TreeNode(10);
    testCase(root2, "Single node tree"); // Expected: 10

    // 3. Right-skewed BST
    /*
        5
         \
          8
           \
            12
    */
    TreeNode* root3 = new TreeNode(5);
    root3->right = new TreeNode(8);
    root3->right->right = new TreeNode(12);
    testCase(root3, "Right-skewed BST"); // Expected: 5 8 12

    // 4. Left-skewed BST
    /*
          10
         /
        6
       /
      2
    */
    TreeNode* root4 = new TreeNode(10);
    root4->left = new TreeNode(6);
    root4->left->left = new TreeNode(2);
    testCase(root4, "Left-skewed BST"); // Expected: 2 6 10

    // 5. Empty tree
    TreeNode* root5 = nullptr;
    testCase(root5, "Empty tree"); // Expected: (nothing)

    return 0;
}
