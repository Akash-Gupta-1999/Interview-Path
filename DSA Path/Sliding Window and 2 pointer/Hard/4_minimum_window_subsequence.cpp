#include <bits/stdc++.h>
using namespace std;

string minWindowSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    int min_len = INT_MAX, start = -1;
    int i = 0;

    while (i < n) {
        int j = 0;

        // ---------------------------
        // 1) Forward pass: try to find a subsequence of t inside s
        // Move 'i' forward until we can match the whole string t
        // ---------------------------
        while (i < n) {
            if (s[i] == t[j]) j++;      // match current char of t
            if (j == m) break;          // found all of t in order
            i++;
        }
        if (j < m) break;               // no more subsequence possible

        // ---------------------------
        // 2) Backward pass: shrink the window
        // Now we know s[..i] contains t as subsequence ending at i
        // Move 'i' backward to find the smallest window that still contains t
        // ---------------------------
        int end = i;                    // subsequence ends at position 'end'
        j = m - 1;                      // match t backwards
        while (i >= 0) {
            if (s[i] == t[j]) j--;      // match characters backward
            if (j < 0) break;           // all chars of t matched
            i--;
        }

        // ---------------------------
        // 3) Update minimum window
        // At this point 'i' is at the leftmost position of a valid window
        // Window is [i .. end]
        // ---------------------------
        if (end - i + 1 < min_len) {
            min_len = end - i + 1;
            start = i;
        }

        // ---------------------------
        // 4) Continue searching
        // Next subsequence must start after 'i'
        // ---------------------------
        i = i + 1;
    }

    // Return the smallest subsequence window found
    return (start == -1) ? "" : s.substr(start, min_len);
}

int main() {
    cout << minWindowSubsequence("abcdebdde", "bde") << " (Expected: bcde)" << endl;
    cout << minWindowSubsequence("jmeqksfrsdcmsiwvaovztaqenprpvnbstl", "u") << " (Expected: '')" << endl;
    cout << minWindowSubsequence("abcdebdde", "dde") << " (Expected: dde)" << endl;
    cout << minWindowSubsequence("abcdebdde", "ace") << " (Expected: abcde)" << endl;
    return 0;
}
