#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size();
    long long sn = (n * (n + 1)) / 2, s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0, s2 = 0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        s+=a[i-1]; 
        s2+=(a[i-1] * a[i-1]);
    }
    //S-Sn = X-Y:
    long long val1 = s - sn;
    // S2-S2n = X^2-Y^2:
    long long val2 = s2 - s2n;
    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;
    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

vector<int> findMissingRepeatingNumbers_xor(vector<int> a){
    int xr = 0, xr1 = 0, n = a.size();
    for(int i=0;i<n;i++){
        xr^=a[i];
        xr1^=(i+1);
    }
    xr1 = xr1 ^ xr;
    int set_bit = xr1 & ~(xr1-1);
    int zero = 0, one = 0;
    for(int i=0;i<n;i++){
        if(set_bit & a[i])
            one^=a[i];
        else
            zero^=a[i];
        if(set_bit & (i+1))
            one^=(i+1);
        else
            zero^=(i+1);
    }
    int ct = 0;
    for(int i=0;i<n;i++){
        if(a[i] == one)
            ct++;
    }
    if(ct == 2) return {one,zero};
    return {zero,one};
} 

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    vector<int> ans1 = findMissingRepeatingNumbers_xor(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    cout << "The repeating and missing numbers are: {"
         << ans1[0] << ", " << ans1[1] << "}\n";
    return 0;
}