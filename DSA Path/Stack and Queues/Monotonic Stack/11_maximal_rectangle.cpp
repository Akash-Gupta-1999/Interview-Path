#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights){
    stack<pair<int,int>> st;
    int maxA = 0;
    int n = heights.size();
    for(int i=0; i<=n; i++){
        while(!st.empty() && (i == n || st.top().first > heights[i])){
            auto hist = st.top(); st.pop();
            int width = st.empty() ? i : i - st.top().second - 1;
            maxA = max(maxA, width * hist.first);
        }
        if(i != n) st.push({heights[i], i});
    }
    return maxA;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int maxA = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        maxA = max(maxA, largestRectangleArea(heights));
    }
    return maxA;
}

int main() {
    vector<vector<vector<char>>> testcases = {
        {}, // empty matrix
        {{'0','0','0'}}, // single row, all zeros
        {{'1','1','1'}}, // single row, all ones
        {{'1'},{'1'},{'1'}}, // single col, all ones
        {{'1','0','1','0','0'},
         {'1','0','1','1','1'},
         {'1','1','1','1','1'},
         {'1','0','0','1','0'}}, // mixed case (classic LC example)
        {{'1','1','1','1'},
         {'1','1','1','1'},
         {'1','1','1','1'}}, // full 3x4 of ones
        {{'0','1'},
         {'1','0'}} // diagonal ones
    };

    for(int t=0; t<testcases.size(); t++){
        cout << "Testcase " << t+1 << " -> " 
             << maximalRectangle(testcases[t]) << "\n";
    }
    return 0;
}
