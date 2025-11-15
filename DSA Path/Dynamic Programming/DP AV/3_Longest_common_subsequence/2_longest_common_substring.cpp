#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int n1,int n2,int count){
    if(n1 == 0 || n2 == 0)
        return count;
    if(x[n1-1] == y[n2-1])
        return max(count+1,lcs(x,y,n1-1,n2-1,count+1));
    return max(lcs(x,y,n1-1,n2,0),lcs(x,y,n1,n2-1,0));
}

int lcs_dp(string x,string y,int n1,int n2,vector<vector<int>>& dp,int count){
    if(n1 == 0 || n2 == 0)
        return count;
    if(x[n1-1] == y[n2-1]){
        int temp = count+1;
        dp[n1][n2] = max(temp,lcs_dp(x,y,n1-1,n2-1,dp,count+1));
        return dp[n1][n2];
    }
    if(dp[n1][n2]!=-1)
        return dp[n1][n2];
    dp[n1][n2] = max(lcs_dp(x,y,n1-1,n2,dp,0),lcs_dp(x,y,n1,n2-1,dp,0));
    return dp[n1][n2];
}

int top_down(string x,string y,int n1,int n2,vector<vector<int>>& dp){
    int ans = 0;
    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+1;j++){
            if(i==0 || j == 0)
                dp[i][j] = 0;
            else if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

int top_down_dpd(string x,string y,int n1,int n2){
    vector<int> prev(n2+1,0),curr(n2+1,0);
    int ans = 0;
    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+1;j++){
            if(i==0||j==0)
                curr[j] = 0;
            else if(x[i-1] == y[j-1]){
                curr[j] = 1+prev[j-1];
                ans = max(ans,curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

int main(){
    string x = "cabcdgh";
    string y = "habedfr";
    int n1,n2;
    n1 = x.size();
    n2 = y.size();
    cout<<lcs(x,y,n1,n2,0)<<endl;
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    cout<<lcs_dp(x,y,n1,n2,dp,0)<<endl;
    cout<<top_down(x,y,n1,n2,dp)<<endl;
    cout<<top_down_dpd(x,y,n1,n2)<<endl;
}