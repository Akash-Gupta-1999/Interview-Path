#include <bits/stdc++.h>
using namespace std;

/*
   Prime Factorization using Sieve of Smallest Prime Factors (SPF)
   ---------------------------------------------------------------
   Precomputation: O(n log log n)
   Factorization of a number: O(log n)
*/

// Function 1: Build sieve with smallest prime factor (SPF)
vector<int> sieveWithSPF(int n) {
    vector<int> spf(n + 1); // spf[i] = smallest prime factor of i
    for (int i = 0; i <= n; i++) spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i; // mark smallest prime
            }
        }
    }
    return spf;
}

// Function 2: Factorize a number using spf[]
vector<int> getFactorization(int n, vector<int>& spf) {
    vector<int> factors;
    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}

// Function 3: Driver
int main() {
    int N = 1000; // Precompute primes up to N
    vector<int> spf = sieveWithSPF(N);

    vector<int> testCases = {12, 30, 37, 100, 315};

    for (int n : testCases) {
        vector<int> factors = getFactorization(n, spf);
        cout << "Prime factorization of " << n << ": ";
        for (int f : factors) cout << f << " ";
        cout << endl;
    }

    return 0;
}
