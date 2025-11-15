#include<bits/stdc++.h>
using namespace std;

int subsequence(string x,string y,int n1,int n2){
        vector<int> prev(n1+1,0),curr(n2+1,0);
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n1+1;j++){
                if(i==0 || j == 0)
                    curr[j] = 0;
                else if(x[i-1] == y[j-1])
                    curr[j] = 1+prev[j-1];
                else 
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return curr[n1];
    }
    
int main() {
    string x = "leetcode";
    string y = x;
    reverse(y.begin(),y.end());
    int ans = subsequence(x,y,x.size(),y.size());
    cout<<x.size()-ans<<endl;
}