#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> need, window;
    for(char c : t) need[c]++;

    int have = 0, needCount = need.size();
    int left = 0, min_size = INT_MAX, start = 0;

    for(int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        // If this char is needed and freq is satisfied
        if(need.count(c) && window[c] == need[c]) {
            have++;
        }

        // When window contains all chars
        while(have == needCount) {
            // Update best answer
            if(right - left + 1 < min_size) {
                min_size = right - left + 1;
                start = left;
            }

            // Pop from left
            window[s[left]]--;
            if(need.count(s[left]) && window[s[left]] < need[s[left]]) {
                have--;
            }
            left++;
        }
    }
    return (min_size == INT_MAX) ? "" : s.substr(start, min_size);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << " (Expected BANC)\n";
    cout << minWindow("a", "a") << " (Expected a)\n";
    cout << minWindow("a", "aa") << " (Expected '')\n";
}
