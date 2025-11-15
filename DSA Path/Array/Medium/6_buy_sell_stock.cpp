#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy_idx = 0, max_profit = 0;
    for(int i=0;i<prices.size();i++){
        int profit = prices[i] - prices[buy_idx];
        if(profit<0)
            buy_idx = i;
        max_profit=max(max_profit,profit);
    }
    return max_profit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}