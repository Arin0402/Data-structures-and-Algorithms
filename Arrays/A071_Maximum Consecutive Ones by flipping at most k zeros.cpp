#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-consecutive-ones/1

// 1
// try all the substrings
// O(N^3)

// 2
// slinding window
// O(2*n) = O(N)
// O(1)

class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        
        int l = 0;
        int r = 0;
        
        int maxi = -1;
        
        while(r < n){
            
            // element is one
            if(nums[r] == 1) r++;
            
            // element is zero
            else{
                
                // have used all the zeros before
                if(k == 0){
                    
                    // update maxi
                    maxi = max(maxi, r - l);
                    
                    // update l
                    // go to index next to the first occurence of zero in ths window
                    while(nums[l] != 0) l++;
                    
                    l++;
                    
                    // increase k by 1 as we have one zero available to flip
                    k += 1;
                }
                else{
                    // decrease k by one
                    k--;
                    
                    // update r
                    r++;
                }
                
            }
            
        }
        
        // for last case
        if(l < n) maxi = max(maxi, r - l);
        
        return maxi;
        
    }
};