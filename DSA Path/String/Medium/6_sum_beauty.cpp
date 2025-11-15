#include <bits/stdc++.h>
using namespace std;

// Function to calculate the beauty sum of all substrings
int beautySum(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        vector<int> freq(26, 0);
        for (int j = i; j < s.size(); ++j) {
            freq[s[j] - 'a']++;

            int maxFreq = 0, minFreq = INT_MAX;
            for (int k = 0; k < 26; ++k) {
                if (freq[k] > 0) {
                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }
            ans += (maxFreq - minFreq);
        }
    }
    return ans;
}

int main() {
    vector<string> test_cases = {
        "aabcb",      // Expected: 5
        "aabcbaa",    // Expected: 17
        "aaaa",       // Expected: 0 (all substrings have equal frequency)
        "abc",        // Expected: 0 (no repeated characters)
        "zzzzzz",     // Expected: 0 (same character only)
        "abac",       // Expected: 3
    };

    for (string s : test_cases) {
        cout << "Input: \"" << s << "\" => Beauty Sum: " << beautySum(s) << endl;
    }

    return 0;
}
