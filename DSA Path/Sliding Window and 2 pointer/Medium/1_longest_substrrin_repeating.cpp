#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int left = 0, ans = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (lastSeen.find(s[i]) != lastSeen.end() && lastSeen[s[i]] >= left) {
            left = lastSeen[s[i]] + 1;  // move left past duplicate
        }
        lastSeen[s[i]] = i;             // update last seen index
        ans = max(ans, i - left + 1);   // current window size
    }

    return ans;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << "\n"; // 3 ("abc")
    cout << lengthOfLongestSubstring("bbbbb") << "\n";    // 1 ("b")
    cout << lengthOfLongestSubstring("pwwkew") << "\n";   // 3 ("wke")
    cout << lengthOfLongestSubstring("") << "\n";         // 0 (empty string)
    cout << lengthOfLongestSubstring("au") << "\n";       // 2 ("au")
    cout << lengthOfLongestSubstring("dvdf") << "\n";     // 3 ("vdf")
    return 0;
}
