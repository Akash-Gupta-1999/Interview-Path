#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    // Step 2: Traverse and merge
    for (int i = 1; i < intervals.size(); i++) {
        // Overlap → merge with last
        if (intervals[i][0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        } else {
            // No overlap → add new
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

/*
🔹 Intuition (works for any integers):
- Sorting ensures overlapping intervals appear consecutively.
- For each interval:
  - If start ≤ end of last → merge.
  - Else, push new interval.
- Negative values are treated the same way since sorting works on integers.
*/

void printIntervals(vector<vector<int>> res) {
    for (auto &v : res) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
}

int main() {
    // ✅ Test case 1: Normal case
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    cout << "Test 1: ";
    printIntervals(merge(intervals1));
    // Expected: [[1,6],[8,10],[15,18]]

    // ✅ Test case 2: Touching intervals
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    cout << "Test 2: ";
    printIntervals(merge(intervals2));
    // Expected: [[1,5]]

    // ✅ Test case 3: Completely overlapping
    vector<vector<int>> intervals3 = {{6,8},{1,9},{2,4},{4,7}};
    cout << "Test 3: ";
    printIntervals(merge(intervals3));
    // Expected: [[1,9]]

    // ✅ Test case 4: No overlap
    vector<vector<int>> intervals4 = {{1,2},{3,4},{5,6}};
    cout << "Test 4: ";
    printIntervals(merge(intervals4));
    // Expected: [[1,2],[3,4],[5,6]]

    // ✅ Test case 5: Negative intervals
    vector<vector<int>> intervals5 = {{-10,-1},{-5,0},{1,3}};
    cout << "Test 5: ";
    printIntervals(merge(intervals5));
    // Expected: [[-10,0],[1,3]]

    // ✅ Test case 6: Unsorted input with negatives
    vector<vector<int>> intervals6 = {{5,6},{-3,0},{1,2},{-10,-5},{-2,4}};
    cout << "Test 6: ";
    printIntervals(merge(intervals6));
    // Expected: [[-10,-5],[-3,4],[5,6]]

    // ✅ Test case 7: Single interval
    vector<vector<int>> intervals7 = {{5,10}};
    cout << "Test 7: ";
    printIntervals(merge(intervals7));
    // Expected: [[5,10]]

    // ✅ Test case 8: Empty input
    vector<vector<int>> intervals8 = {};
    cout << "Test 8: ";
    printIntervals(merge(intervals8));
    // Expected: []

    return 0;
}
