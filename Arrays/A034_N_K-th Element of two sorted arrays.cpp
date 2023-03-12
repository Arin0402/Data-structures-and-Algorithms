#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// https://www.youtube.com/watch?v=nv7F4PiLUzo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=67

// 1
// using extra space

// 2
// using pointers and count variable
// place pointers at the starting of the two and initialise a count variable
// compare and increase the pointers
// if count == k return

// 3
// usign binary search
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
        if(m > n) return kthElement(arr2, arr1, m, n, k);
        
        // if k is greater than the m, then we cannot take zero elements from first array
        // we have to take minimum of k - m elements
        int low = max(0, k - m);

        // if k is smaller than n, then we can not take n elements
        // in that case , we can only take k elements        
        int high = min(k, n);
        
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            int cut1 = mid;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 -1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1, l2);
            }
            else if(l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
            
        }
        
        
    }
};