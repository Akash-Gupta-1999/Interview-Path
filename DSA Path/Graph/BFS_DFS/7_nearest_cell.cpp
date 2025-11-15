#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int,int>> q;

    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    // Start BFS from all 0's
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Multi-source BFS
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (dist[nr][nc] > dist[r][c] + 1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    return dist;
}

void printMatrix(const vector<vector<int>>& mat) {
    for (auto &row : mat) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test Case 1: Mixed 0s and 1s
    vector<vector<int>> mat1 = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    cout << "Test Case 1:\n";
    printMatrix(updateMatrix(mat1));
    // Expected:
    // 0 0 0
    // 0 1 0
    // 1 2 1

    cout << endl;

    // Test Case 2: All ones (only one 0 in corner)
    vector<vector<int>> mat2 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 1, 1}
    };
    cout << "Test Case 2:\n";
    printMatrix(updateMatrix(mat2));
    // Expected:
    // 2 3 4
    // 1 2 3
    // 0 1 2

    cout << endl;

    // Test Case 3: All zeros
    vector<vector<int>> mat3 = {
        {0, 0},
        {0, 0}
    };
    cout << "Test Case 3:\n";
    printMatrix(updateMatrix(mat3));
    // Expected:
    // 0 0
    // 0 0

    cout << endl;

    // Test Case 4: Single row
    vector<vector<int>> mat4 = {
        {1, 1, 0, 1, 1}
    };
    cout << "Test Case 4:\n";
    printMatrix(updateMatrix(mat4));
    // Expected:
    // 2 1 0 1 2

    cout << endl;

    // Test Case 5: Single column
    vector<vector<int>> mat5 = {
        {1},
        {1},
        {0},
        {1}
    };
    cout << "Test Case 5:\n";
    printMatrix(updateMatrix(mat5));
    // Expected:
    // 2
    // 1
    // 0
    // 1

    return 0;
}
