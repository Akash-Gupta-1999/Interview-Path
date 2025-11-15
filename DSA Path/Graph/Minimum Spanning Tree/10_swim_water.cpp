#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Function: swimInWater
// ==========================================
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> x = {-1, 0, 0, 1};
    vector<int> y = {0, -1, 1, 0};

    pq.push({grid[0][0], 0, 0});
    visited[0][0] = 1;

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int time = it[0], i = it[1], j = it[2];

        if (i == n - 1 && j == n - 1) return time;

        for (int k = 0; k < 4; k++) {
            int x_k = i + x[k];
            int y_k = j + y[k];
            if (x_k >= 0 && x_k < n && y_k >= 0 && y_k < n && !visited[x_k][y_k]) {
                visited[x_k][y_k] = 1;
                pq.push({max(time, grid[x_k][y_k]), x_k, y_k});
            }
        }
    }
    return -1; // unreachable
}

// ==========================================
// Main Function with Multiple Test Cases
// ==========================================
int main() {
    vector<vector<vector<int>>> testCases = {
        {{0, 2}, {1, 3}},                               // Expected: 3
        {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16},
         {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}},       // Expected: 16
        {{3, 2}, {0, 1}},                               // Expected: 3
        {{10, 12, 4}, {6, 8, 2}, {1, 3, 5}}             // Example case
    };

    for (int t = 0; t < testCases.size(); t++) {
        cout << "==============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "==============================\n";

        vector<vector<int>> grid = testCases[t];
        cout << "Grid:\n";
        for (auto &row : grid) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }

        int result = swimInWater(grid);
        cout << "Minimum time to reach destination: " << result << "\n\n";
    }

    return 0;
}
