#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long double ans = 1;

    // ✅ Why use long long nn instead of int n directly:
    // If n = INT_MIN (-2147483648), then -n cannot be represented as an int
    // because INT_MAX is only 2147483647. Doing `n = -n` would overflow.
    // By storing n in a long long (nn), we safely handle this case.
    int sign = 1;
    long long nn = n;
    if (nn < 0) {
        sign = -1;
        nn = -nn; // safe now, no overflow
    }

    while (nn > 0) {
        if (nn % 2) {
            ans = ans * x;
            nn--;
        } else {
            x = x * x;
            nn /= 2;
        }
    }

    if (sign == -1)
        return (1.0 / ans);
    return ans;
}

int main() {
    vector<tuple<double, int, double>> tests = {
        {2.0, 10, 1024.0},
        {2.1, 3, 9.261},
        {2.0, -2, 0.25},
        {2.0, 0, 1.0},
        {0.0, 5, 0.0},
        {-2.0, 3, -8.0},
        {-2.0, 4, 16.0},
        {1.00001, 123456, pow(1.00001, 123456)},
        {2.0, INT_MIN, pow(2.0, INT_MIN)} // extreme negative exponent
    };

    cout << fixed << setprecision(15);
    for (auto &[x, n, expected] : tests) {
        double result = myPow(x, n);
        cout << "myPow(" << x << ", " << n << ") = " << result
             << "  (expected ≈ " << expected << ")\n";
    }

    return 0;
}
