#include<bits/stdc++.h>
using namespace std;

int minimum_subset_diff(vector<int> arr,int n,int cum_sum,vector<vector<int>>& dp,int second_sum){
    if(n == 0){
        return abs((cum_sum-second_sum)-second_sum);
    }
    if(dp[n][second_sum] != -1)
        return dp[n][second_sum];
    dp[n][second_sum] = min(minimum_subset_diff(arr,n-1,cum_sum,dp,second_sum+arr[n-1]),minimum_subset_diff(arr,n-1,cum_sum,dp,second_sum));
    return dp[n][second_sum];
}

int minimum_subset_diff_top_down(vector<int> arr,int n,int cum_sum,vector<vector<int>> dp,int second_sum){
    for(int i=0;i<n+1;i++){
        for(int j = 0;j<=cum_sum+1;j++){
            if(i == 0)
                dp[i][j] = abs((cum_sum - j) - j);
            else if(arr[n-1] <= cum_sum){
                dp[i][j] = min(dp[i-1][j - arr[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][cum_sum];
}

int minimum_subset_diff_top_down_dpd(vector<int> arr,int n,int cum_sum,vector<int> dpd,int second_sum){
    for(int i=0;i<n+1;i++){
        for(int j = cum_sum;j>=0;j--){
            if(i == 0)
                dpd[j] = abs((cum_sum - j) - j);
            else if(arr[n-1] <= cum_sum){
                dpd[j] = min(dpd[j - arr[i-1]],dpd[j]);
            }
        }
    }
    return dpd[cum_sum];
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

void aditya_verma_method(vector<int> &dpd,int n,int cum_sum){
    int ans = INT_MAX;
    for(int i =0;i<=cum_sum/2;i++)
        if(dpd[i] == 1)
            ans=min(ans,abs(cum_sum - (2*i)));
    cout<<"The Result is: "<<ans<<endl;
}

int main(){
    vector<int> arr = {1,5,4,9};
    int n = 4;
    int cum_sum = 0;
    for(int i=0;i<n;i++)
        cum_sum+=arr[i];
    vector<vector<int>> dp(n+1,vector<int>(cum_sum+1,-1));
    cout<<minimum_subset_diff(arr,n,cum_sum,dp,0)<<endl;
    vector<int> dpd(cum_sum+1,0);
    cout<<minimum_subset_diff_top_down_dpd(arr,n,cum_sum,dpd,0)<<endl;
    cout<<minimum_subset_diff_top_down(arr,n,cum_sum,dp,0)<<endl;
    top_bottom_dpd(arr,n,cum_sum,dpd);
    aditya_verma_method(dpd,n,cum_sum);
}