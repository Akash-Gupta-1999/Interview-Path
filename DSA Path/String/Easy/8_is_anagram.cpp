#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;
    
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); i++) {
        umap[s[i]]++;
    }
    
    for (int i = 0; i < t.size(); i++) {
        if (umap[t[i]] == 0)
            return false;
        umap[t[i]]--;
    }
    
    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t)) {
        cout << "'" << s << "' and '" << t << "' are anagrams." << endl;
    } else {
        cout << "'" << s << "' and '" << t << "' are not anagrams." << endl;
    }

    return 0;
}
