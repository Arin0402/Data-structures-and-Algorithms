#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution
{
public:
	int helper(int ind, int target, int arr[], vector<vector<int>> &dp)
	{

		// beacuse in the constraints , numbers can be zero also. consider example - 0 0 1,  ans = 4.
		if (ind < 0)
		{
			if (target == 0)
				return 1;
			return 0;
		}

		// OR

		// if(ind == 0){
		//     if(target == 0 && arr[0] == 0) return 2;
		//     if(target == 0 || arr[0] == target) return 1;
		//     return 0;
		// }

		if (dp[ind][target] != -1)
			return dp[ind][target];

		int not_take = helper(ind - 1, target, arr, dp);
		int take = 0;

		if (arr[ind] <= target)
			take = helper(ind - 1, target - arr[ind], arr, dp);

		return dp[ind][target] = (not_take % MOD + take % MOD) % MOD;
	}

	int perfectSum(int arr[], int n, int sum)
	{

		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

		return helper(n - 1, sum, arr, dp);
	}
};