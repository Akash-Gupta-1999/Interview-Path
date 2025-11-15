#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, vector<int>& nums2, int n, int m){
    int i = m-1, j = n-1, k = m+n-1;
       while(i>=0 && j>=0){
            if(nums1[i] >= nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
       }
       while(i>=0){
        nums1[k] = nums1[i];
        i--;
        k--;
       }
       while(j>=0){
        nums1[k] = nums2[j];
        j--;
        k--;
       }
}

int main(){
    vector<int> arr1 = {1,2,3,0,0,0};
    vector<int> arr2 = {2,5,6};
    int m = 3, n = 3;
    merge(arr1, arr2, m, n);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < m+n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}