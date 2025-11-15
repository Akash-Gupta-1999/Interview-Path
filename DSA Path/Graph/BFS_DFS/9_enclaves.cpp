#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m, int n, int i, int j) {
    visited[i][j] = 1;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && grid[nx][ny] == 1)
                dfs(grid, visited, m, n, nx, ny);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    // Mark all boundary-connected land cells
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 1 && !visited[i][0])
            dfs(grid, visited, m, n, i, 0);
        if (grid[i][n - 1] == 1 && !visited[i][n - 1])
            dfs(grid, visited, m, n, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == 1 && !visited[0][j])
            dfs(grid, visited, m, n, 0, j);
        if (grid[m - 1][j] == 1 && !visited[m - 1][j])
            dfs(grid, visited, m, n, m - 1, j);
    }

    // Count unvisited land cells (enclaves)
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j])
                ans++;
        }
    }
    return ans;
}

int main() {
    // Test case 1: Basic case
    vector<vector<int>> grid1 = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    cout << "Test Case 1: " << numEnclaves(grid1) << endl;
    // Expected: 3 (the three land cells in the middle are enclaves)

    // Test case 2: All land is on border
    vector<vector<int>> grid2 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    cout << "Test Case 2: " << numEnclaves(grid2) << endl;
    // Expected: 0 (all land is border-connected)

    // Test case 3: One isolated enclave
    vector<vector<int>> grid3 = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << "Test Case 3: " << numEnclaves(grid3) << endl;
    // Expected: 1 (the single land cell is enclosed)

    // Test case 4: No land
    vector<vector<int>> grid4 = {
        {0,0},
        {0,0}
    };
    cout << "Test Case 4: " << numEnclaves(grid4) << endl;
    // Expected: 0

    return 0;
}
