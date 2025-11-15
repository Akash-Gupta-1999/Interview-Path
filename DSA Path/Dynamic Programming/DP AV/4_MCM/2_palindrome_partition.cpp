#include<bits/stdc++.h>
using namespace std;

int ispalindrome(string s,int i,int j){
    int flag = 1;
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int partition(string s,int i,int j,vector<vector<int>>& dp){
    if(i == j)
        return 1;
    if(ispalindrome(s,i,j))
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini = INT_MAX;
    int temp;
    for(int k = i;k<=j-1;k++){
        temp = partition(s,i,k,dp) + partition(s,k+1,j,dp);
        mini = min(mini,temp);
        dp[i][j] = mini;
    }
    return dp[i][j];
}

int aditya_opt_partition(string s,int i,int j,vector<vector<int>>& dp){
    if(i == j)
        return 1;
    if(ispalindrome(s,i,j))
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini = INT_MAX;
    int temp;
    for(int k = i;k<=j-1;k++){
        int left,right;
        if(dp[i][k]!=-1)
            left = dp[i][k];
        else
            left = aditya_opt_partition(s,i,k,dp);
        dp[i][k] = left;
        if(dp[k+1][j]!=-1)
            right = dp[k+1][j];
        else
            right = aditya_opt_partition(s,k+1,j,dp);
        dp[k+1][j] = right;
        temp = left+right;
        mini = min(mini,temp);
        dp[i][j] = mini;
    }
    return dp[i][j];
}

int main(){
    string s = "adbcbde";
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<partition(s,0,s.size()-1,dp) - 1<<endl;
    cout<<aditya_opt_partition(s,0,s.size()-1,dp)-1<<endl;
}