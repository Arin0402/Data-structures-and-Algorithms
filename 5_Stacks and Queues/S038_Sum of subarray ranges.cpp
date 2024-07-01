#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sum-of-subarray-ranges/1

// 1
// using sliding window
// O(N^2)
class Solution {
  public:
    long long subarrayRanges(int N, vector<int> &nums) {
        
        int n = nums.size();
        long long int ans = 0;

        for(int left = 0; left < n; left++){            
            
            // minimum value of the current window
            int minVal = nums[left];  
            
            // maximum value of the current window
            int maxVal = nums[left];

            for(int right = left; right < n; right++){
                
                // update the values as we move forward
                
                maxVal = max(maxVal, nums[right]);
                minVal = min(minVal, nums[right]);

                // add to the answer
                ans += maxVal - minVal;
            }
        }

        return ans;
    }
};

// 2
// O(N)
// same as S036.
// answer would be ans = sum of subarrays maximum - sum of subarrays minimum.
