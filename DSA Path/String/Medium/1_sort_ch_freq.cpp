#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> umap;
    priority_queue<pair<int, char>> pq;

    // Count frequency of each character
    for (int i = 0; i < s.length(); i++)
        umap[s[i]]++;

    // Push into max heap by frequency
    for (auto it : umap)
        pq.push(make_pair(it.second, it.first));

    string ans = "";
    // Build the answer string
    while (!pq.empty()) {
        pair<int, char> var = pq.top();
        pq.pop();

        char ch = var.second;
        int freq = var.first;

        while (freq--) {
            ans += ch;
        }
    }

    return ans;
}

int main() {
    vector<string> testCases = {
        "tree",
        "cccaaa",
        "Aabb",
        "abcabc",
        "",
        "zzZZzz"
    };

    for (string test : testCases) {
        string result = frequencySort(test);
        cout << "Input: " << test << "::: Output: " << result<<"\n";
    }

    return 0;
}
