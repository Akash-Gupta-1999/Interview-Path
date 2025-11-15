#include <bits/stdc++.h>
using namespace std;

// ====================================
// Class: DisjointSet (Your Version)
// ====================================
class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);
        if (u_par == v_par) return;

        if (rank[u_par] > rank[v_par])
            parent[v_par] = u_par;
        else if (rank[u_par] < rank[v_par])
            parent[u_par] = v_par;
        else {
            parent[v_par] = u_par;
            rank[u_par]++;
        }
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
// Function: removeStones
// ====================================
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int maxRow = 0, maxCol = 0;

    // Find max row and col to build DSU size
    for (auto &it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjointSet dsu(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;

    // Connect row-node and col-node for each stone
    for (auto &it : stones) {
        int u = it[0];
        int v = maxRow + 1 + it[1];  // offset column indices
        dsu.unionBySize(u, v);
        stoneNodes[u] = 1;
        stoneNodes[v] = 1;
    }

    // Count distinct components
    int components = 0;
    for (auto &it : stoneNodes) {
        if (dsu.findParent(it.first) == it.first)
            components++;
    }

    // Stones that can be removed = total - components
    return n - components;
}

// ====================================
// Main Function with Multiple Test Cases
// ====================================
int main() {
    vector<vector<vector<int>>> testCases = {
        {{0,0}, {0,1}, {1,0}, {1,2}, {2,1}, {2,2}},  // Expected: 5
        {{0,0}, {0,2}, {1,1}, {2,0}, {2,2}},          // Expected: 3
        {{0,1}, {1,2}, {2,3}, {3,4}},                 // Expected: 3
        {{0,0}, {1,1}, {2,2}},                        // Expected: 0 (all isolated)
        {{0,0}, {0,1}, {0,2}, {1,0}, {2,0}}           // Expected: 4
    };

    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "==============================\n";

        vector<vector<int>> stones = testCases[t];
        cout << "Input Stones:\n";
        for (auto &s : stones)
            cout << "(" << s[0] << "," << s[1] << ") ";
        cout << "\n";

        int result = removeStones(stones);
        cout << "Maximum stones that can be removed: " << result << "\n\n";
    }

    return 0;
}
