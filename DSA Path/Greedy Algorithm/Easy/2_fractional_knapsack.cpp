#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator based on value-to-weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // higher ratio first
}

/*
Intuition:
- Greedy pick items with highest value/weight ratio.
- Take full item if it fits, else take fraction.
*/
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;

    for (auto& it : items) {
        if (W == 0) break; // knapsack full
        if (it.weight <= W) {
            // Take full item
            W -= it.weight;
            totalValue += it.value;
        } else {
            // Take fraction of item
            totalValue += it.value * ((double)W / it.weight);
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items;

    // Testcase 1
    items = { {60, 10}, {100, 20}, {120, 30} };
    int W = 50;
    cout << "TC1: " << fractionalKnapsack(W, items) << endl;
    // Expected: 240 (take item2+item3 fully, 2/3 of item1)

    // Testcase 2
    items = { {500, 30}, {400, 20}, {200, 10} };
    W = 40;
    cout << "TC2: " << fractionalKnapsack(W, items) << endl;
    // Expected: 900 (take items2+3 fully, 10/30 of item1)

    // Testcase 3
    items = { {100, 20}, {60, 10}, {120, 30} };
    W = 10;
    cout << "TC3: " << fractionalKnapsack(W, items) << endl;
    // Expected: 60 (best ratio item2 fits fully)

    // Testcase 4
    items = { {200, 50}, {180, 30}, {100, 10} };
    W = 20;
    cout << "TC4: " << fractionalKnapsack(W, items) << endl;
    // Expected: 100 + 2/3 of item2 = 220

    // Testcase 5
    items = { {100, 10}, {280, 40}, {120, 20}, {120, 24} };
    W = 60;
    cout << "TC5: " << fractionalKnapsack(W, items) << endl;
    // Expected: 440
}
