#include <bits/stdc++.h>
using namespace std;

// Comparator function for sorting by length
bool cmp(const string &a, const string &b){
    return a.size() < b.size();
}

// Function to check if s2 can be predecessor of s1
bool compare(const string &s1, const string &s2){
    if(s1.size() != s2.size() + 1) return false;
    int i = 0, j = 0;
    while(i < s1.size()){
        if(j < s2.size() && s1[i] == s2[j]){
            i++; j++;
        } else i++;
    }
    return j == s2.size();
}

// Function to find the length of the longest string chain
int longestStrChain(vector<string>& words) {
    int n = words.size();
    // Sort words by length using cmp
    sort(words.begin(), words.end(), cmp);

    vector<int> dp(n,1); // dp[i] = longest chain ending at i
    int ans = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(compare(words[i], words[j]) && dp[i] < 1 + dp[j]){
                dp[i] = 1 + dp[j];
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    vector<vector<string>> testCases = {
        {"a","b","ba","bca","bda","bdca"},    // Expected: 4
        {"xbc","pcxbcf","xb","cxbc","pcxbc"}, // Expected: 5
        {"abcd","dbqca"},                     // Expected: 1
        {"a","ab","ac","bd","abc","abd","abdd"} // Expected: 4
    };

    for(auto words : testCases){
        cout << "Words: ";
        for(auto &w : words) cout << w << " ";
        cout << "\nLongest String Chain Length: " << longestStrChain(words) << "\n";
        cout << "-------------------------------------\n";
    }

    return 0;
}
