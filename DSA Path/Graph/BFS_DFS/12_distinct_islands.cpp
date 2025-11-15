#include <bits/stdc++.h>
using namespace std;

// BFS to explore an island and record its shape relative to the starting cell
vector<vector<int>> bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m, int n, int i, int j){
    vector<vector<int>> ans;              // stores relative coordinates of the island
    queue<pair<int,int>> q;               // queue for BFS
    vector<int> x = {-1,0,0,1};          // direction vectors (up, left, right, down)
    vector<int> y = {0,-1,1,0};

    q.push({i,j});                        // push starting cell
    visited[i][j] = 1;                    // mark starting cell as visited
    ans.push_back({0,0});                 // starting cell relative to itself is (0,0)

    while(!q.empty()){
        auto [a,b] = q.front(); q.pop();  // current cell
        for(int k=0;k<4;k++){
            int a_c = a + x[k];           // next row
            int b_c = b + y[k];           // next column
            // check bounds
            if(a_c>=0 && a_c<m && b_c>=0 && b_c<n){
                // if it's land and not visited
                if(!visited[a_c][b_c] && grid[a_c][b_c]){
                    q.push({a_c,b_c});            // add to queue
                    visited[a_c][b_c] = 1;        // mark visited
                    ans.push_back({a_c-i,b_c-j}); // store relative coordinates
                }
            }
        }
    }
    return ans;  // return the shape of the island
}

// Function to count the number of distinct islands
// Input: grid - 2D matrix of 0s (water) and 1s (land)
// Output: number of distinct islands
int numDistinctIslands(vector<vector<int>>& grid) {
    set<vector<vector<int>>> islands;   // to store unique island shapes
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n,0)); // visited matrix

    // traverse the grid
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // if cell is unvisited land
            if(!visited[i][j] && grid[i][j] == 1){
                vector<vector<int>> shape = bfs(grid, visited, m, n, i, j); // explore island
                islands.insert(shape); // insert shape into set (duplicates automatically ignored)
            }
        }
    }
    return islands.size(); // number of distinct islands
}

int main() {
    // Testcase 1
    vector<vector<int>> grid1 = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };
    cout << "TC1: Number of distinct islands = " << numDistinctIslands(grid1) << endl;

    // Testcase 2
    vector<vector<int>> grid2 = {
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,0,1},
        {1,1,0,1,1}
    };
    cout << "TC2: Number of distinct islands = " << numDistinctIslands(grid2) << endl;

    // Testcase 3 (no islands)
    vector<vector<int>> grid3 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    cout << "TC3: Number of distinct islands = " << numDistinctIslands(grid3) << endl;

    // Testcase 4 (single island)
    vector<vector<int>> grid4 = {
        {1,1},
        {1,1}
    };
    cout << "TC4: Number of distinct islands = " << numDistinctIslands(grid4) << endl;

    return 0;
}
