#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int windowSize = n - k;   // size of the "dropped" window
    int curr_sum = 0, left = 0;

    // total sum of all cards
    int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

    // if we must take all cards, just return total
    if (k == n)
        return total;

    // Step 1: Take the first (n-k) elements as initial dropped window
    for (int i = 0; i < windowSize; i++) {
        curr_sum += cardPoints[i];
    }
    int min_sum = curr_sum; // smallest dropped window sum

    // Step 2: Slide the window across the array
    for (int i = windowSize; i < n; i++) {
        curr_sum -= cardPoints[left++];  // remove left element
        curr_sum += cardPoints[i];       // add new right element
        min_sum = min(min_sum, curr_sum);
    }

    // Step 3: max score = total - minimum dropped window sum
    return total - min_sum;
}

/*
Intuition:
------------
- We need to take exactly k cards from either front or back.
- Equivalent to "dropping" exactly (n-k) cards in one consecutive window.
- So, find the minimum sum subarray of length (n-k).
- Answer = total sum of array - minimum dropped sum.
- This works because the chosen k cards are everything except that dropped window.
*/

int main() {
    vector<int> cards1 = {1,2,3,4,5,6,1};
    cout << "Test1: " << maxScore(cards1, 3) << " (Expected 12)\n";

    vector<int> cards2 = {2,2,2};
    cout << "Test2: " << maxScore(cards2, 2) << " (Expected 4)\n";

    vector<int> cards3 = {9,7,7,9,7,7,9};
    cout << "Test3: " << maxScore(cards3, 7) << " (Expected 55)\n";

    vector<int> cards4 = {1,1000,1};
    cout << "Test4: " << maxScore(cards4, 1) << " (Expected 1)\n";

    vector<int> cards5 = {96,90,41,82,39,74,64,50,30};
    cout << "Test5: " << maxScore(cards5, 8) << " (Expected 536)\n";

    return 0;
}
