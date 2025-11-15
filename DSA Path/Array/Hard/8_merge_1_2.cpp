#include<bits/stdc++.h>
using namespace std;
// shell sort gap method
void merge(vector<int>& arr1, vector<int>& arr2, int n, int m){
    int gap = (m+n)/2 + (m+n)%2;
    while(gap>0){
        int left = 0, right = left + gap;
        while(right<m+n){
            int i,j;
            // case 1: left in arr1[]
            //and right in arr2[]:
            if(left<n && right>=n){
                i = left;
                j = right-n;
                if(arr1[i] > arr2[j])
                    swap(arr1[i],arr2[j]);
            }
            // case 2: both pointers in arr2[]:
            else if(left>=n){
                i = left-n;
                j = right -n;
                if(arr2[i] > arr2[j])
                    swap(arr2[i],arr2[j]);
            }
            // case 3: both pointers in arr1[]:
            else{
                i = left;
                j = right;
                if(arr1[i] > arr1[j])
                    swap(arr1[i],arr1[j]);
            }
            left++;
            right++;
        }
        // break if iteration gap=1 is completed:
        if(gap == 1)
            break;
        // Otherwise, calculate new gap:
        gap = (gap/2) + (gap%2);
    }
}

int main(){
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}