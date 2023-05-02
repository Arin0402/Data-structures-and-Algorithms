#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// 1
// memo
// O(N)
// O(N) + O(N)

class Solution{

    public:
        int helper(int ind, vector<int> &nums, vector<int> &dp){
        
        if(ind < 0 ) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + helper(ind - 2, nums, dp );
        int not_pick = helper(ind-1, nums, dp);
        
        return dp[ind] =  max(pick, not_pick);        
    }

    int maximumNonAdjacentSum(vector<int> &nums){
        
        int n = nums.size();        
        vector<int> dp(n , -1);
        
        return helper(n-1, nums, dp);
        
    }

};

// 2
// tabulation
// space optimised
int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();                
    
    int prev2 = INT_MIN;
    int prev1 = INT_MIN;
    int num;
    
    for(int i = 0 ; i  < n;  i++){        
        
        // taking care of edge cases of negtive indexes.    
        int pick = nums[i] + (i-2 >= 0 ? prev2 : 0) ;
        int not_pick = (i-1 >= 0 ? prev1 : 0);                
        
        num = max(pick, not_pick);        
        
        prev2 = prev1;
        prev1 = num;     
    }
    
    return num;
    
}