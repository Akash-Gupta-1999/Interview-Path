#include <bits/stdc++.h>
using namespace std;

// ====================================
// Class: DisjointSet
// ====================================
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);
        if (u_par == v_par) return;

        if (size[u_par] > size[v_par]) {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        } else {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
    }
};

// ====================================
// Function: numOfIslands
// ====================================
// Parameters:
//   n, m - grid dimensions
//   operators - list of positions where land is added
// Returns:
//   Vector of island counts after each addition
// ====================================
vector<int> numOfIslands(int n, int m, vector<pair<int, int>>& operators) {
    vector<int> result;
    vector<vector<int>> visited(n,vector<int>(m,0));
    int components = 0;
    DisjointSet dsu(m*n);
    for(auto it : operators){
        int i = it.first, j = it.second;
        if(visited[i][j]){
            result.push_back(components);
            continue;
        }
        visited[i][j] = 1;
        components++;
        vector<int> x = {-1,0,0,1};
        vector<int> y = {0,-1,1,0};
        for(int k=0;k<x.size();k++){
            int x_k = i + x[k];
            int y_k = j + y[k];
            if(x_k>=0 && x_k<n && y_k>=0 && y_k<m){
                if(visited[x_k][y_k]){
                    int node = (i*m) + j;
                    int adj_node = (x_k * m) + y_k;
                    if(dsu.findParent(node) != dsu.findParent(adj_node)){
                        dsu.unionBySize(node,adj_node);
                        components--;
                    }
                }
            } 
        }
        result.push_back(components);
    }
    return result;
}

// ====================================
// Main Function with Multiple Test Cases
// ====================================
int main() {
    vector<tuple<int, int, vector<pair<int, int>>>> testCases;

    // ---------- Test Case 1 ----------
    {
        int n = 3, m = 3;
        vector<pair<int, int>> ops = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
        testCases.push_back({n, m, ops});
    }

    // ---------- Test Case 2 ----------
    {
        int n = 3, m = 3;
        vector<pair<int, int>> ops = {{0, 0}, {0, 1}, {1, 2}, {1, 2}};
        testCases.push_back({n, m, ops});
    }

    // ---------- Test Case 3 ----------
    {
        int n = 4, m = 5;
        vector<pair<int, int>> ops = {{1, 1}, {0, 1}, {3, 3}, {3, 4}, {1, 0}, {0, 0}};
        testCases.push_back({n, m, ops});
    }

    // ---------- Run All Test Cases ----------
    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "==============================\n";

        int n, m;
        vector<pair<int, int>> ops;
        tie(n, m, ops) = testCases[t];

        cout << "Grid: " << n << " x " << m << "\n";
        cout << "Operators:\n";
        for (auto &p : ops)
            cout << "(" << p.first << ", " << p.second << ")\n";

        auto result = numOfIslands(n, m, ops);

        cout << "Island count after each operation:\n";
        for (int count : result)
            cout << count << " ";
        cout << "\n\n";
    }

    return 0;
}
