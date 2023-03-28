#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/

// solution 
// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/solutions/3341928/c-java-python3-prefix-sums-binary-search/

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());
        
        // size of nums.
        int n = nums.size();
        
        // prefix sum
        vector<long long> prefix(n+1, 0);
        
        
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + (long long) nums[i];
        
        vector<long long> ans;
        
        for(auto q : queries){
            
            // find the number of emements smaller than q.            
            int ind = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            
            long long count = 0;
            
            // for elements smaller than q
            // increment required
            count +=  1LL*ind*q - prefix[ind];
            
            
            // for elements greater than or equal to q
            // decrement required            
            count +=  (prefix[n] - prefix[ind]) - 1LL*(n-ind)*q;
                                    
            
            ans.push_back(count);
        }
        
        return ans;
                
    }
};