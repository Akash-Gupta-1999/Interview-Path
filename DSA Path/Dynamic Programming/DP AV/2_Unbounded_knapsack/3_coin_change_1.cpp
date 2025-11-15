#include<bits/stdc++.h>
using namespace std;

int coin_change(vector<int> arr,int n,int s,vector<vector<int>>& dp){
    if(s == 0)
        return 0;
    if(n==0)
        return INT_MAX - 1;
    if(dp[n][s]!=-1)
        return dp[n][s];
    if(arr[n-1]<=s){
        dp[n][s] = min(1+coin_change(arr,n,s-arr[n-1],dp),coin_change(arr,n-1,s,dp));
        return dp[n][s];
    }
    else{
        dp[n][s] = coin_change(arr,n-1,s,dp);
        return dp[n][s];
    }
}

int top_bottom(vector<int> arr,int n,int s,vector<vector<int>>& dp){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s+1;j++){
            if(j == 0)
                dp[i][j] = 0;
            else if(i == 0)
                dp[i][j] = INT_MAX-1;
            else if(arr[i-1]<=j)
                dp[i][j] = min(1+dp[i][j-arr[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][s];
}

int top_bottom_dpd(vector<int> arr,int n,int s,vector<int>& dp){
    for(int i=0;i<n+1;i++)
        for(int j=0;j<s+1;j++){
            if(j==0)
                dp[j] = 0;
            else if(i==0)
                dp[j] = INT_MAX-1;
            else if(arr[i-1]<=j)
                dp[j] = min(1+dp[j-arr[i-1]],dp[j]);
        }
    return dp[s];
}

int main(){
    vector<int> arr = {186,419,83,408};
    int s = 6249;
    int n = arr.size();
    int ans = 0;
    vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
    cout<<coin_change(arr,n,s,dp)<<endl;
    cout<<top_bottom(arr,n,s,dp)<<endl;
    vector<int> dpd(s+1,0);
    cout<<top_bottom_dpd(arr,n,s,dpd)<<endl;
}