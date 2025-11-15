#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class comp {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if (a.first != b.first) return a.first < b.first; // sort by row
        return a.second < b.second;                       // if same row, sort by value
    }
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    
    queue<pair<TreeNode*,pair<int,int>>> q; // node, {row,col}
    unordered_map<int,vector<pair<int,int>>> hash;
    int maxcol = 0, mincol = 0;
    
    q.push({root,{0,0}});
    while(!q.empty()){
        auto temp = q.front(); q.pop();
        TreeNode* n = temp.first;
        int row = temp.second.first, col = temp.second.second;
        
        hash[col].push_back({row,n->val});
        maxcol = max(maxcol,col);
        mincol = min(mincol,col);
        
        if(n->left)  q.push({n->left,{row+1,col-1}});
        if(n->right) q.push({n->right,{row+1,col+1}});
    }
    
    vector<vector<int>> ans;
    for(int i=mincol;i<=maxcol;i++){
        sort(hash[i].begin(), hash[i].end(), comp());
        vector<int> lvl;
        for(auto &p : hash[i])
            lvl.push_back(p.second);
        ans.push_back(lvl);
    }
    return ans;
}

int main() {
    /*
            3
           / \
          9   20
             /  \
            15   7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    auto res = verticalTraversal(root);
    for (auto &col : res) {
        for (int v : col) cout << v << " ";
        cout << endl;
    }
}
