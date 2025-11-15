#include <bits/stdc++.h>
using namespace std;

void rec_find(int row,int col,string curr,vector<vector<int>>& m,vector<string>& ans,int n){
    if(row == n-1 && col == n-1){
        ans.push_back(curr);
        return;
    }
    vector<int> x = {0,-1,1,0};
    vector<int> y = {-1,0,0,1};
    vector<char> d = {'L','U','D','R'};
    for(int k=0;k<x.size();k++){
        int row_k = row + x[k];
        int col_k = col + y[k];
        if(row_k>=0 && col_k>=0 && row_k<n && col_k<n && m[row_k][col_k] != 0){
            curr += d[k];
            m[row_k][col_k] = 0;
            rec_find(row_k,col_k,curr,m,ans,n);
            curr.pop_back();
            m[row_k][col_k] = 1;
        }
    }
}

// Function to implement
vector<string> findPath(vector<vector<int>>& m, int n) {
    // TODO: Implement your solution here
    vector<string> ans;
    if (m[0][0] == 0 || m[n-1][n-1] == 0) return ans; // No path if start/end blocked
    m[0][0] = 0; // mark start as visited
    rec_find(0,0,"",m,ans,n);
    return ans; // Return all possible paths in lexicographical order
}

int main() {
    // Testcase 1
    int N1 = 4;
    vector<vector<int>> m1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> res1 = findPath(m1, N1);
    cout << "Testcase 1 Output: ";
    if (res1.empty()) cout << "-1";
    else {
        for (string &path : res1) cout << path << " ";
    }
    cout << "\n";

    // Testcase 2
    int N2 = 4;
    vector<vector<int>> m2 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 1, 1},
        {0, 0, 1, 1}
    };
    vector<string> res2 = findPath(m2, N2);
    cout << "Testcase 2 Output: ";
    if (res2.empty()) cout << "-1";
    else {
        for (string &path : res2) cout << path << " ";
    }
    cout << "\n";

    // Testcase 3 (No path)
    int N3 = 2;
    vector<vector<int>> m3 = {
        {1, 0},
        {0, 1}
    };
    vector<string> res3 = findPath(m3, N3);
    cout << "Testcase 3 Output: ";
    if (res3.empty()) cout << "-1";
    else {
        for (string &path : res3) cout << path << " ";
    }
    cout << "\n";

    return 0;
}
