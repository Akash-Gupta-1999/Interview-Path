#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;

    map<int,int> freq; // ordered map
    for (int card : hand) freq[card]++;

    for (auto& [card, count] : freq) {
        if (count > 0) {
            for (int i = 1; i < groupSize; i++) {
                if (freq[card + i] < count) return false;
                freq[card + i] -= count;
            }
        }
    }
    return true;
}

int main() {
    vector<pair<vector<int>, int>> testcases = {
        {{1,2,3,6,2,3,4,7,8}, 3},   // true
        {{1,2,3,4,5}, 4},          // false
        {{1,2,3,4}, 2},            // true
        {{2,3,1,2,3,1,2,3,1}, 3},  // true
    };

    for (int i = 0; i < testcases.size(); i++) {
        auto [hand, k] = testcases[i];
        cout << "Testcase " << i+1 << ": "
             << (isNStraightHand(hand, k) ? "true" : "false") << "\n";
    }
}
