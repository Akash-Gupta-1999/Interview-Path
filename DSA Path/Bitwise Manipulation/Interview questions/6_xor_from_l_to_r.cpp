#include <bits/stdc++.h>
using namespace std;

/*
   Function to compute XOR from 1 to n in O(1).
    1        --------> 1
    1^2      --------> 3
    1^2^3    --------> 0
    1^2^3^4  --------> 4
    1^2^3^4^5    --------> 1
    1^2^3^4^5^6  --------> 7
    1^2^3^4^5^6^7    --------> 0
    1^2^3^4^5^6^7^8  --------> 8
    1^2^3^4^5^6^7^8^9    --------> 1
    1^2^3^4^5^6^7^8^9^10 --------> 11
    1^2^3^4^5^6^7^8^9^10^11 --------> 0
    1^2^3^4^5^6^7^8^9^10^11^12 --------> 12
   Pattern:
     n % 4 == 0 -> result = n
     n % 4 == 1 -> result = 1
     n % 4 == 2 -> result = n+1
     n % 4 == 3 -> result = 0
*/
int xorFrom1ToN(int n) {
    if (n < 0) return 0; // handle case when l=0
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// XOR from L to R
int xorFromLToR(int l, int r) {
    return xorFrom1ToN(r) ^ xorFrom1ToN(l - 1);
}

int main() {
    vector<pair<int,int>> testcases = {
        {1, 1}, {1, 2}, {2, 4}, {3, 7}, {5, 10}, {1, 16}, {7, 7}
    };

    for (auto [l, r] : testcases) {
        cout << "XOR from " << l << " to " << r 
             << " = " << xorFromLToR(l, r) << endl;
    }

    return 0;
}
