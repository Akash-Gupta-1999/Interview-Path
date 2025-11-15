#include <bits/stdc++.h>
using namespace std;

// Function to return all prime factors of n
vector<int> primeFactors(int n) {
    vector<int> factors;

    // Loop from 2 to sqrt(n)
    // Time Complexity: O(√n)
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            factors.push_back(i);

        // Each prime factor divides n only a limited number of times
        // Overall divisions across the loop = O(log n) at most
        while (n % i == 0)
            n /= i;
    }

    // If n is still > 1, then it is prime
    if (n != 1)
        factors.push_back(n);

    return factors;
}

int main() {
    // Test cases
    vector<int> testCases = {12, 30, 37, 100, 315};

    for (int n : testCases) {
        vector<int> factors = primeFactors(n);
        cout << "Prime factors of " << n << ": ";
        for (int f : factors) cout << f << " ";
        cout << endl;
    }

    return 0;
}

/*
Time Complexity: 
- Outer loop runs up to √n → O(√n)
- Inner while loop reduces n across iterations → O(log n) overall
=> Total: O(√n)

Space Complexity:
- Stores only distinct prime factors → O(k), where k ≤ log n
*/
