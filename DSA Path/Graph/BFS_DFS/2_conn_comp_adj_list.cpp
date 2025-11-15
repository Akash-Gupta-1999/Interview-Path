#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, vector<int>& visited, int start) {
    visited[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

int countConnectedComponents(vector<vector<int>>& adj) {
    int n = adj.size();
    int provinces = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(adj, visited, i);
            provinces++;
        }
    }
    return provinces;
}

int main() {
    // Test case 1
    vector<vector<int>> adj1 = {
        {1},        // 0 connected to 1
        {0},        // 1 connected to 0
        {3},        // 2 connected to 3
        {2}         // 3 connected to 2
    };
    cout << "Test Case 1: " << countConnectedComponents(adj1) << endl; 
    // Expected: 2  ({0,1}, {2,3})

    // Test case 2
    vector<vector<int>> adj2 = {
        {}, {}, {}
    };
    cout << "Test Case 2: " << countConnectedComponents(adj2) << endl; 
    // Expected: 3 (all isolated)

    // Test case 3
    vector<vector<int>> adj3 = {
        {1,2}, 
        {0,2}, 
        {0,1}
    };
    cout << "Test Case 3: " << countConnectedComponents(adj3) << endl; 
    // Expected: 1 (fully connected)

    // Test case 4
    vector<vector<int>> adj4 = {
        {}
    };
    cout << "Test Case 4: " << countConnectedComponents(adj4) << endl; 
    // Expected: 1

    return 0;
}
