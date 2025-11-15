#include <bits/stdc++.h>
using namespace std;

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

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet dsu(n * n);
    int max_size = 0;
    vector<int> x = {-1, 0, 0, 1};
    vector<int> y = {0, -1, 1, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) continue;
            for (int k = 0; k < 4; k++) {
                int x_k = i + x[k];
                int y_k = j + y[k];
                if (x_k >= 0 && x_k < n && y_k >= 0 && y_k < n) {
                    if (grid[x_k][y_k]) {
                        int node = (i * n) + j;
                        int adj_node = (x_k * n) + y_k;
                        dsu.unionBySize(node, adj_node);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) continue;
            unordered_set<int> parents;
            for (int k = 0; k < 4; k++) {
                int x_k = i + x[k];
                int y_k = j + y[k];
                if (x_k >= 0 && x_k < n && y_k >= 0 && y_k < n) {
                    if (grid[x_k][y_k]) {
                        int adj_node = (x_k * n) + y_k;
                        parents.insert(dsu.findParent(adj_node));
                    }
                }
            }
            int size = 0;
            for (int p : parents) size += dsu.size[p];
            max_size = max(max_size, size + 1);
        }
    }

    for (int i = 0; i < n * n; i++)
        max_size = max(max_size, dsu.size[i]);

    return max_size;
}

int main() {
    vector<vector<vector<int>>> testCases = {
        {{1, 0}, {1, 1}},
        {{1, 1}, {1, 1}},
        {{0, 0}, {0, 0}},
        {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}}
    };

    for (auto& grid : testCases) {
        cout << "Grid:\n";
        for (auto& row : grid) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }

        cout << "Largest Island Size: " << largestIsland(grid) << "\n\n";
    }

    return 0;
}
