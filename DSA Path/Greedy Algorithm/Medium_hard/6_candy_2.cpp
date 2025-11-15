#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    int sum = 1;   // at least 1 candy for first child
    int i = 1;

    while (i < n) {
        // Case 1: Equal ratings → give 1 candy and move on
        if (ratings[i] == ratings[i - 1]) {
            sum += 1;
            i++;
            continue;
        }

        // Case 2: Increasing slope
        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1]) {
            peak++;
            sum += peak;
            i++;
        }

        // Case 3: Decreasing slope
        int down = 1;
        while (i < n && ratings[i] < ratings[i - 1]) {
            sum += down;
            down++;
            i++;
        }

        // Fix for peak vs. down slope imbalance
        if (down > peak)
            sum += (down - peak);
    }
    return sum;
}

int main() {
    vector<int> r1 = {1, 0, 2};
    cout << candy(r1) << endl; // ✅ Expected: 5

    vector<int> r2 = {1, 2, 2};
    cout << candy(r2) << endl; // ✅ Expected: 4

    vector<int> r3 = {1, 3, 4, 5, 2};
    cout << candy(r3) << endl; // ✅ Expected: 11

    vector<int> r4 = {1, 2, 87, 87, 87, 2, 1};
    cout << candy(r4) << endl; // ✅ Expected: 13

    return 0;
}
