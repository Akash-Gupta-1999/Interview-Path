#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int i,int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int max_idx = i;
    if(left<n && arr[left] > arr[max_idx])
        max_idx = left;
    if(right<n && arr[right] > arr[max_idx])
        max_idx = right;
    if(max_idx != i){
        swap(arr[i],arr[max_idx]);
        heapify(arr,max_idx,n);
    }
}

// Function to convert a min-heap array into a max-heap array
void convertMinToMaxHeap(vector<int>& arr) {
    // TODO: implement conversion logic
    int n = arr.size();
    for(int i = (n-2)/2;i>=0;i--){
        heapify(arr,i,n);
    }
}

int main() {
    // Testcases: each array here is a valid min-heap
    vector<vector<int>> testcases = {
        {1, 3, 5, 7, 9, 11},          // complete min-heap
        {2, 4, 8, 10, 12, 14, 16},    // complete min-heap
        {5, 10, 15, 20, 30, 40},      // complete min-heap
        {1, 2, 3, 17, 19, 36, 7},     // min-heap
    };

    for (int i = 0; i < testcases.size(); i++) {
        cout << "Testcase " << i + 1 << " (Min-Heap): ";
        for (int x : testcases[i]) cout << x << " ";
        cout << endl;

        convertMinToMaxHeap(testcases[i]);

        cout << "Converted to Max-Heap: ";
        for (int x : testcases[i]) cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
