#include<bits/stdc++.h>
using namespace std;

int knapsack_rec(vector<int> profit,vector<int> weight,int n,int w){
    if(n == 0 || w == 0)
        return 0;
    if(weight[n-1] > w)
        knapsack_rec(profit,weight,n-1,w);
    else
        return max(profit[n-1]+knapsack_rec(profit,weight,n,w-weight[n-1]),knapsack_rec(profit,weight,n-1,w));
}

int knapsack_mem(vector<int> profit,vector<int> weight,int n,int w,vector<vector<int>> dp){
    if(n == 0 || w == 0)
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    if(weight[n-1] > w){
        dp[n-1][w] = knapsack_mem(profit,weight,n-1,w,dp);
        return dp[n-1][w];
    }
    else{
        dp[n-1][w] = max(profit[n-1]+knapsack_rec(profit,weight,n,w-weight[n-1]),knapsack_rec(profit,weight,n-1,w));
        return dp[n-1][w];
    }
}

int knapsack_top_down(vector<int> profit,vector<int> weight,int n,int w,vector<vector<int>> dp){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weight[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(profit[i-1]+dp[i][j - weight[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][w];
}

int knapsack_top_down_dpd(vector<int> profit,vector<int> weight,int n,int w,vector<int> dpd){
    for(int i = 1;i<n+1;i++){
        for(int j = 0;j<w+1;j++){
            if(weight[i-1] <= j){
                dpd[j] = max(profit[i-1]+dpd[j - weight[i-1]],dpd[j]);
            }
        }
    }
    return dpd[w];
}

int main(){
    int n = 3;
    vector<int> profit = {60,100,120};
    vector<int> weight = {10,20,30};
    int w = 50;
    cout<<knapsack_rec(profit,weight,n,w)<<endl;
    vector<vector<int>> dp(n+1,vector<int> (w+1,-1));
    cout<<knapsack_mem(profit,weight,n,w,dp)<<endl;
    cout<<knapsack_top_down(profit,weight,n,w,dp)<<endl;
    vector<int>dpd(w+1,0);
    cout<<knapsack_top_down_dpd(profit,weight,n,w,dpd)<<endl;
}