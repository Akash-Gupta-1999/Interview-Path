#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    
    // Min-heap: {effort, row, col}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};

    dist[0][0] = 0;
    pq.push({0,0,0}); // {effort, row, col}

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int d = cur[0], i = cur[1], j = cur[2];

        if (i == m-1 && j == n-1) return d; // ✅ early exit
        if (d > dist[i][j]) continue;       // ✅ skip outdated states

        for (int k = 0; k < 4; k++) {
            int x_c = i + dx[k];
            int y_c = j + dy[k];
            if (x_c >= 0 && x_c < m && y_c >= 0 && y_c < n) {
                int abs_diff = abs(heights[i][j] - heights[x_c][y_c]);
                int new_effort = max(abs_diff, d);
                if (new_effort < dist[x_c][y_c]) {
                    dist[x_c][y_c] = new_effort;
                    pq.push({new_effort, x_c, y_c});
                }
            }
        }
    }

    return dist[m-1][n-1];
}

int main() {
    // ---------- Testcase 1 ----------
    {
        vector<vector<int>> heights = {
            {1,2,2},
            {3,8,2},
            {5,3,5}
        };
        cout << "TC1 -> Minimum Effort: " << minimumEffortPath(heights) << endl; // Expected 2
    }

    // ---------- Testcase 2 ----------
    {
        vector<vector<int>> heights = {
            {1,2,3},
            {3,8,4},
            {5,3,5}
        };
        cout << "TC2 -> Minimum Effort: " << minimumEffortPath(heights) << endl; // Expected 1
    }

    // ---------- Testcase 3 ----------
    {
        vector<vector<int>> heights = {
            {1,2,1,1,1},
            {1,2,1,2,1},
            {1,2,1,2,1},
            {1,2,1,2,1},
            {1,1,1,2,1}
        };
        cout << "TC3 -> Minimum Effort: " << minimumEffortPath(heights) << endl; // Expected 0
    }

    // ---------- Testcase 4 (Single Cell) ----------
    {
        vector<vector<int>> heights = {
            {42}
        };
        cout << "TC4 -> Minimum Effort: " << minimumEffortPath(heights) << endl; // Expected 0
    }

    // ---------- Testcase 5 (2x2 grid) ----------
    {
        vector<vector<int>> heights = {
            {1,100},
            {1,1}
        };
        cout << "TC5 -> Minimum Effort: " << minimumEffortPath(heights) << endl; // Expected 0
    }

    return 0;
}
