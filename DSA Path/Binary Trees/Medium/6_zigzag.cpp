#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🔹 Approach 1: Two Stack Solution
vector<vector<int>> zigzagLevelOrderTwoStack(TreeNode* root) {
    if (!root) return {};
    
    stack<TreeNode*> s1, s2;
    vector<vector<int>> ans;
    
    s1.push(root);
    
    while (!s1.empty() || !s2.empty()) {
        vector<int> level;
        
        if (!s1.empty()) {
            while (!s1.empty()) {
                TreeNode* temp = s1.top(); s1.pop();
                level.push_back(temp->val);
                if (temp->left)  s2.push(temp->left);
                if (temp->right) s2.push(temp->right);
            }
        } else {
            while (!s2.empty()) {
                TreeNode* temp = s2.top(); s2.pop();
                level.push_back(temp->val);
                if (temp->right) s1.push(temp->right);
                if (temp->left)  s1.push(temp->left);
            }
        }
        ans.push_back(level);
    }
    
    return ans;
}

// 🔹 Approach 2: Single Queue + Direction Flag
vector<vector<int>> zigzagLevelOrderQueue(TreeNode* root) {
    if (!root) return {};
    
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    bool leftToRight = true;
    
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            int idx = leftToRight ? i : (size - 1 - i);
            level[idx] = node->val;
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        ans.push_back(level);
        leftToRight = !leftToRight;
    }
    
    return ans;
}

// Utility: Print 2D vector
void printLevels(const vector<vector<int>>& levels) {
    cout << "[";
    for (int i = 0; i < levels.size(); i++) {
        cout << "[";
        for (int j = 0; j < levels[i].size(); j++) {
            cout << levels[i][j];
            if (j + 1 < levels[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < levels.size()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "🔹 Two Stack Zigzag: ";
    printLevels(zigzagLevelOrderTwoStack(root)); // [[1],[3,2],[4,5,6]]

    cout << "🔹 Queue + Flag Zigzag: ";
    printLevels(zigzagLevelOrderQueue(root));    // [[1],[3,2],[4,5,6]]

    return 0;
}
