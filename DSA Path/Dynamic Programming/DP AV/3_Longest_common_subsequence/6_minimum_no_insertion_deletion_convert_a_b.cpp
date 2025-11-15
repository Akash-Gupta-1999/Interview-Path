#include<bits/stdc++.h>
using namespace std;

int subsequence(string x,string y,int n1,int n2){
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+1;j++){
            if(i==0 || j == 0)
                dp[i][j] = 0;
            else if(x[i-1] == y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

int main(){
    string x = "heap";
    string y = "pea";
    int n1 = x.size(),n2 =y.size();
    int s = subsequence(x,y,n1,n2);
    int ans = abs(n1-s) + abs(n2-s);
    cout<<ans<<endl;
}