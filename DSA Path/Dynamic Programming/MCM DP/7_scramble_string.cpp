#include <bits/stdc++.h>
using namespace std;

/*
Problem: Scramble String
------------------------
We are given two strings s1 and s2 of the same length.
We need to determine if s2 is a scrambled string of s1.

A scrambled string can be formed by recursively partitioning a string into two
non-empty substrings and swapping them any number of times.

Example:
s1 = "great", s2 = "rgeat" → true
s1 = "abcde", s2 = "caebd" → false
*/

/* -------------------------------------------------------------------------- */
/*                          🔹 TOP-DOWN (Memoization)                         */
/* -------------------------------------------------------------------------- */

bool isScrambleMemo(string s1, string s2, unordered_map<string, bool>& mp) {
    if (s1 == s2)
        return true;

    if (s1.size() != s2.size())
        return false;

    string key = s1 + " " + s2;
    if (mp.find(key) != mp.end())
        return mp[key];

    // Optional pruning to speed up
    string c1 = s1, c2 = s2;
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    if (c1 != c2)
        return mp[key] = false;

    int n = s1.size();
    for (int i = 1; i < n; i++) {
        // Case 1: No swap
        if (isScrambleMemo(s1.substr(0, i), s2.substr(0, i), mp) &&
            isScrambleMemo(s1.substr(i), s2.substr(i), mp))
            return mp[key] = true;

        // Case 2: Swap
        if (isScrambleMemo(s1.substr(0, i), s2.substr(n - i), mp) &&
            isScrambleMemo(s1.substr(i), s2.substr(0, n - i), mp))
            return mp[key] = true;
    }

    return mp[key] = false;
}

/* -------------------------------------------------------------------------- */
/*                                   MAIN                                    */
/* -------------------------------------------------------------------------- */

int main() {
    vector<pair<string, string>> testCases = {
        {"great", "rgeat"},   // true
        {"abcde", "caebd"},   // false
        {"a", "a"},           // true
        {"abc", "bca"},       // true
        {"abc", "def"}        // false
    };

    for (auto& [s1, s2] : testCases) {
        unordered_map<string, bool> mp;
        cout << s1 << " & " << s2 << " -> " 
             << boolalpha << isScrambleMemo(s1, s2, mp) << "\n";
    }

    return 0;
}
