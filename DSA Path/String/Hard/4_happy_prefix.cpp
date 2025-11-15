#include <bits/stdc++.h>
using namespace std;

// KMP LPS (Longest Prefix Suffix) array builder
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

// Function to get longest prefix which is also a suffix
string longestPrefix(const string &s) {
    vector<int> lps = computeLPS(s);
    int prefixLen = lps.back(); // lps[n-1] gives longest prefix == suffix
    return s.substr(0, prefixLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> testcases = {
        "ababab",
        "abacabad",
        "aaaa",
        "abc",
        "abababa",
        "a",
        ""
    };

    for (auto &test : testcases) {
        cout << "String: " << (test.empty() ? "\"\"" : test) << "\n";
        cout << "Longest Prefix = Suffix: \"" << longestPrefix(test) << "\"\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
