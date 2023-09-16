#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// 1
// memo
// O(n*W)
// O(n*W) + O(n)

class Solution
{
public:
    int helper(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (wt[0] <= W)
                return val[0];
            return 0;
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int not_take = helper(ind - 1, W, wt, val, dp);

        int take = INT_MIN;
        if (wt[ind] <= W)
            take = val[ind] + helper(ind - 1, W - wt[ind], wt, val, dp);

        return dp[ind][W] = max(take, not_take);
    }

    int knapSack(int W, int wt[], int val[], int n)
    {

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return helper(n - 1, W, wt, val, dp);
    }
};

// 2
// tab
// O(n*W)
// O(n*W)
class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int i = 0; i <= W; i++)
        {
            if (wt[0] <= i)
                dp[0][i] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {

                int not_take = dp[i - 1][j];
                int take = INT_MIN;

                if (wt[i] <= j)
                    take = val[i] + dp[i - 1][j - wt[i]];

                dp[i][j] = max(take, not_take);
            }
        }

        return dp[n - 1][W];
    }
};

// 3
// space optimised
// O(n*W)
// O(2*W)
class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<int> prev(W + 1, 0);

        for (int i = 0; i <= W; i++)
        {
            if (wt[0] <= i)
                prev[i] = val[0];
        }

        for (int i = 1; i < n; i++)
        {

            vector<int> temp(W + 1, 0);
            for (int j = 0; j <= W; j++)
            {

                int not_take = prev[j];
                int take = INT_MIN;

                if (wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];

                temp[j] = max(take, not_take);
            }

            prev = temp;
        }

        return prev[W];
    }
};

// 4
// 1D array space optimisation

class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<int> prev(W + 1, 0);

        for (int i = 0; i <= W; i++)
        {
            if (wt[0] <= i)
                prev[i] = val[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = W; j >= 0; j--)
            {

                int not_take = prev[j];
                int take = INT_MIN;

                if (wt[i] <= j)
                    take = val[i] + prev[j - wt[i]];

                prev[j] = max(take, not_take);
            }
        }

        return prev[W];
    }
};