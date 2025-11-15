#include <bits/stdc++.h>
using namespace std;

/*
Coin Change I - Minimum number of coins to make amount
*/
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return dp[amount] == 1e9 ? -1 : dp[amount];
}

int main() {
    vector<int> coins;
    int amount;

    // Testcase 1
    coins = {1, 2, 5};
    amount = 11;
    cout << "TC1: " << coinChange(coins, amount) << endl; 
    // Expected: 3 (11 = 5+5+1)

    // Testcase 2
    coins = {2};
    amount = 3;
    cout << "TC2: " << coinChange(coins, amount) << endl; 
    // Expected: -1

    // Testcase 3
    coins = {1};
    amount = 0;
    cout << "TC3: " << coinChange(coins, amount) << endl; 
    // Expected: 0

    // Testcase 4
    coins = {1};
    amount = 2;
    cout << "TC4: " << coinChange(coins, amount) << endl; 
    // Expected: 2
}
