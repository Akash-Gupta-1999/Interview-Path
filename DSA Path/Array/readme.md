Array Questions
-   Easy
    1.  Check if Array is sorted or rotated :  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
    2.  Remove the duplicates and do inplace from sorted array : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
    3.  Rotate the Array k times : https://leetcode.com/problems/rotate-array/
    4.  Move Zeroes to the End : https://leetcode.com/problems/move-zeroes/description/
    5.  Union of 2 Arrays : https://takeuforward.org/data-structure/union-of-two-sorted-arrays/
    6.  Missing Number in an array : https://leetcode.com/problems/missing-number/
    7.  Max Consecutive 1's : https://leetcode.com/problems/max-consecutive-ones/description/
    8.  Single Integer : https://leetcode.com/problems/single-number/description/
    9.  *Maximum Subarray with given sum k (Prefix sum + Hash map) : https://takeuforward.org/plus/dsa/problems/longest-subarray-with-sum-k
-   Medium
    1.  2sum : https://leetcode.com/problems/two-sum/description/
    2.  sort colors (dutch flag algo) : https://leetcode.com/problems/sort-colors/description/
    3.  *Majority Element (more than n/2 times) (moore's voting Algo) : https://leetcode.com/problems/majority-element/description/
        -   n/3 times : https://leetcode.com/problems/majority-element-ii/description/
        -   n/k times
    4.  Max sum fo a subarray (Kadane Algo) : https://leetcode.com/problems/maximum-subarray/description/
    5.  Print max sub idx 
    6.  Buy and sell stock : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
    7.  *Alternate pos and neg with equal numbers : https://leetcode.com/problems/rearrange-array-elements-by-sign/
    8.  Unequal numbers of pos and neg 
    9.  *Next permutation : https://leetcode.com/problems/next-permutation/description/
    10. *Longest consecutive sequence in Array : https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
    11. *Set Matrix Zeroes : https://leetcode.com/problems/set-matrix-zeroes/description/  (O(1) space approach)
    12. *rotate matrix by 90 degree : https://leetcode.com/problems/rotate-image/description/
    13. *spiral matrix : https://leetcode.com/problems/spiral-matrix/description/
    14. *count subarrays with sum k : https://leetcode.com/problems/subarray-sum-equals-k/description/
-   Hard
    1.  *Pascal Triangle:
        1.  given any row and col. find the value in the pascal Triangle
        2.  given any row number. print the row in pascal triangle
        3.  https://leetcode.com/problems/pascals-triangle/description/ 
    2.  *Majority Element:
        1. more than (n/3) : https://leetcode.com/problems/majority-element-ii/description/
        2.  more than (n/k)
    3.  *3sum : https://leetcode.com/problems/3sum/description/
    4.  4sum : https://leetcode.com/problems/4sum/description/
    5.  Largest subarray with zero sum : https://www.geeksforgeeks.org/dsa/find-the-largest-subarray-with-0-sum/
    6.  Largest subarray with xor k : https://www.geeksforgeeks.org/dsa/count-number-subarrays-given-xor/
    7.  Merge Intervals : https://leetcode.com/problems/merge-intervals/description/
    8.  Merge 2 sorted Arrays:
        1.  Type 1 : sort 2 sorted arrays without extra space but catch here is that last element of first array is less than first element of second array. like arr1 = [1,3,7,8], arr2 = [4,6,9,10] => arr1 = [1,3,4,6], arr2 = [7,8,9,10]
        2.  Type 2 : https://leetcode.com/problems/merge-sorted-array/description/ 
    9.  find repeating one and missing one : https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
    10. count Inversions : https://takeuforward.org/data-structure/count-inversions-in-an-array/
    11. count reverse Pairs : https://leetcode.com/problems/reverse-pairs/description/
    12. Maximum product subarray : https://leetcode.com/problems/maximum-product-subarray/description/


-   Cheatsheet
    -   Easy/Medium/Hard
        1.  2 Pointers 
            -   Easy : Remove Duplicates from sorted array, Move zeroes to end, Union of 2 Arrays : simple in place manipulation with 2 pointers. Inplace Manipulation is like quick sort Technique
            -   Medium : Dutch National Flag Algo : sort colors : use 2 pointers to segregate 0s,1s and 2s in single traversal.
                -   new type here with space 0(N) : Alternate pos and neg with equal numbers, Unequal numbers of pos and negative : use extra array to store the result and then copy back to original array.
            -   Hard : 3sum, 4sum : use 2 pointers after fixing 1 or 2 elements to find the triplets or quadruplets with sum 0.
        2.  Prefix Sum
            -   Easy : Maximum subarray with given sum k : use prefix sum and hashmap to store the prefix sums and their indices.
            -   Medium : Count subarrays with sum k : use prefix sum and hashmap to store the frequency of prefix sums.
            -   Hard : Largest subarray with zero sum, Largest subarray with xor k : use prefix sum/xor and hashmap to store the first occurrence of prefix sums/xors.
    -   Easy
        1.  uniq problem : check if array is sorted and rotated, rotate array k times, max consecutive 1s
    -   Easy/Hard
        1.  XOR
            -   Easy : Missing number in an array, Single integer : use xor properties to find missing or single element in array.
            -   Hard : Find repeating one and missing one : use xor properties to find the missing and repeating elements in array.
    -   Medium/hard
        1.  Moore's Voting Algo
            -   Medium : Majority Element (more than n/2 times) : use count and candidate variable to find the majority element.
            -   Hard : Majority Element (more than n/3 times, more than n/k times) : use count1, count2 and candidate1, candidate2 variables to find the majority elements.
    -   Medium
        1.  uniq problem : next permutation, long consecutive sequence in array, set matrix zeroes, rotate matrix by 90 degree, spiral matrix, count subarrays with sum k
        2.  Type 1 : Hashing : 2sum, 4sum II :https://leetcode.com/problems/4sum-ii/description/ : use hashmap to store the elements and check for complement.
        4.  Type 3 : Kadane's Algo : Max sum of a subarray, Print Max subarray : use current sum and max sum variable to store the maximum sum of subarray.
        5.  Type 4 : Buy and Sell Stock : use min price variable to store the minimum price and max profit variable to store the maximum profit.
        6.  Type 5 : Matrix Manipulation : set matrix zeroes, rotate matrix by 90 degree, spiral matrix : use in place manipulation to achieve the desired result.
    -   Hard
        uniq problems : Maximum product subarray
        1.  Type 1 : Combinatorics : Pascal Triangle : use nCr formula to find the value in pascal triangle.
        2.  Type 2 : Merge Intervals : Merge Intervals : sort the intervals and then merge them if they overlap.
        3.  Type 3 : Sorting + Two pointers : Merge 2 sorted arrays : use gap method (Shell sort) or insertion method to merge two sorted arrays without extra space.
        4.  Type 4 : Divide and Conquer + Merge Sort : Count Inversions, Count Reverse Pairs : use modified merge sort to count inversions or reverse pairs.
