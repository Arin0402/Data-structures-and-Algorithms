#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

// 1
// memo
// O(n*W)
// O(n*W) + O(n + W)
class Solution
{

public:
    int helper(int ind, int W, int cost[], int N, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (cost[0] != -1)
                return W * cost[0];
            return 1e9;
        }
        if (W == 0)
            return 0;

        if (dp[ind][W] != -1)
            return dp[ind][W];

        // can not take.
        if (cost[ind] == -1)
            return helper(ind - 1, W, cost, N, dp);

        int not_take = helper(ind - 1, W, cost, N, dp);
        int take = INT_MAX;
        if (W - (ind + 1) >= 0)
            take = cost[ind] + helper(ind, W - (ind + 1), cost, N, dp);

        return dp[ind][W] = min(take, not_take);
    }

    int minimumCost(int cost[], int N, int W)
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));

        int ways = helper(N - 1, W, cost, N, dp);
        return (ways >= 1e9 ? -1 : ways);
    }
};

// 2
// tab
class Solution
{

public:
    int minimumCost(int cost[], int N, int W)
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, 0));

        for (int j = 0; j <= W; j++)
        {

            if (cost[0] != -1)
                dp[0][j] = j * cost[0];
            else
                dp[0][j] = 1e9;
        }

        for (int i = 0; i < N; i++)
            dp[i][0] = 0;

        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j <= W; j++)
            {

                // can not take.
                if (cost[i] == -1)
                    dp[i][j] = dp[i - 1][j];
                else
                {

                    int not_take = dp[i - 1][j];
                    int take = INT_MAX;

                    if (j - (i + 1) >= 0)
                        take = cost[i] + dp[i][j - (i + 1)];

                    dp[i][j] = min(take, not_take);
                }
            }
        }

        int ways = dp[N - 1][W];
        return (ways >= 1e9 ? -1 : ways);
    }
};

// 3
// space optimised
class Solution
{

public:
    int minimumCost(int cost[], int N, int W)
    {
        vector<int> prev(W + 1, 0);

        for (int j = 0; j <= W; j++)
        {

            if (cost[0] != -1)
                prev[j] = j * cost[0];
            else
                prev[j] = 1e9;
        }

        prev[0] = 0;

        for (int i = 1; i < N; i++)
        {

            vector<int> temp(W + 1, 0);

            for (int j = 0; j <= W; j++)
            {

                // can not take.
                if (cost[i] == -1)
                    temp[j] = prev[j];
                else
                {

                    int not_take = prev[j];
                    int take = INT_MAX;

                    if (j - (i + 1) >= 0)
                        take = cost[i] + temp[j - (i + 1)];

                    temp[j] = min(take, not_take);
                }
            }

            prev = temp;
        }

        int ways = prev[W];
        return (ways >= 1e9 ? -1 : ways);
    }
};
