#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

// absolutely same as unbounded knapsack problem. (D023)
// assume the length pieces form 1 to n be the weights and price[] as val[]

// 1
// memo
class Solution
{
public:
    int helper(int ind, int W, int val[], vector<vector<int>> &dp)
    {

        // ind + 1 will denote the weight at that index.

        if (ind == 0)
        {
 
            return W * val[0];

            // OR  (but ind + 1  in this case would be equal to 1, so it boils down to return W*val[0])
            // return (W/ (ind + 1))*val[0];
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int not_take = helper(ind - 1, W, val, dp);
        int take = INT_MIN;

        if (ind + 1 <= W)
            take = val[ind] + helper(ind, W - (ind + 1), val, dp);

        return dp[ind][W] = max(take, not_take);
    }

    int cutRod(int price[], int n)
    {

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(n - 1, n, price, dp);
    }
};
