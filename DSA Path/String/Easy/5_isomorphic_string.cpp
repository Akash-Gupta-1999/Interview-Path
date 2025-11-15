#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char,char> umap_sc, umap_tc;
    int i = 0;
    while(i < s.size()) {
        if(umap_sc.find(s[i]) != umap_sc.end() && umap_sc[s[i]] != t[i])
            return false;
        else if(umap_tc.find(t[i]) != umap_tc.end() && umap_tc[t[i]] != s[i])
            return false;
        else {
            umap_sc[s[i]] = t[i];
            umap_tc[t[i]] = s[i];
            i++;
        }
    }
    return true;
}

int main() {
    vector<pair<string, string>> testCases = {
        {"egg", "add"},
        {"foo", "bar"},
        {"paper", "title"},
        {"badc", "baba"},
        {"abc", "def"},
        {"ab", "aa"},
        {"aab", "xxy"},
        {"aab", "xyz"}
    };

    for(auto& [s, t] : testCases) {
        cout << "isIsomorphic(\"" << s << "\", \"" << t << "\") = ";
        cout << (isIsomorphic(s, t) ? "true" : "false") << endl;
    }

    return 0;
}
