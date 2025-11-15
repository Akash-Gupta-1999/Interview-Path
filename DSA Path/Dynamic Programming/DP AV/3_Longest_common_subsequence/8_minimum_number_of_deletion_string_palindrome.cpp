#include<bits/stdc++.h>
using namespace std;

int top_down(string x,string y,int n1,int n2){
    int n = min(n1,n2);
    int m = max(n1,n2);
    vector<int> curr(n+1,0),prev(n+1,0);
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j == 0)
                curr[j] = 0;
            else if(x[i-1] == y[j-1]){
                curr[j] = 1+prev[j-1];
            }
            else
                curr[j] = max(prev[j],curr[j-1]);
        }
        prev = curr;
    }
    return curr[n];
}

int main(){
    string x = "agbcba";
    string y = x;
    reverse(y.begin(),y.end());
    int s = top_down(x,y,x.size(),y.size());
    int n = x.size();
    cout<<abs(s-n)<<endl;
}
