#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------
// 🧠 Intuition:
// We want to find the max profit from a single buy-sell.
// Keep track of the minimum price so far (best buying price)
// and calculate the profit if we sold today.
// Keep updating the max profit.
// -----------------------------------------------------------
int maximumProfit(vector<int> &Arr) {
    int maxProfit = 0;
    int mini = Arr[0];  // Minimum price so far

    for (int i = 1; i < Arr.size(); i++) {
        int curProfit = Arr[i] - mini;         // Profit if sold today
        maxProfit = max(maxProfit, curProfit); // Update max profit
        mini = min(mini, Arr[i]);              // Update minimum price
    }

    return maxProfit;
}

// -----------------------------------------------------------
// 🔍 Driver code with multiple test cases
// -----------------------------------------------------------
int main() {
    vector<vector<int>> testCases = {
        {7, 1, 5, 3, 6, 4},   // Expected: 5
        {7, 6, 4, 3, 1},      // Expected: 0 (no profit possible)
        {2, 4, 1},            // Expected: 2
        {3, 3, 5, 0, 0, 3, 1, 4}, // Expected: 4
        {1},                  // Expected: 0
    };

    for (auto &Arr : testCases) {
        cout << "Prices: ";
        for (int price : Arr) cout << price << " ";
        cout << "\nMaximum Profit: " << maximumProfit(Arr);
        cout << "\n-----------------------------\n";
    }

    return 0;
}
