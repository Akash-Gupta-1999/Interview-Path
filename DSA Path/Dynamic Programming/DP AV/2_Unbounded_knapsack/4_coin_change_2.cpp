#include<bits/stdc++.h>
using namespace std;

int top_bottom(vector<int> coins,int n,int s,vector<vector<int>>& dp){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(j == 0)
                dp[i][j] = 1;
            else if(i == 0)
               dp[i][j] = 0;
            else if(coins[i-1]<=j)
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][s];
}

int coin_change(vector<int> coins,int n,int s,vector<vector<int>>& dp){
    if(s == 0)
        return 1;
    if(n == 0)
        return 0;
    if(dp[n][s] != -1)
        return dp[n][s];
    if(coins[n-1]<=s){
        dp[n][s] = coin_change(coins,n,s-coins[n-1],dp) + coin_change(coins,n-1,s,dp);
        return dp[n][s];
    }
    dp[n][s] = coin_change(coins,n-1,s,dp);
    return dp[n][s];
}

int top_bottom_dpd(vector<int> coins,int n,int s,vector<int>& dp){
    for(int i = 0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(j == 0)
                dp[j] = 1;
            else if(i == 0)
                dp[j] = 0;
            else if(coins[i-1]<=j)
                dp[j] = dp[j-coins[i-1]] + dp[j];
        }
    }
    return dp[s];
}

int main(){
    vector<int> coins = {1,2,5};
    int s = 5;
    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
    cout<<top_bottom(coins,n,s,dp)<<endl;
    cout<<coin_change(coins,n,s,dp)<<endl;
    vector<int> dpd(s+1,0);
    cout<<top_bottom_dpd(coins,n,s,dpd)<<endl;
}