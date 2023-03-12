#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1

// 1
// O(logn)
// O(logn)
class Solution {
  public:
    
    int helper(int low, int high, int arr[], int k){
        
        if(low > high)  return -1;
        
        int mid = low + (high - low)/2;
        if(arr[mid] == k) return mid;
        
        if(arr[mid] > k) return helper(low, mid-1, arr, k);
        else return helper(mid+1, high , arr, k);
        
        
    }
  
    int binarysearch(int arr[], int n, int k) {
        
        return helper(0, n-1, arr, k);
        
    }
};
