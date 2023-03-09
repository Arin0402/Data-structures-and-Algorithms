#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

// 1
// O(n^2)
// find the maximum for each index

// basic idea is to use 0 as 1 and decrease the count of 0s for each use.
// if 0 is encounter then decrease the count of m.
// if m < 0, calculcate the length.

// 2
// O(n)
// sliding window
// same concept as above
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    
    int findZeroes(int arr[], int n, int m) {
        
        int l = 0;
        int r = 0;
        
        int maxi = 0;
        
        while(r < n){
            
            // if right element is 0, then use it and decrease the count of m.
            if(arr[r] == 0) m--;
            
            // count is less than zero.
            if(m < 0){
                // calculate the maximum length.
                maxi = max(maxi, r - l);
                
                // shift the window by 1 from left.
                // if the left elemenrt is zero, increase the count.
                if(arr[l] == 0) m++;
                l++;
            }
            
            r++;
        }
        
        maxi = max(maxi, r - l);
        
        return maxi;
        
    }  
};