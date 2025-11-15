#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans = strs[0];
    int i = 1;
    while(i < strs.size()) {
        int j = 0;
        while(j < ans.size() && ans[j] == strs[i][j])
            j++;
        ans = strs[i].substr(0, j);
        i++;
    }
    return ans;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    // Additional test case
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs2) << endl;

    return 0;
}
