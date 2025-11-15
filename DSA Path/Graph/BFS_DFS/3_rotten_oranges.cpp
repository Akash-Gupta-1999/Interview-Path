#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    int time = 0;
    vector<int> x = {-1, 0, 0, 1};
    vector<int> y = {0, 1, -1, 0};

    int rows = grid.size();
    int cols = grid[0].size();

    // Push all initially rotten oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int size = q.size();
        bool rotted = false; // track if any fresh got rotten in this round

        for (int i = 0; i < size; i++) {
            auto coord = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int x_c = coord.first + x[dir];
                int y_c = coord.second + y[dir];

                // ✅ boundary check fixed
                if (x_c >= 0 && x_c < rows && y_c >= 0 && y_c < cols && grid[x_c][y_c] == 1) {
                    grid[x_c][y_c] = 2;
                    q.push({x_c, y_c});
                    rotted = true;
                }
            }
        }

        if (rotted) time++; // increment time only if some fresh oranges got rotten
    }

    // Check if any fresh oranges remain
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) return -1;
        }
    }

    return time;
}

int main() {
    // Test case 1
    vector<vector<int>> grid1 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << "Test Case 1: " << orangesRotting(grid1) << endl;
    // Expected: 4

    // Test case 2
    vector<vector<int>> grid2 = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };
    cout << "Test Case 2: " << orangesRotting(grid2) << endl;
    // Expected: -1 (fresh oranges remain unreachable)

    // Test case 3
    vector<vector<int>> grid3 = {
        {0,2}
    };
    cout << "Test Case 3: " << orangesRotting(grid3) << endl;
    // Expected: 0 (no fresh oranges)

    // Test case 4
    vector<vector<int>> grid4 = {
        {1}
    };
    cout << "Test Case 4: " << orangesRotting(grid4) << endl;
    // Expected: -1 (fresh orange never rots)

    // Test case 5
    vector<vector<int>> grid5 = {
        {2,2,0,1}
    };
    cout << "Test Case 5: " << orangesRotting(grid5) << endl;
    // Expected: -1 (fresh orange isolated)

    return 0;
}
