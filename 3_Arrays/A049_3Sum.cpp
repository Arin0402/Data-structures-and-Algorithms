#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/3sum/

// 1
// O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
       
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i =0 ; i < n-2; i++){
            
            if(nums[i] > 0) break; // number greater than zero.
            if(i > 0 && nums[i] == nums[i-1]) continue; // escape for same number  - -7,-6,-6,2,3,3,4  Here -6.
            
            int sum = 0 - nums[i]; // sum to be searched.
            int low = i+1;
            int high = n-1;
            
            while(low < high){
                
                if(nums[low] + nums[high] == sum)
                {
                    
                    ans.push_back({nums[i], nums[low], nums[high]});
                    
                    // avoiod repetiion of same pairs as we are not breaking out of the loop.
                    while(low < high && nums[low] == nums[low+1]) low++; 
                    while(low < high && nums[high] == nums[high-1]) high--;                                    
                    
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < sum) low++;
                else high--;
            }                
            
        }
        
        return ans;
        
    }
};