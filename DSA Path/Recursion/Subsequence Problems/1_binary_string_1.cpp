#include <bits/stdc++.h>
using namespace std;

// Recursive helper function
void generateStrings(int n, string current, vector<string> &result) {
    // Base case: if current string length == n, store it
    if (current.size() == n) {
        result.push_back(current);
        return;
    }

    // Always allowed to add '0'
    generateStrings(n, current + '0', result);

    // Add '1' only if the last character is not '1'
    if (current.empty() || current.back() != '1') {
        generateStrings(n, current + '1', result);
    }
}

// Main function to return all strings
vector<string> getBinaryStringsNoConsecOnes(int n) {
    vector<string> result;
    generateStrings(n, "", result);
    return result;
}

int main() {
    // Test cases
    vector<int> testCases = {2, 3, 4};

    for (int n : testCases) {
        cout << "Binary strings of length " << n << " with no consecutive 1's:\n";
        vector<string> strings = getBinaryStringsNoConsecOnes(n);
        for (const string &s : strings) {
            cout << s << "\n";
        }
        cout << "Total: " << strings.size() << "\n\n";
    }

    return 0;
}
