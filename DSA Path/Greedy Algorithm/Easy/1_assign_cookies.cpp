#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- Sort both greed factors and cookie sizes.
- Always assign the smallest possible cookie that satisfies the current child.
- Greedy ensures maximum children satisfied.
*/
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0; // i -> children, j -> cookies
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            // cookie satisfies child
            i++;
            j++;
        } else {
            // cookie too small, try bigger one
            j++;
        }
    }
    return i; // number of satisfied children
}

int main() {
    vector<int> g, s;

    // Testcase 1
    g = {1,2,3};
    s = {1,1};
    cout << "TC1: " << findContentChildren(g, s) << endl; 
    // Expected: 1 (only one child can be satisfied)

    // Testcase 2
    g = {1,2};
    s = {1,2,3};
    cout << "TC2: " << findContentChildren(g, s) << endl; 
    // Expected: 2 (both satisfied)

    // Testcase 3
    g = {2,3,4};
    s = {1,1,2};
    cout << "TC3: " << findContentChildren(g, s) << endl; 
    // Expected: 1 (only child with greed 2 gets satisfied)

    // Testcase 4
    g = {1,2,3};
    s = {3};
    cout << "TC4: " << findContentChildren(g, s) << endl; 
    // Expected: 1 (largest child with greed ≤3 is satisfied)

    // Testcase 5
    g = {5,6,7};
    s = {1,2,3};
    cout << "TC5: " << findContentChildren(g, s) << endl; 
    // Expected: 0 (no child can be satisfied)
}
