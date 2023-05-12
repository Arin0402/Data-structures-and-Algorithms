#include <bits/stdc++.h>
using namespace std;

// instead of two steps , we can have k jumps from an index.

// 1
// memo
// O(N)*k ( k due to for loop)
// O(N) + O(N)
int helper(int ind, int k, vector<int> &heights, vector<int> &dp)
{
	if (ind == 0)
		return 0;

	int minSteps = INT_MAX;

	if (dp[ind] != -1)
		return dp[ind];

	for (int j = 1; j <= k; j++)
	{

		int l = INT_MAX;

		if (ind - j >= 0)
			l = helper(ind - j, k, heights, dp) + abs(heights[ind] - heights[ind - j]);
		minSteps = min(minSteps, l);
	}

	return dp[ind] = minSteps;
}

int frogKJump(int n, int k, vector<int> &heights)
{

	vector<int> dp(n, -1);
	return helper(n - 1, k, heights, dp);
}

// 2
// Tab
// O(N)*k ( k due to for loop)
// O(N) 
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        
        vector<int> dp(n, -1);
        
        dp[0] = 0;
        
        for(int i = 1; i <= n - 1; i++){
            
            int ans = INT_MAX;
        
            for(int j = 1; j <= k; j++){
                
                if(i - j >= 0){
                    ans = min(ans , abs(height[i] - height[i - j]) +  dp[i - j] );
                }
            }
        
            dp[i] = ans;
        }
        
        return dp[n-1];
    }
};