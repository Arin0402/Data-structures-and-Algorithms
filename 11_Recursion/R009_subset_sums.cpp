#include <bits/stdc++.h>
using namespace std;

// subset sum 1
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1/#
// if required -
// https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10

// subset sum - 2
// https://leetcode.com/problems/subsets-ii/description/
// https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11
  
// TC - 2^n * n ( *n as we are putting ds into ans )
// sc - 2^n
class Solution {
public:
    
    void allthesubsets(int index,vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int n ){
        
        // push the ds into ans.
        // no base case as we want all the subsets.
        // not depending on sum or anything else.
        // the for loop will take care of index out of bound.
        ans.push_back(ds);
        
        for(int i = index ; i < n ;i++){
            
            if(i > index  && nums[i] == nums[i-1] ) continue; // avoiding duplicates;
            
            ds.push_back(nums[i]);
            allthesubsets(i +1, ds, ans, nums, n);
            ds.pop_back();
        }
            
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;    
        vector<int> ds;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        allthesubsets(0,ds,ans , nums, n);
        return ans;
        
    }
};