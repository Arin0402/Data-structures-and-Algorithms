#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/

// 1
// O(N^2)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();

        // count the number of ones int the nums
        int cntOne = count(nums.begin(), nums.end(), 1);

        // if the numeber of 1s is greater than zero then, it is possible to make all 
        // elemnts as 1.
        if(cntOne > 0)  return n - cntOne;

        // else
        
        // calculate GCD of all the numbers
        int GCD = 0;
        for(int i = 0; i < n; i++){
            GCD = __gcd(GCD, nums[i]);
        }

        // if the GCd of all the numbers is not equal to 1, then we cannnot make all the 
        // elements 1, so return -1
        if(GCD != 1)  return -1;

        // else

        // minimum number of operations required to make at one element in array as 1
        int mi = INT_MAX;    

        // try all the subarrays
        for(int i = 0 ; i < n; i++){
            
            int res = nums[i];
        
            for(int j = i; j < n; j++){                
                res = __gcd(res, nums[j]);

                // found gcd equal to 1 for the current subarray.
                if(res == 1) mi = min(mi, j - i);
            }
        }

        // return the minimum number of operations
        return n + mi - 1;
    }
}; 