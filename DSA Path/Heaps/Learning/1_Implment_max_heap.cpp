#include <bits/stdc++.h>
using namespace std;

class max_heap {
private:
    vector<int> pq;  // internal array to represent heap

    // Return index of parent node
    int parent(int i) { return (i - 1) / 2; }

    // Return index of left child
    int left_child(int i) { return 2 * i + 1; }

    // Return index of right child
    int right_child(int i) { return 2 * i + 2; }

    // Move element at idx UP until heap property is satisfied
    void shiftupward(int idx) {
        while (idx > 0 && pq[parent(idx)] < pq[idx]) {
            swap(pq[parent(idx)], pq[idx]);
            idx = parent(idx);
        }
    }

    // Move element at idx DOWN until heap property is satisfied
    void shiftdown(int idx) {
        int max_idx = idx; // keep track of largest so far
        if (left_child(idx) < pq.size() && pq[left_child(idx)] > pq[max_idx])
            max_idx = left_child(idx);
        if (right_child(idx) < pq.size() && pq[right_child(idx)] > pq[max_idx])
            max_idx = right_child(idx);
        if (idx != max_idx) {
            swap(pq[idx], pq[max_idx]);
            shiftdown(max_idx); // continue down
        }
    }

public:
    // Insert element into heap
    void insert(int num) {
        pq.push_back(num);
        shiftupward(pq.size() - 1); // bubble up newly inserted element
    }

    // Extract and return maximum element
    int extract() {
        if (pq.empty()) {
            throw runtime_error("Heap is empty, cannot extract.");
        }
        int num = pq[0];          // root is max
        pq[0] = pq.back();        // move last element to root
        pq.pop_back();
        if (!pq.empty()) shiftdown(0); // push root down to restore heap
        return num;
    }

    // Change value at index idx to num and fix heap property
    void changepriority(int idx, int num) {
        if (idx < 0 || idx >= pq.size()) {
            throw runtime_error("Index out of range.");
        }
        int old_val = pq[idx];
        pq[idx] = num;
        if (num > old_val)  // if increased, bubble up
            shiftupward(idx);
        else                // if decreased, bubble down
            shiftdown(idx);
    }

    // Get maximum element without removing it
    int getmax() {
        if (pq.empty()) throw runtime_error("Heap is empty.");
        return pq[0];
    }

    // Utility functions
    int size() { return pq.size(); }
    bool empty() { return pq.empty(); }

    // Print current heap (array representation, not sorted)
    void print() {
        for (int i = 0; i < pq.size(); i++)
            cout << pq[i] << " ";
        cout << endl;
    }
};

int main() {
    max_heap p;

    cout << "=== Inserting elements ===" << endl;
    vector<int> arr = {45, 20, 14, 12, 31, 7, 11, 13, 7};
    for (int x : arr) p.insert(x);
    p.print();

    cout << "\n=== Extract max ===" << endl;
    cout << "Extracted: " << p.extract() << endl;
    p.print();

    cout << "\n=== Change priority ===" << endl;
    p.changepriority(2, 49); // index 2 increased to 49
    p.print();

    cout << "\n=== Get max without extract ===" << endl;
    cout << "Current max: " << p.getmax() << endl;

    cout << "\n=== Extract all elements ===" << endl;
    while (!p.empty()) {
        cout << p.extract() << " ";
    }
    cout << endl;

    // Extra test: inserting decreasing order
    cout << "\n=== Insert decreasing numbers ===" << endl;
    for (int i = 10; i >= 1; i--) p.insert(i);
    p.print();

    // Extract until empty
    cout << "\nExtracting all: ";
    while (!p.empty()) cout << p.extract() << " ";
    cout << endl;

    return 0;
}
