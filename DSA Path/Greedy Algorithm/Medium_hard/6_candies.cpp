#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1); // Step 1: everyone gets 1

    // Step 2: Left -> Right pass
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 3: Right -> Left pass with sum calculation
    int sum = candies[n - 1];  // start from last element
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        sum += candies[i];
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
