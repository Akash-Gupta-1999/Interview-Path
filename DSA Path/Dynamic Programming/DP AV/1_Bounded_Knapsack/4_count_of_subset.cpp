#include<bits/stdc++.h>
using namespace std;

int subset_sum(vector<int> set,int n,int sum,vector<vector<int>>& dp){
    if(sum == 0){
        return 1;
    }
    if(n == 0)
        return 0;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    else{
        if(set[n-1] <= sum){
            dp[n][sum] = subset_sum(set,n-1,sum-set[n-1],dp) + subset_sum(set,n-1,sum,dp);
            return dp[n][sum];
        }
        else{
            dp[n][sum] = subset_sum(set,n-1,sum,dp);
            return dp[n][sum];
        }
    }
}

int top_bottom(vector<int> set,int n,int sum,vector<vector<int>>& dp){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else if(set[i-1] <= j){
                dp[i][j] = dp[i-1][j-set[i-1]] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int top_bottom_dpd(vector<int> set,int n,int sum,vector<int>& dpd){
    dpd[0] = 1;
    for(int i = 1;i<n+1;i++){
        for(int j = sum;j>=0;j--){
            if(set[i-1] <= j){
                dpd[j] = dpd[j-set[i-1]] + dpd[j]; 
            }
        }
    }
    return dpd[sum];
}

int main(){
    vector<int> set = {1,2,3,3};
    int n = 4;
    int sum = 6;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    cout<<subset_sum(set,n,sum,dp)<<endl;
    cout<<top_bottom(set,n,sum,dp)<<endl;
    vector<int> dpd(sum+1,0);
    cout<<top_bottom_dpd(set,n,sum,dpd)<<endl;
}