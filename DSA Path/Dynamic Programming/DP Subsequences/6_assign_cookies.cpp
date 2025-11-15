#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    // g = greed factor of each child
    // s = size of each cookie

    sort(g.begin(), g.end()); // sort children by greed
    sort(s.begin(), s.end()); // sort cookies by size

    int i = 0; // pointer for children
    int j = 0; // pointer for cookies
    int ans = 0;

    // Greedily assign smallest possible cookie to each child
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            // current cookie can satisfy current child
            ans++;
            i++; // move to next child
        }
        // move to next cookie in either case
        j++;
    }

    return ans; // maximum number of content children
}

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << findContentChildren(g, s) << endl; // Output: 1

    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << findContentChildren(g2, s2) << endl; // Output: 2
}
