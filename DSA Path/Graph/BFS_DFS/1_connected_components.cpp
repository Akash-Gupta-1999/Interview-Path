#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& isConnected, vector<int>& visited, int n, int start) {
    visited[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] && !visited[j]) { // ✅ correct condition
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int provinces = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(isConnected, visited, n, i);
            provinces++;
        }
    }
    return provinces;
}

int main() {
    // Test case 1
    vector<vector<int>> isConnected1 = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << "Test Case 1: " << findCircleNum(isConnected1) << endl; 
    // Expected: 2 (two provinces: {0,1} and {2})

    // Test case 2
    vector<vector<int>> isConnected2 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout << "Test Case 2: " << findCircleNum(isConnected2) << endl; 
    // Expected: 3 (each city is isolated)

    // Test case 3
    vector<vector<int>> isConnected3 = {
        {1,1,0,0},
        {1,1,1,0},
        {0,1,1,0},
        {0,0,0,1}
    };
    cout << "Test Case 3: " << findCircleNum(isConnected3) << endl; 
    // Expected: 2 (one province {0,1,2}, another {3})

    // Test case 4 (single city)
    vector<vector<int>> isConnected4 = {
        {1}
    };
    cout << "Test Case 4: " << findCircleNum(isConnected4) << endl; 
    // Expected: 1

    return 0;
}
