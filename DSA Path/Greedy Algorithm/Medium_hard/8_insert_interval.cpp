#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& ninv) {
    int i = 0;
    vector<vector<int>> ans;
    bool inserted = false;  // flag to track if ninv is placed

    while (i < inv.size()) {
        if (ninv[1] < inv[i][0]) {   // new interval before current
            ans.push_back(ninv);
            inserted = true;
            break;
        } else if (ninv[0] > inv[i][1]) {  // new interval after current
            ans.push_back(inv[i]);
            i++;
        } else { // overlap → merge
            ninv[0] = min(ninv[0], inv[i][0]);
            ninv[1] = max(ninv[1], inv[i][1]);
            i++;
        }
    }

    // push remaining old intervals
    while (i < inv.size()) {
        ans.push_back(inv[i]);
        i++;
    }

    // if ninv was never inserted
    if (!inserted) ans.push_back(ninv);

    return ans;
}

// Utility to print intervals
void printIntervals(vector<vector<int>> res) {
    for (auto &v : res) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;
}

int main() {
    // ✅ Test case 1: Insert overlapping in middle
    vector<vector<int>> inv1 = {{1,3},{6,9}};
    vector<int> ninv1 = {2,5};
    auto res1 = insert(inv1, ninv1);
    cout << "Test 1: ";
    printIntervals(res1);
    // Expected: [[1,5],[6,9]]

    // ✅ Test case 2: Merge multiple overlaps
    vector<vector<int>> inv2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> ninv2 = {4,8};
    auto res2 = insert(inv2, ninv2);
    cout << "Test 2: ";
    printIntervals(res2);
    // Expected: [[1,2],[3,10],[12,16]]

    // ✅ Test case 3: Insert before all
    vector<vector<int>> inv3 = {{3,5},{6,9}};
    vector<int> ninv3 = {1,2};
    auto res3 = insert(inv3, ninv3);
    cout << "Test 3: ";
    printIntervals(res3);
    // Expected: [[1,2],[3,5],[6,9]]

    // ✅ Test case 4: Insert after all
    vector<vector<int>> inv4 = {{1,2},{3,5}};
    vector<int> ninv4 = {6,7};
    auto res4 = insert(inv4, ninv4);
    cout << "Test 4: ";
    printIntervals(res4);
    // Expected: [[1,2],[3,5],[6,7]]

    // ✅ Test case 5: Insert covers all
    vector<vector<int>> inv5 = {{2,3},{4,5},{6,7}};
    vector<int> ninv5 = {1,8};
    auto res5 = insert(inv5, ninv5);
    cout << "Test 5: ";
    printIntervals(res5);
    // Expected: [[1,8]]

    return 0;
}
