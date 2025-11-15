#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end());   // sort by start time
    int count = 0;
    vector<int> ninv = intervals[0];            // current active interval

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < ninv[1]) {        // overlap
            // keep interval with smaller end
            if (intervals[i][1] <= ninv[1])
                ninv = intervals[i];
            count++;
        } else {
            ninv = intervals[i];
        }
    }
    return count;
}

int main() {
    // Test 1
    vector<vector<int>> t1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << eraseOverlapIntervals(t1) << endl;
    // Expected: 1 (remove [1,3])

    // Test 2
    vector<vector<int>> t2 = {{1,2},{1,2},{1,2}};
    cout << eraseOverlapIntervals(t2) << endl;
    // Expected: 2 (remove two of them)

    // Test 3
    vector<vector<int>> t3 = {{1,2},{2,3}};
    cout << eraseOverlapIntervals(t3) << endl;
    // Expected: 0 (no overlaps)

    // Test 4 (with negatives)
    vector<vector<int>> t4 = {{-5,0},{-3,2},{1,3},{2,4}};
    cout << eraseOverlapIntervals(t4) << endl;
    // Expected: 2 (remove [-3,2] and [2,4])

    return 0;
}
