#include<bits/stdc++.h>
using namespace std;

bool target_sum(vector<int> arr,int n,int sum,vector<vector<int>>& dp,int temp){
    if(n == 0){
        if(sum == temp)
            return 1;
        else
            return 0;
    }
    if(dp[n][temp] != -1)
        return dp[n][temp];
    if(arr[n-1] <= temp){
        dp[n][temp] = target_sum(arr,n-1,sum,dp,temp+arr[n-1]) || target_sum(arr,n-1,sum,dp,temp-arr[n-1]);
        return dp[n][temp];
    }
    else{
        dp[n][temp] = target_sum(arr,n-1,sum,dp,temp+arr[n-1]);
        return dp[n][temp];
    }
}

bool top_bottom(vector<int> set,int n,int sum,vector<vector<int>>& dp){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else if(set[i-1] <= j){
                dp[i][j] = dp[i-1][j-set[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

bool top_bottom_dpd(vector<int> set,int n,int sum,vector<int>& dpd){
    dpd[0] = 1;
    for(int i = 1;i<n+1;i++){
        for(int j = sum;j>=0;j--){
            if(set[i-1] <= j){
                dpd[j] = dpd[j-set[i-1]] || dpd[j]; 
            }
        }
    }
    return dpd[sum];
}

int main(){
    vector<int> arr = {1,1,1,3,1};
    int n = 5,sum = 2;
    int cum_sum = 0;
    for(int i=0;i<n;i++)
        cum_sum+=arr[i];
    if(sum>cum_sum || (cum_sum-sum)%2!=0){
        cout<<0<<endl;
        return 0;
    }
    int temp = (cum_sum - sum)/2;
    vector<vector<int>> dp(n+1,vector<int>(temp+1,-1)); 
    vector<int> dpd(temp+1,0);
    cout<<boolalpha<<top_bottom(arr,n,temp,dp)<<endl;
    cout<<boolalpha<<top_bottom_dpd(arr,n,temp,dpd)<<endl;
    vector<vector<int>>dpt(n+1,vector<int>(cum_sum+1,-1));
    cout<<boolalpha<<target_sum(arr,n,sum,dpt,0)<<endl;
}