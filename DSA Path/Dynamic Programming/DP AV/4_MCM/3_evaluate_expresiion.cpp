#include<bits/stdc++.h>
using namespace std;

int no_ways(char k,int lf,int lt,int rf,int rt,bool isbool){
    int ans;
    if(k == '|'){
        if(isbool == true)
            ans = lt * rf + lt*rt + lf * rt;
        else
            ans = lf*rf;
    }
    else if(k == '&'){
        if(isbool == true)
            ans = lt * rt;
        else
            ans = lf*rf + lt*rf + lf*rt;
    }
    else{
        if(isbool == true)
            ans = lt*rf + lf*rt;
        else
            ans = lf*rf + lt*rt;
    }
    return ans;
}

int ways_evaluate(string s,int i,int j,bool isbool,vector<vector<vector<int>>>& dp){
    if(i == j){
        if(isbool == true)
            return s[i] == 't';
        else
            return s[i] == 'f';
    }
    if(dp[i][j][isbool]!=-1)
        return dp[i][j][isbool];
    int lf,lt,rf,rt;
    int ans = 0;
    for(int k=i+1;k<=j-1;k+=2){
        if(dp[i][k-1][0]!=-1)
            lf = dp[i][k-1][0];
        else
            lf = ways_evaluate(s,i,k-1,false,dp);
        dp[i][k-1][0] = lf;
        if(dp[i][k-1][1]!=-1)
            lt = dp[i][k-1][1];
        else
            lt = ways_evaluate(s,i,k-1,true,dp);;
        dp[i][k-1][1] = lt;
        if(dp[k+1][j][0]!=-1)
            rf = dp[k+1][j][0];
        else
            rf = ways_evaluate(s,k+1,j,false,dp);
        dp[k+1][j][0] = rf;
        if(dp[k+1][j][1]!=-1)
            rt = dp[k+1][j][1];
        else
            rt = ways_evaluate(s,k+1,j,true,dp);
        dp[k+1][j][1] = rt;
        ans+=no_ways(s[k],lf,lt,rf,rt,isbool);
        dp[i][j][isbool] = ans;
    }
    return dp[i][j][isbool];
}

int main(){
    string s = "t|t&f^t";
    int n = s.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    cout<<ways_evaluate(s,0,s.size()-1,true,dp)<<endl;
}