#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> mat(n, vector<int>(n, INT_MAX));

    for (auto &it : edges) {
        mat[it[0]][it[1]] = it[2];
        mat[it[1]][it[0]] = it[2];
    }

    for (int i = 0; i < n; i++) mat[i][i] = 0;

    // Floyd–Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    int ans = -1, min_city = INT_MAX;
    for (int i = 0; i < n; i++) {
        int city = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] <= distanceThreshold)
                city++;
        }
        if (city <= min_city) {
            min_city = city;
            ans = i;
        }
    }

    return ans;
}

// ==============================
// Main + multiple test cases
// ==============================
int main() {
    vector<tuple<int, vector<vector<int>>, int>> testCases = {
        {4, {{0,1,3},{1,2,1},{1,3,4},{2,3,1}}, 4},  // Expected: 3
        {5, {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}}, 2}, // Expected: 0
        {6, {{0,1,7},{0,2,9},{1,3,10},{2,3,2},{3,4,1},{4,5,2}}, 9}, // Custom
    };

    for (int t = 0; t < testCases.size(); t++) {
        auto [n, edges, threshold] = testCases[t];
        cout << "Test Case " << t + 1 << ":\n";
        cout << "n = " << n << ", threshold = " << threshold << "\nEdges: ";
        for (auto &e : edges)
            cout << "{" << e[0] << "," << e[1] << "," << e[2] << "} ";
        cout << "\n";

        cout << "Output City: " << findTheCity(n, edges, threshold) << "\n\n";
    }

    return 0;
}
