#include <bits/stdc++.h>
using namespace std;

// ==============================
// Function: floydWarshall
// ==============================
vector<vector<int>> floydWarshall(int n, vector<vector<int>>& matrix) {
    const int INF = 1e9;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Detect negative cycle
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < 0) {
            cout << "Graph contains a Negative Cycle!\n";
            break;
        }
    }

    return matrix;
}

// ==============================
// Main function with test cases
// ==============================
int main() {
    const int INF = 1e9;

    // ---------- Testcase 1: Basic graph ----------
    {
        int n = 4;
        vector<vector<int>> matrix = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
        };
        cout << "Test Case 1 (Basic Graph):\n";
        auto dist = floydWarshall(n, matrix);
        for (auto &row : dist) {
            for (auto val : row)
                cout << (val == INF ? "INF " : to_string(val) + " ");
            cout << "\n";
        }
        cout << "\n";
    }

    // ---------- Testcase 2: With negative edge ----------
    {
        int n = 3;
        vector<vector<int>> matrix = {
            {0, 1, INF},
            {INF, 0, -1},
            {2, INF, 0}
        };
        cout << "Test Case 2 (With Negative Edge):\n";
        auto dist = floydWarshall(n, matrix);
        for (auto &row : dist) {
            for (auto val : row)
                cout << (val == INF ? "INF " : to_string(val) + " ");
            cout << "\n";
        }
        cout << "\n";
    }

    // ---------- Testcase 3: Mixed weights ----------
    {
        int n = 4;
        vector<vector<int>> matrix = {
            {0, 3, INF, 7},
            {8, 0, 2, INF},
            {5, INF, 0, 1},
            {2, INF, INF, 0}
        };
        cout << "Test Case 3 (Mixed Weights):\n";
        auto dist = floydWarshall(n, matrix);
        for (auto &row : dist) {
            for (auto val : row)
                cout << (val == INF ? "INF " : to_string(val) + " ");
            cout << "\n";
        }
        cout << "\n";
    }

    // ---------- Testcase 4: Negative cycle ----------
    {
        int n = 3;
        vector<vector<int>> matrix = {
            {0, 1, INF},
            {INF, 0, -2},
            {-1, INF, 0}
        };
        cout << "Test Case 4 (Negative Cycle):\n";
        auto dist = floydWarshall(n, matrix);
        for (auto &row : dist) {
            for (auto val : row)
                cout << (val == INF ? "INF " : to_string(val) + " ");
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
