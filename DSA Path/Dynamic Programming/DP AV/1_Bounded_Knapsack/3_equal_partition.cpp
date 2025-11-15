#include<bits/stdc++.h>
using namespace std;

bool equal_partition(vector<int> arr,int n,vector<vector<int>>& dp,int sum){
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    if(arr[n-1] > sum){
        dp[n][sum] = equal_partition(arr,n-1,dp,sum);
        return dp[n][sum];
    }
    else{
        dp[n][sum] = equal_partition(arr,n-1,dp,sum-arr[n-1]) || equal_partition(arr,n-1,dp,sum);
        return dp[n][sum];
    }
}

bool equal_partition_top_down(vector<int> arr,int n,vector<vector<int>>& dp,int sum){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j == 0)
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

bool equal_partition_top_down_dpd(vector<int> arr,int n,vector<int>& dpd,int sum){
    dpd[0] = 1;
    for(int i=0;i<n+1;i++)
        for(int j = sum;j>=0;j--){
            if(arr[i-1] <= j)
                dpd[j] = dpd[j-arr[i-1]] || dpd[j];
        }
    return dpd[sum];
}

int main(){
    vector<int> arr = {1,5,5,11};
    int n = 4;
    int sum=0;
    for(int i = 0;i<n;i++)
        sum+=arr[i];
    if(sum%2 != 0){
        cout<<boolalpha<<false<<endl;
    }
    else{
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        vector<int> dpd(sum+1,0);
        cout<<boolalpha<<equal_partition(arr,n,dp,sum)<<endl;
        cout<<boolalpha<<equal_partition_top_down(arr,n,dp,sum)<<endl;
        cout<<boolalpha<<equal_partition_top_down_dpd(arr,n,dpd,sum)<<endl;
    }
}