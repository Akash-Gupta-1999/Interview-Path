#include <bits/stdc++.h>
using namespace std;

/*
    Sieve of Eratosthenes Algorithm
    ---------------------------------
    Intuition:
    - A prime number is only divisible by 1 and itself.
    - To find all primes < n, we start from 2 and eliminate all multiples.
    - Instead of eliminating from 2*i, we start from i*i 
      (since smaller multiples are already eliminated).

    Time Complexity: O(n log log n)
    Space Complexity: O(n)
*/

// Function 1: Generate prime markers using sieve
vector<int> sieve(int n) {
    vector<int> primes(n, 1);   // Assume all are prime
    if (n > 0) primes[0] = 0;   // 0 not prime
    if (n > 1) primes[1] = 0;   // 1 not prime

    for (int i = 2; i <= sqrt(n); i++) {
        if (primes[i] == 1) {
            // Eliminate multiples of i
            for (int j = i * i; j < n; j += i) {
                primes[j] = 0;
            }
        }
    }
    return primes;
}

// Function 2: Count primes < n
int countPrimes(int n) {
    vector<int> primes = sieve(n);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (primes[i] == 1) count++;
    }
    return count;
}

// Function 3: Main driver
int main() {
    vector<int> testCases = {10, 20,25, 50, 100};

    for (int n : testCases) {
        cout << "Number of primes less than " << n 
             << " = " << countPrimes(n) << endl;
    }

    return 0;
}

// Nlog(logn)