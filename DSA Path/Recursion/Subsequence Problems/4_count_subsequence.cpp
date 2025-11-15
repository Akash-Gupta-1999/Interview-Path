#include <bits/stdc++.h>
using namespace std;

// 📝 Function to implement
int countSubsequencesWithSumK(int i,int sum,vector<int>& nums, int k) {
    if(i == nums.size()){
        if(sum == k)
            return 1;
        return 0;
    }
    int l = countSubsequencesWithSumK(i+1,sum+nums[i],nums,k);
    int r = countSubsequencesWithSumK(i+1,sum,nums,k);
    return l+r;
}

int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 1}, 3},       // Expected: 2 (subsequences: {1,2}, {2,1})
        {{1, 2, 3}, 3},       // Expected: 2 ({1,2}, {3})
        {{1, 1, 1}, 2},       // Expected: 3 ({1,1} three different ways)
        {{2, 4, 6, 10}, 16},  // Expected: 2 ({6,10}, {2,4,10})
        {{}, 0},              // Expected: 1 (empty subsequence)
        {{1, -1, 2, -2}, 0}   // Expected: 4 ({1,-1}, {2,-2}, {1,-1,2,-2}, {})
    };

    for (int i = 0; i < testCases.size(); i++) {
        auto nums = testCases[i].first;
        int k = testCases[i].second;

        cout << "Test case " << i + 1 << ": ";
        cout << "Array = { ";
        for (auto x : nums) cout << x << " ";
        cout << "}, k = " << k << "\n";

        int result = countSubsequencesWithSumK(0,0,nums, k);
        cout << "Result: " << result << "\n\n";
    }

    return 0;
}
