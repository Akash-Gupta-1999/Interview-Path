#include <bits/stdc++.h>
using namespace std;

// Function to compute LPS (Longest Prefix Suffix) array for KMP
vector<int> computeLPS(const string &s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len == 0) {
                lps[i] = 0;
                i++;
            } 
            else {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

// Function to form the shortest palindrome by adding characters in front
string shortestPalindrome(string s) {
    int n = s.size();
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    // Construct pattern for KMP: s + '#' + reverse(s)
    string pattern = s + '#' + s_rev;
    vector<int> lps = computeLPS(pattern);

    int matched = lps.back(); // Length of longest palindromic prefix
    return s_rev.substr(0, n - matched) + s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> testcases = {
        "aacecaaa",
        "abcd",
        "baab",
        "race",
        "aa",
        "a",
        ""
    };

    for (auto &test : testcases) {
        cout << "Original: " << (test.empty() ? "\"\"" : test) << "\n";
        cout << "Shortest Palindrome: " << shortestPalindrome(test) << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
