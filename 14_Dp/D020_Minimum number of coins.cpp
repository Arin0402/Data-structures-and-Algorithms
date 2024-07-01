#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Why greedy fails ?
// https://www.youtube.com/watch?v=mVg9CfJvayM

// 1
// memo
// O(n*V)
// O(n*V) + O(n)
class Solution{

	public:
	
	int helper(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
	    
	    if(target == 0) return 0;
	    
	    if(ind == 0){
	        
	        if(target%coins[ind] == 0) return target/coins[ind];
	        
	        // Not possible
	        return INT_MAX;
	    }
	    
	    if(dp[ind][target] != -1) return dp[ind][target];
	    
	    // not_take
	    int choice1 = helper(ind - 1, target, coins, dp);
	    
	    
	    // take
	    int choice2 = INT_MAX;
	    if(coins[ind] <= target){
	        
	        int val = helper(ind , target - coins[ind], coins, dp); 
	        
	        if(val != INT_MAX) choice2 = 1 + val;
	        
	    }
	    
	    return dp[ind][target] = min(choice1, choice2);
	    
	}
	
	int minCoins(vector<int> &coins, int M, int target) 
	{ 
	    vector<vector<int>> dp(M, vector<int>(target + 1, -1));
	    
	    int ans = helper(M-1, target, coins, dp); 
        return ans == INT_MAX ? -1: ans ;
	} 
	  
};


// 2
// tab
// O(n*V)
// O(n*V)
class Solution
{
public:
	int minCoins(int coins[], int M, int V)
	{

		vector<vector<int>> dp(M, vector<int>(V + 1, 0));

		for (int i = 0; i <= V; i++)
		{
			if (i % coins[0] == 0)
				dp[0][i] = i / coins[0];
			else
				dp[0][i] = 1e9;
		}

		for (int i = 1; i < M; i++)
		{
			for (int j = 0; j <= V; j++)
			{

				int not_take = dp[i - 1][j];
				int take = INT_MAX;

				if (coins[i] <= j)
					take = 1 + dp[i][j - coins[i]];

				dp[i][j] = min(take, not_take);
			}
		}

		int ans = dp[M - 1][V];
		return ans < 1e9 ? ans : -1;
	}
};

// 3
// space optimised
// O(n*V)
// O(2*V)
class Solution
{
public:
	int minCoins(int coins[], int M, int V)
	{

		vector<int> prev(V + 1, 0);

		for (int i = 0; i <= V; i++)
		{
			if (i % coins[0] == 0)
				prev[i] = i / coins[0];
			else
				prev[i] = 1e9;
		}

		for (int i = 1; i < M; i++)
		{

			vector<int> temp(V + 1, 0);
			for (int j = 0; j <= V; j++)
			{

				int not_take = prev[j];
				int take = INT_MAX;

				if (coins[i] <= j)
					take = 1 + temp[j - coins[i]];

				temp[j] = min(take, not_take);
			}

			prev = temp;
		}

		int ans = prev[V];
		return ans < 1e9 ? ans : -1;
	}
};
