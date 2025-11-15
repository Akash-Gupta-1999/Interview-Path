#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    int left = 0, maxFreq = 0, ans = 0;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // shrink if more than k replacements needed
        if ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main() {
    cout << "Test1: " << characterReplacement("ABAB", 2) << "\n";     // expected 4
    cout << "Test2: " << characterReplacement("AABABBA", 1) << "\n"; // expected 4
    cout << "Test3: " << characterReplacement("AAAA", 2) << "\n";    // expected 4
    cout << "Test4: " << characterReplacement("ABCDE", 1) << "\n";   // expected 2
    cout << "Test5: " << characterReplacement("BAAAB", 2) << "\n";   // expected 5
    return 0;
}
