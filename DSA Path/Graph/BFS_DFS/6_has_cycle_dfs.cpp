#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& visited,int n,vector<vector<int>>& adj,int start,int prev){
    visited[start] = 1;
    for(auto it : adj[start]){
        if(it!=prev && visited[it]) return true;
        if(!visited[it]){
            visited[it] = 1;
            if(dfs(visited,n,adj,it,start)) return true;
        }
    }
    return false;
}

// Function to check if graph contains a cycle
// adj = adjacency list, n = number of vertices
bool hasCycle(vector<vector<int>>& adj, int n) {
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i])
            if(dfs(visited,n,adj,i,-1)) return true;
    }
    return false;
}

int main() {
    // Test case 1: Simple cycle (triangle 0-1-2-0)
    int n1 = 3;
    vector<vector<int>> adj1 = {
        {1,2},   // 0 connected to 1,2
        {0,2},   // 1 connected to 0,2
        {0,1}    // 2 connected to 0,1
    };
    cout << "Test Case 1: " << (hasCycle(adj1, n1) ? "Cycle found" : "No cycle") << endl;
    // Expected: Cycle found

    // Test case 2: Line graph (0-1-2), no cycle
    int n2 = 3;
    vector<vector<int>> adj2 = {
        {1},     // 0 connected to 1
        {0,2},   // 1 connected to 0,2
        {1}      // 2 connected to 1
    };
    cout << "Test Case 2: " << (hasCycle(adj2, n2) ? "Cycle found" : "No cycle") << endl;
    // Expected: No cycle

    // Test case 3: Disconnected graph with a cycle in one component
    int n3 = 5;
    vector<vector<int>> adj3 = {
        {1},       // 0 connected to 1
        {0,2},     // 1 connected to 0,2
        {1},       // 2 connected to 1  --> component {0,1,2} is a line (no cycle)
        {4},       // 3 connected to 4
        {3}        // 4 connected to 3  --> component {3,4} is also a line (no cycle)
    };
    cout << "Test Case 3: " << (hasCycle(adj3, n3) ? "Cycle found" : "No cycle") << endl;
    // Expected: No cycle

    // Test case 4: Disconnected graph with a cycle in one component
    int n4 = 6;
    vector<vector<int>> adj4 = {
        {1},         // 0 connected to 1
        {0,2},       // 1 connected to 0,2
        {1,3},       // 2 connected to 1,3
        {2,4,5},     // 3 connected to 2,4,5
        {3,5},       // 4 connected to 3,5
        {3,4}        // 5 connected to 3,4  --> cycle in {3,4,5}
    };
    cout << "Test Case 4: " << (hasCycle(adj4, n4) ? "Cycle found" : "No cycle") << endl;
    // Expected: Cycle found

    return 0;
}
