#include <bits/stdc++.h>
using namespace std;

// Function to add two integers without using '+' or '-'
int add(int a, int b) {
    while (b != 0) {
        // carry contains common set bits of a and b
        int carry = (a & b) << 1;

        // XOR gives sum of bits where at least one is not set
        // (adds without considering carry)
        a = a ^ b;

        // Now add the carry in the next iteration
        b = carry;
    }
    return a;
}

int main() {
    // Testcases
    cout << add(5, 3) << endl;     // 8
    cout << add(-4, 7) << endl;    // 3
    cout << add(-6, -10) << endl;  // -16
    cout << add(0, 9) << endl;     // 9
    cout << add(100, 200) << endl; // 300
}
