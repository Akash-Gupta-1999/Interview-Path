#include<bits/stdc++.h>
using namespace std;

int top_down(string x,string y,int n1,int n2,vector<vector<int>>& dp){
    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+1;j++){
            if(i==0 || j == 0)
                dp[i][j] = 0;
            else if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

set<string> print_all_subsequence(string x,string y,int n1,int n2,vector<vector<int>> dp){
    set<string> s;
    if(n1 == 0 || n2 == 0){
        s.insert("");
        return s;
    }
    if(x[n1-1] == y[n2-1]){
        set<string> temp = print_all_subsequence(x,y,n1-1,n2-1,dp);
        for(string ss : temp)
            s.insert(ss + x[n1-1]);
    }
    else{
        if(dp[n1-1][n2] >= dp[n1][n2-1])
            s = print_all_subsequence(x,y,n1-1,n2,dp);
        if(dp[n1][n2-1] >= dp[n1-1][n2]){
            set<string> temp = print_all_subsequence(x,y,n1,n2-1,dp);
            for(string ss : temp)
                s.insert(ss);
        }
    }
    return s;
}

int main(){
    string x = "AGTGATG";
    string y = "GTTAG";
    int n1,n2;
    n1 = x.size();
    n2 = y.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    cout<<top_down(x,y,n1,n2,dp)<<endl;
    set<string> s = print_all_subsequence(x,y,n1,n2,dp);
    for(string ss : s)
        cout<<ss<<" ";
    cout<<endl;
}