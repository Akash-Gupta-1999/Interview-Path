#include <bits/stdc++.h>
using namespace std;

// Function to compute prev and next maps
void computePrevNext(const string &s, unordered_map<char,int> &prevMap, unordered_map<char,int> &nextMap) {
    int n = s.size();
    unordered_map<char,int> last;

    // Compute next occurrences
    for(int i=n-1;i>=0;i--){
        if(last.count(s[i])) nextMap[s[i]] = last[s[i]];
        else nextMap[s[i]] = n; // no next occurrence
        last[s[i]] = i;
    }

    last.clear();
    // Compute prev occurrences
    for(int i=0;i<n;i++){
        if(last.count(s[i])) prevMap[s[i]] = last[s[i]];
        else prevMap[s[i]] = -1; // no previous occurrence
        last[s[i]] = i;
    }
}

// Recursion + Memoization
int countPSRec(string &s, int i, int j, vector<vector<int>> &dp, unordered_map<char, int> &prev, unordered_map<char, int> &next) {
    if(i > j) return 0;
    if(i == j) return 1; // single char palindrome
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] != s[j]) {
        dp[i][j] = countPSRec(s, i+1, j, dp, prev, next) + countPSRec(s, i, j-1, dp, prev, next) - countPSRec(s, i+1, j-1, dp, prev, next);
    } else {
        int l = next[s[i]]; // first occurrence after i
        int r = prev[s[j]]; // last occurrence before j
        if(l > r) dp[i][j] = 2*countPSRec(s, i+1, j-1, dp, prev, next) + 2;
        else if(l == r) dp[i][j] = 2*countPSRec(s, i+1, j-1, dp, prev, next) + 1;
        else dp[i][j] = 2*countPSRec(s, i+1, j-1, dp, prev, next) - countPSRec(s, l+1, r-1, dp, prev, next);
    }
    return dp[i][j];
}

// Tabulation
int countPSTab(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    vector<int> prev(n,-1), next(n,-1);
    unordered_map<char,int> mp;

    // Compute prev array
    for(int i=0;i<n;i++){
        if(mp.count(s[i])) prev[i] = mp[s[i]];
        mp[s[i]] = i;
    }

    mp.clear();
    // Compute next array
    for(int i=n-1;i>=0;i--){
        if(mp.count(s[i])) next[i] = mp[s[i]];
        mp[s[i]] = i;
    }

    for(int len=1; len<=n; len++){
        for(int i=0; i+len-1<n; i++){
            int j = i+len-1;
            if(i==j) dp[i][j] = 1;
            else if(s[i]!=s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            else {
                int l = next[i];
                int r = prev[j];
                if(l > r) dp[i][j] = 2*dp[i+1][j-1] + 2;
                else if(l == r) dp[i][j] = 2*dp[i+1][j-1] + 1;
                else dp[i][j] = 2*dp[i+1][j-1] - dp[l+1][r-1];
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    unordered_map<char,int> prevMap, nextMap;
    computePrevNext(s, prevMap, nextMap); // Keep main clean

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));

    int countRecMem = countPSRec(s, 0, n-1, dp, prevMap, nextMap);
    int countTab = countPSTab(s);

    cout << "Count of unique palindromic subsequences (Rec+Memo): " << countRecMem << endl;
    cout << "Count of unique palindromic subsequences (Tabulation): " << countTab << endl;

    return 0;
}
