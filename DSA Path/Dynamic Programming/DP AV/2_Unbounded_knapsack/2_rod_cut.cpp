#include<bits/stdc++.h>
using namespace std;

int unbounded_knapsack(vector<int> p,int n,int size,vector<vector<int>>& dp){
    if(n == 0 || size == 0){
        return 0;
    }
    if(dp[n][size] != -1)
        return dp[n][size];
    if(n <= size){
        dp[n][size] = max(p[n-1]+ unbounded_knapsack(p,n,size-n,dp),unbounded_knapsack(p,n-1,size,dp));
        return dp[n][size];
    }
    else{
        dp[n][size] = unbounded_knapsack(p,n-1,size,dp);
        return dp[n][size];
    }
}

int top_bottom(vector<int> p,int n,vector<vector<int>>& dp){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(i<=j)
                dp[i][j] = max(p[i-1]+dp[i][j-i],dp[i-1][j]);
            else    
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][n];
}

int top_bottom_dpd(vector<int> p,int n,vector<int>& dp){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i<=j)
                dp[j] = max(p[i-1]+dp[j-i],dp[j]);
        }
    }
    return dp[n];
}

int main(){
    vector<int> profit = {1,5,8,9,10,17,17,20};
    int n = profit.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<unbounded_knapsack(profit,n,n,dp)<<endl;
    cout<<top_bottom(profit,n,dp)<<endl;
    vector<int>dpd(n+1,0);
    cout<<top_bottom_dpd(profit,n,dpd)<<endl;
}