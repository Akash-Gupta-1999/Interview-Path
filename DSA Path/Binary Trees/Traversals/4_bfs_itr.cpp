#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Level Order Traversal (BFS)
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;

    while (!q.empty()) {
        int sz = q.size();              // number of nodes at this level
        vector<int> level;              // values at current level

        for (int i = 0; i < sz; i++) {
            TreeNode* temp = q.front(); q.pop();
            level.push_back(temp->val);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    /*
        Example Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Expected Level Order:
        [
          [1],
          [2,3],
          [4,5,6]
        ]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> result = levelOrder(root);

    cout << "Level Order Traversal:" << endl;
    for (auto& level : result) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }

    return 0;
}
