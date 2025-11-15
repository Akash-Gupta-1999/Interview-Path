#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to print Top View of a Binary Tree
vector<int> topView(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    queue<pair<TreeNode*,int>> q;
    int mincol=0,maxcol=0;
    unordered_map<int,int> hash;
    q.push({root,0});
    while(!q.empty()){
        auto tmp = q.front(); q.pop();
        TreeNode* n = tmp.first;
        int idx = tmp.second;
        if(hash.find(idx) == hash.end())
            hash[idx] = n->val;
        mincol = min(mincol,idx);
        maxcol = max(maxcol,idx);
        if(n->left) q.push({n->left,idx-1});
        if(n->right) q.push({n->right,idx+1});
    }
    for(int i=mincol;i<=maxcol;i++)
        ans.push_back(hash[i]);
    return ans;
}

int main() {
    /*
            1
           / \
          2   3
           \   \
            4   5
             \
              6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    // Call topView function
    vector<int> result = topView(root);

    // Print result
    cout << "Top View: ";
    for (int v : result) cout << v << " ";
    cout << endl;

    // ✅ Expected output for this tree:
    // Top View: 2 1 3 5

    return 0;
}
