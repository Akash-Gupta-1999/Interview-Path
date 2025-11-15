#include <bits/stdc++.h>
using namespace std;

void rec_sum(int i, vector<int>& curr, vector<vector<int>>& res, vector<int>& candidates, int target) {
    if (i == candidates.size()) {
        if (target == 0)
            res.push_back(curr);
        return;
    }
    if (candidates[i] <= target) {
        curr.push_back(candidates[i]);
        rec_sum(i, curr, res, candidates, target - candidates[i]);
        curr.pop_back();
    }
    rec_sum(i + 1, curr, res, candidates, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> curr;
    rec_sum(0, curr, res, candidates, target);
    return res;
}

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{2, 3, 6, 7}, 7},       // Expected: [[2,2,3], [7]]
        {{2, 3, 5}, 8},          // Expected: [[2,2,2,2], [2,3,3], [3,5]]
        {{2}, 1},                // Expected: []
        {{1}, 2},                // Expected: [[1,1]]
        {{1}, 1},                // Expected: [[1]]
        {{3, 4, 5}, 8}           // Expected: [[3,5], [4,4]]
    };

    for (int t = 0; t < testCases.size(); t++) {
        auto candidates = testCases[t].first;
        int target = testCases[t].second;

        cout << "Test case " << t + 1 << ": ";
        cout << "Candidates = { ";
        for (auto x : candidates) cout << x << " ";
        cout << "}, Target = " << target << "\n";

        auto result = combinationSum(candidates, target);

        cout << "Combinations:\n";
        if (result.empty()) {
            cout << "  No combination found.\n";
        } else {
            for (auto& comb : result) {
                cout << "  { ";
                for (auto num : comb) cout << num << " ";
                cout << "}\n";
            }
        }
        cout << "\n";
    }

    return 0;
}
