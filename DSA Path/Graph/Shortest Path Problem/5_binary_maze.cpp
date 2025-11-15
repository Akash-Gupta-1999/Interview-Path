#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) return -1;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int,int>> q;
    vector<int> dx = {0,1,1,1,0,-1,-1,-1};
    vector<int> dy = {1,1,0,-1,-1,-1,0,1};
    dist[0][0] = 1;
    q.push({0,0});
    while (!q.empty()) {
        auto [i,j] = q.front(); q.pop();
        for (int k = 0; k < 8; k++) {
            int x_c = i + dx[k];
            int y_c = j + dy[k];
            if (x_c >= 0 && x_c < m && y_c >= 0 && y_c < n) {
                if (grid[x_c][y_c] == 0 && dist[i][j] + 1 < dist[x_c][y_c]) {
                    dist[x_c][y_c] = dist[i][j] + 1;
                    q.push({x_c,y_c});
                }
            }
        }
    }
    if (dist[m-1][n-1] == INT_MAX) return -1;
    return dist[m-1][n-1];
}

int main() {
    // ---------- Testcase 1 ----------
    {
        vector<vector<int>> grid = {
            {0,1},
            {1,0}
        };
        cout << "TC1: " << shortestPathBinaryMatrix(grid) << endl; 
        // Expected: 2 (path is (0,0) -> (1,1))
    }

    // ---------- Testcase 2 ----------
    {
        vector<vector<int>> grid = {
            {0,0,0},
            {1,1,0},
            {1,1,0}
        };
        cout << "TC2: " << shortestPathBinaryMatrix(grid) << endl;
        // Expected: 4 (path is (0,0)->(0,1)->(0,2)->(1,2)->(2,2))
    }

    // ---------- Testcase 3 ----------
    {
        vector<vector<int>> grid = {
            {1,0},
            {0,0}
        };
        cout << "TC3: " << shortestPathBinaryMatrix(grid) << endl;
        // Expected: -1 (start blocked)
    }

    // ---------- Testcase 4 ----------
    {
        vector<vector<int>> grid = {
            {0}
        };
        cout << "TC4: " << shortestPathBinaryMatrix(grid) << endl;
        // Expected: 1 (already at destination)
    }

    // ---------- Testcase 5 ----------
    {
        vector<vector<int>> grid = {
            {0,0,0},
            {0,1,0},
            {0,0,0}
        };
        cout << "TC5: " << shortestPathBinaryMatrix(grid) << endl;
        // Expected: 3 (diagonal path: (0,0) -> (1,1) -> (2,2))
    }

    return 0;
}
