#include<bits/stdc++.h>
using namespace std;

int ncr(int n, int r){
    int val = 1;
    for(int i = 1;i<=r;i++){  // ncr = n/1 * (n-1)/2 * (n-2)/3 * ...... * (n-r+1)/r
        val*=(n-i+1);
        val/=i;
    }
    return val;
}

int main(){
    int n = 10, r = 6; // n is row number and r is index
    cout<<ncr(n-1,r-1)<<endl; 
}

// 1    0c0
// 11   1c0, 1c1
// 121  2c0,2c1,2c2
//1331
//14641

//ncr = n!/(r!*(n-r)!) = n * n-1 * n-2 * ..... * (n-r+1) * (n-r)! / (r * r-1 * r-2 * ..... * 1 * (n-r)!) = n/1 * (n-1)/2 * (n-2)/3 * ...... * (n-r+1)/r