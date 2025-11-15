#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if(x == 1 || x == 0)
        return x;
    int low = 1, high = x/2;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(x/mid == mid)
            return mid;
        if(x/mid > mid){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans;
}

int main(){
    int n = 1124;
    cout<<mySqrt(n)<<endl;
}