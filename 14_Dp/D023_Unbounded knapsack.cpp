#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// 1
// memo
// O(n*W)
// O(n*W) + O(n)
class Solution
{
public:
    int helper(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
    {

        if (ind < 0)                    
            return 0;
        

        // if (ind == 0)
        // {
        //     return (W / wt[0]) * val[0];
        // }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        int not_take = helper(ind - 1, W, val, wt, dp);
        int take = INT_MIN;

        if (wt[ind] <= W)
            take = val[ind] + helper(ind, W - wt[ind], val, wt, dp);

        return dp[ind][W] = max(take, not_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));

        return helper(N - 1, W, val, wt, dp);
    }
};

// 2
// tab
// O(n*W)
// O(n*W)
class Solution
{

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, 0));

        for (int i = 0; i <= W; i++)
        {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j <= W; j++)
            {

                int not_take = dp[i - 1][j];
                int take = INT_MIN;

                if (wt[i] <= j)
                    take = val[i] + dp[i][j - wt[i]];

                dp[i][j] = max(take, not_take);
            }
        }

        return dp[N - 1][W];
    }
};

// 3
class Solution
{

public:
    int knapSack(int N, int W, int val[], int wt[])
    {

        vector<int> prev(W + 1, 0);

        for (int i = 0; i <= W; i++)
        {
            prev[i] = (i / wt[0]) * val[0];
        }

        for (int i = 1; i < N; i++)
        {

            vector<int> temp(W + 1, 0);

            for (int j = 0; j <= W; j++)
            {

                int not_take = prev[j];
                int take = INT_MIN;

                if (wt[i] <= j)
                    take = val[i] + temp[j - wt[i]];

                temp[j] = max(take, not_take);
            }

            prev = temp;
        }

        return prev[W];
    }
};

// 4
// 1D array
class Solution
{

public:
    int knapSack(int N, int W, int val[], int wt[])
    {

        vector<int> prev(W + 1, 0);

        for (int i = 0; i <= W; i++)
        {
            prev[i] = (i / wt[0]) * val[0];
        }

        for (int i = 1; i < N; i++)
        {

            vector<int> temp(W + 1, 0);

            for (int j = 0; j <= W; j++)
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