#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Step 1: Build parent map for each node
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

// Step 2: BFS to find all nodes at distance k
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if (!root) return {};

    unordered_map<TreeNode*, TreeNode*> parent;   // parent mapping
    unordered_map<TreeNode*, bool> visited;       // visited tracking
    vector<int> ans;

    // build parent map
    findParent(parent, root);

    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;

    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        if (dist++ == k) break;  // stop when we reach k
        for (int i = 0; i < sz; i++) {
            TreeNode* n = q.front(); q.pop();

            // check neighbors (left, right, parent)
            if (n->left && !visited[n->left]) {
                q.push(n->left);
                visited[n->left] = true;
            }
            if (n->right && !visited[n->right]) {
                q.push(n->right);
                visited[n->right] = true;
            }
            if (parent.count(n) && !visited[parent[n]]) {
                q.push(parent[n]);
                visited[parent[n]] = true;
            }
        }
    }

    // collect all nodes at distance k
    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}

// Helper: build tree and test
int main() {
    /*
              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // node 5

    vector<int> res = distanceK(root, target, 2);

    cout << "Nodes at distance 2 from target (5): ";
    for (int v : res) cout << v << " ";
    cout << endl;

    // ✅ Expected: 7 4 1 (order may vary depending on BFS)

    return 0;
}
