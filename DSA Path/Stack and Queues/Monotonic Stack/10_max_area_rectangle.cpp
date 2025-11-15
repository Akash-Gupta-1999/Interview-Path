#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<pair<int,int>> st;  // (height, index)
    int n = heights.size();
    int Amax = 0;

    for(int i=0; i <= n; i++) {
        while(!st.empty() && (i == n || st.top().first > heights[i])) {
            pair<int,int> bar = st.top(); st.pop();
            int width = st.empty() ? i : i - st.top().second - 1;
            int area = width * bar.first;
            Amax = max(Amax, area);
        }
        if(i != n) st.push({heights[i], i});
    }
    return Amax;
}

int main() {
    vector<vector<int>> testcases = {
        {},                       // empty input
        {5},                      // single bar
        {2,2,2,2},                // all equal
        {4,5,6,7,4},              // increasing then drop
        {7,6,5,4},                // strictly decreasing
        {2,1,5,6,2,3},            // classic example
        {1000,1000,1000},         // large equal values
        {1,2,3,4,5},              // strictly increasing
        {5,4,3,2,1},              // strictly decreasing
        {6,7,5},                  // tricky mid drop
    };

    for (int t = 0; t < testcases.size(); t++) {
        vector<int> heights = testcases[t];
        cout << "Testcase " << t+1 << ": [";
        for (int i = 0; i < heights.size(); i++) {
            cout << heights[i] << (i+1 < heights.size() ? "," : "");
        }
        cout << "] -> " << largestRectangleArea(heights) << "\n";
    }
    return 0;
}
