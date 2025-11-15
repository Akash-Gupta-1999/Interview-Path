#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function: build parent mapping
void findParent(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front(); q.pop();
        if (n->left) {
            parent[n->left] = n;
            q.push(n->left);
        }
        if (n->right) {
            parent[n->right] = n;
            q.push(n->right);
        }
    }
}

// 🔥 Function to calculate minimum time to burn the tree
int minTimeToBurn(TreeNode* root, TreeNode* target) {
    if (!root) return 0;

    unordered_map<TreeNode*, TreeNode*> parent;   // parent mapping
    unordered_map<TreeNode*, bool> visited;       // visited tracking

    // Step 1: Build parent map
    findParent(parent, root);

    // Step 2: Start BFS from target
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;

    int time = 0;
    while (!q.empty()) {
        int sz = q.size();
        bool burned = false; // track if at least one new node is burned

        for (int i = 0; i < sz; i++) {
            TreeNode* n = q.front(); q.pop();

            // check neighbors (left, right, parent)
            if (n->left && !visited[n->left]) {
                q.push(n->left);
                visited[n->left] = true;
                burned = true;
            }
            if (n->right && !visited[n->right]) {
                q.push(n->right);
                visited[n->right] = true;
                burned = true;
            }
            if (parent.count(n) && !visited[parent[n]]) {
                q.push(parent[n]);
                visited[parent[n]] = true;
                burned = true;
            }
        }
        if (burned) time++; // only increment if fire spread this round
    }

    return time;
}

int main() {
    /*
              1
             / \
            2   3
           / \
          4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode* target = root->left; // Node with value 2

    int time = minTimeToBurn(root, target);

    cout << "Minimum time to burn the tree from node " 
         << target->val << " is: " << time << endl;

    // ✅ Expected Output: 2

    return 0;
}
