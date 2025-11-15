#include <bits/stdc++.h>
using namespace std;

void rec_sum(int idx, vector<int>& candidates, vector<vector<int>>& res, vector<int>& curr, int target) {
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        if (i > idx && candidates[i] == candidates[i - 1]) continue; // skip duplicates
        if (candidates[i] > target) break; // early stop
        curr.push_back(candidates[i]);
        rec_sum(i + 1, candidates, res, curr, target - candidates[i]);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    rec_sum(0, candidates, res, curr, target);
    return res;
}

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{10,1,2,7,6,1,5}, 8},   // Expected: [[1,1,6],[1,2,5],[1,7],[2,6]]
        {{2,5,2,1,2}, 5},        // Expected: [[1,2,2],[5]]
        {{1,1,1,1,1}, 3},        // Expected: [[1,1,1]] (only one unique combo)
        {{3,1,3,5,1}, 8},        // Expected: [[1,3,4], ...] but respecting duplicates rule
        {{2,4,6}, 5},            // Expected: [] (no solution)
        {{1,2}, 4},              // Expected: [] (no solution)
        {{1}, 1}                 // Expected: [[1]]
    };

    for (int t = 0; t < testCases.size(); t++) {
        auto candidates = testCases[t].first;
        int target = testCases[t].second;

        cout << "Test case " << t + 1 << ": ";
        cout << "Candidates = { ";
        for (auto x : candidates) cout << x << " ";
        cout << "}, Target = " << target << "\n";

        auto result = combinationSum2(candidates, target);

        if (result.empty()) {
            cout << "  No combination found.\n";
        } else {
            cout << "  Combinations:\n";
            for (auto& comb : result) {
                cout << "    { ";
                for (auto num : comb) cout << num << " ";
                cout << "}\n";
            }
        }
        cout << "\n";
    }

    return 0;
}
