#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    int num = start ^ goal;
    int ans = 0;
    while (num > 0) {
        ans++;
        num = num & (num - 1); // remove lowest set bit
    }
    return ans;
}

int main() {
    // Testcases
    vector<pair<int,int>> tests = {
        {10, 7},     // 1010 -> 0111 (3 flips)
        {3, 4},      // 0011 -> 0100 (3 flips)
        {7, 7},      // same numbers (0 flips)
        {0, 15},     // 0000 -> 1111 (4 flips)
        {29, 15}     // 11101 -> 01111 (2 flips)
    };

    for (auto &t : tests) {
        cout << "minBitFlips(" << t.first << ", " << t.second << ") = "
             << minBitFlips(t.first, t.second) << "\n";
    }

    return 0;
}
