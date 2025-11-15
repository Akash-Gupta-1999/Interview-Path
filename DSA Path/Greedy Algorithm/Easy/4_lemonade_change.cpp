#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    vector<int> change(2, 0); // change[0] = count of $5, change[1] = count of $10

    for (int bill : bills) {
        if (bill == 5) {
            change[0]++;
        } 
        else if (bill == 10) {
            if (change[0] == 0) return false;
            change[0]--;
            change[1]++;
        } 
        else { // bill == 20
            if (change[1] > 0 && change[0] > 0) {
                // Prefer giving back one $10 and one $5
                change[1]--;
                change[0]--;
            } 
            else if (change[0] >= 3) {
                // Otherwise give back three $5 bills
                change[0] -= 3;
            } 
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> testCases = {
        {5,5,5,10,20},     // true
        {5,5,10},          // true
        {10,10},           // false (no $5 to give back)
        {5,5,10,10,20},    // false (need $5 but none left)
        {5,5,5,5,10,20,5,5,20,5}, // true
        {5,20},            // false (need $15 change, impossible)
        {5,5,10,20}        // true
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test " << i+1 << ": "
             << (lemonadeChange(testCases[i]) ? "true" : "false")
             << endl;
    }
    return 0;
}
