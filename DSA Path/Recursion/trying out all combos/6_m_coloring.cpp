#include <bits/stdc++.h>
using namespace std;

/*
    M-Coloring Problem Skeleton
    ---------------------------
    Given a graph and an integer M, determine if it can be colored 
    with at most M colors such that no two adjacent vertices 
    share the same color.
*/

// Check if color 'c' can be assigned to 'node'
bool isSafe(int node, int c, vector<int> &color, vector<vector<int>> &adj) {
    // TODO: Check all neighbours of node
    for(int k=0;k<adj.size();k++){
        if(k!=node && adj[node][k] == 1 && color[k] == c)
            return false;
    }
    return true; // placeholder
}

// Backtracking function
bool solve(int node, int n, int m, vector<int> &color, vector<vector<int>> &adj) {
    // TODO: Assign colors recursively
    if(node == n)
        return true;
    for(int i=1;i<=m;i++){
        if(isSafe(node,i,color,adj)){
            color[node] = i;
            if(solve(node+1,n,m,color,adj))
                return true;
            color[node] = 0;
        }
    }
    return false; // placeholder
}

// Wrapper function
bool graphColoring(int n, int m, vector<vector<int>> &adj) {
    vector<int> color(n, 0);
    return solve(0, n, m, color, adj);
}

/* ------------------ MAIN ------------------ */
int main() {
    // ✅ Testcase 1 (Possible: needs 3 colors)
    int n1 = 4, m1 = 3; 
    vector<pair<int,int>> edges1 = {{0,1},{0,2},{1,2},{2,3}};
    vector<vector<int>> adj1(n1, vector<int>(n1, 0));
    for (auto &e : edges1) adj1[e.first][e.second] = adj1[e.second][e.first] = 1;
    cout << "Testcase 1: " 
         << (graphColoring(n1, m1, adj1) ? "Possible" : "Not Possible") << "\n";

    // ❌ Testcase 2 (Not possible: triangle with 2 colors)
    int n2 = 3, m2 = 2;
    vector<pair<int,int>> edges2 = {{0,1},{1,2},{2,0}};
    vector<vector<int>> adj2(n2, vector<int>(n2, 0));
    for (auto &e : edges2) adj2[e.first][e.second] = adj2[e.second][e.first] = 1;
    cout << "Testcase 2: " 
         << (graphColoring(n2, m2, adj2) ? "Possible" : "Not Possible") << "\n";

    // ✅ Testcase 3 (Possible: simple chain, 3 colors more than enough)
    int n3 = 5, m3 = 3;
    vector<pair<int,int>> edges3 = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> adj3(n3, vector<int>(n3, 0));
    for (auto &e : edges3) adj3[e.first][e.second] = adj3[e.second][e.first] = 1;
    cout << "Testcase 3: " 
         << (graphColoring(n3, m3, adj3) ? "Possible" : "Not Possible") << "\n";

    // ❌ Testcase 4 (Not possible: square with diagonal, only 2 colors)
    int n4 = 4, m4 = 2; 
    vector<pair<int,int>> edges4 = {{0,1},{1,2},{2,3},{3,0},{0,2}};
    vector<vector<int>> adj4(n4, vector<int>(n4, 0));
    for (auto &e : edges4) adj4[e.first][e.second] = adj4[e.second][e.first] = 1;
    cout << "Testcase 4: " 
         << (graphColoring(n4, m4, adj4) ? "Possible" : "Not Possible") << "\n";

    // ✅ Testcase 5 (Possible: star graph, 2 colors enough)
    int n5 = 5, m5 = 2;
    vector<pair<int,int>> edges5 = {{0,1},{0,2},{0,3},{0,4}};
    vector<vector<int>> adj5(n5, vector<int>(n5, 0));
    for (auto &e : edges5) adj5[e.first][e.second] = adj5[e.second][e.first] = 1;
    cout << "Testcase 5: " 
         << (graphColoring(n5, m5, adj5) ? "Possible" : "Not Possible") << "\n";

    return 0;
}

