#include<bits/stdc++.h>
using namespace std;

int ncr(int n, int r){
    int val = 1;
    for(int i = 1;i<=r;i++){  // ncr = n/1 * (n-1)/2 * (n-3)/3 * ...... * (n-r)/r
        val*=(n-i+1);
        val/=i;
    }
    return val;
}

int main(){
    int n = 10, r = 6;
    cout<<ncr(n-1,r-1)<<endl; 
}

// 1    0c0
// 11   1c0, 1c1
// 121  2c0,2c1,2c2
//1331
//14641