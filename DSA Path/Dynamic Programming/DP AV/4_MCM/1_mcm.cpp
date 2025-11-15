#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> arr,int i,int j){
    if(i==j)
        return 0;
    int mini = INT_MAX;
    int temp;
    for(int k=i;k<=j-1;k++){
        temp = mcm(arr,i,k) + mcm(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]);
        mini = min(mini,temp);
    }
    return mini;   
}

int mcm_mem(vector<int> arr,int i,int j,vector<vector<int>>& dp){
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini = INT_MAX;
    int temp;
    for(int k=i;k<=j-1;k++){
        temp = mcm(arr,i,k) + mcm(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]);
        mini = min(mini,temp);
    }
    dp[i][j] = mini;
    return dp[i][j];
}

int top_bottom(vector<int> arr,vector<vector<int>> dp,int n){
    for(int i=1;i<n;i++)
        dp[i][i] = 0;
    for(int i=n-1;i>=1;i--){
        for(int j = i+1;j<n;j++){
            int mini = INT_MAX;
            int temp;
            for(int k = i;k<=j-1;k++){
                dp[i][j] = + (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                mini = min(mini,dp[i][j]);
                dp[i][j] = mini;
            }    
        }
    }
    return dp[1][n-1];
}

int main(){
    vector<int> arr = {40,20,30,10,30};
    cout<<mcm(arr,1,arr.size()-1)<<endl;
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<mcm_mem(arr,1,arr.size()-1,dp)<<endl;
    cout<<top_bottom(arr,dp,n);
}