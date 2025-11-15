#include<bits/stdc++.h>
using namespace std;

int no_subset_given_diff(vector<int >arr,int n,int cum_sum,int d,vector<vector<int>>& dp,int sum){
    if(n == 0){
        if(abs((cum_sum - sum) - sum) == d)
            return 1;
        else
            return 0;
    }
    if(dp[n][sum] != -1)
        return dp[n][sum];
    dp[n][sum] = no_subset_given_diff(arr,n-1,cum_sum,d,dp,sum+arr[n-1]) + no_subset_given_diff(arr,n-1,cum_sum,d,dp,sum);
    return dp[n][sum];
}

int subset_sum(vector<int> set,int n,int sum,vector<vector<int>>& dp){
    if(sum == 0)
        return 1;
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
    vector<int> arr = {1,2,3,1,2};
    int n= 5, d = 1;
    int cum_sum = 0;
    for(int i=0;i<n;i++)
        cum_sum+=arr[i];
    if(d > cum_sum || (cum_sum - d)%2 != 0)
        return 0;
    int temp=cum_sum;
    cum_sum = (cum_sum - d)/2;
    vector<vector<int>> dp(n+1,vector<int>(cum_sum+1,-1)); 
    vector<int> dpd(cum_sum+1,0);
    vector<vector<int>> dpt(n+1,vector<int>(temp+1,-1)); 
    cout<<subset_sum(arr,n,cum_sum,dp)<<endl;
    cout<<no_subset_given_diff(arr,n,temp,d,dpt,0)/2<<endl;
    cout<<top_bottom(arr,n,cum_sum,dp)<<endl;
    cout<<top_bottom_dpd(arr,n,cum_sum,dpd)<<endl;
}