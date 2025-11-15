#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == divisor)
        return 1;
    int sign = 1;
    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        sign = -1;

    long long n = llabs(dividend);
    long long d = llabs(divisor);
    long long count = 0;

    while(n >= d) {
        int i = 0;
        while(n >= (d << (i+1LL)))
            i++;
        count += (1LL << i);
        n -= (d << i);
    }

    if(count > INT_MAX && sign == 1)
        return INT_MAX;
    if(count > INT_MAX && sign == -1)
        return INT_MIN;

    return (int)(count * sign);
}

int main() {
    vector<pair<int,int>> tests = {
        {10, 3},        // normal case
        {7, -3},        // negative divisor
        {-7, 3},        // negative dividend
        {-7, -3},       // both negative
        {INT_MAX, 1},   // edge: max int
        {INT_MIN, 1},   // edge: min int
        {INT_MIN, -1},  // overflow edge case -> INT_MAX
        {0, 5},         // zero dividend
        {5, INT_MAX},   // divisor > dividend
        {INT_MIN, INT_MIN} // equal -> 1
    };

    for(auto &tc : tests) {
        int dividend = tc.first, divisor = tc.second;
        cout << "divide(" << dividend << ", " << divisor << ") = "
             << divide(dividend, divisor) << "\n";
    }
    return 0;
}
