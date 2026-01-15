#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementNK(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    // Voting phase
    for (int x : nums) {
        if (freq.count(x)) {
            freq[x]++;
        } else if (freq.size() < k - 1) {
            freq[x] = 1;
        } else {
            for (auto it = freq.begin(); it != freq.end();) {
                if (--it->second == 0)
                    it = freq.erase(it);
                else
                    ++it;
            }
        }
    }

    // Verification phase
    unordered_map<int, int> realCount;
    for (int x : nums)
        if (freq.count(x))
            realCount[x]++;

    vector<int> res;
    for (auto& [num, _] : freq)
        if (realCount[num] > nums.size() / k)
            res.push_back(num);

    return res;
}

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 1, 2, 1, 1},        // majority > n/3
        {3, 2, 3},                  // majority > n/2
        {1, 1, 1, 2, 2, 3, 3, 3},    // multiple > n/4
        {1, 2, 3, 4, 5, 6},          // no majority
        {2, 2, 2, 2},               // single element
    };

    vector<int> ks = {3, 2, 4, 3, 3};

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        int k = ks[i];

        vector<int> result = majorityElementNK(nums, k);

        cout << "Test Case " << i + 1 << ":\n";
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\n";

        cout << "k = " << k << "\n";
        cout << "Majority elements (> n/" << k << "): ";

        if (result.empty()) {
            cout << "None";
        } else {
            for (int x : result) cout << x << " ";
        }

        cout << "\n--------------------------\n";
    }

    return 0;
}
