#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1'000'000'007;

// Modular exponentiation: computes (base^exp) % MOD in O(log exp)
long long modpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int countGoodNumbers(long long n) {
    long long evenCount = (n + 1) / 2; // positions where we put '5'
    long long oddCount = n / 2;       // positions where we put '4'
    long long ans = (modpow(5, evenCount) * modpow(4, oddCount)) % MOD;
    return (int)ans;
}

int main() {
    cout << countGoodNumbers(1) << "\n";                  // 5
    cout << countGoodNumbers(2) << "\n";                  // 20
    cout << countGoodNumbers(3) << "\n";                  // 80
    cout << countGoodNumbers(4) << "\n";                  // 320
    cout << countGoodNumbers(10) << "\n";                 // 3200000
    cout << countGoodNumbers(806166225460393LL) << "\n";  // works instantly
}
