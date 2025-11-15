#include<bits/stdc++.h>
using namespace std;

string supersequence(string x,string y,int n1,int n2){
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
    int i=n1,j=n2;
    string ans = "";
    while(i!=0 && j!=0){
        if(x[i-1] == y[j-1]){
            ans+=x[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1] >= dp[i-1][j]){
            ans+=y[j-1];
            j--;
        }
        else{
            ans+=x[i-1];
            i--;
        }
    }
    while(i>0){
        ans+=x[i-1];
        i--;
    }
    while(j>0){
        ans+=y[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int n1 = x.size(),n2 =y.size();
    string ans = supersequence(x,y,n1,n2);
    cout<<ans<<" "<<ans.size()<<endl;
}