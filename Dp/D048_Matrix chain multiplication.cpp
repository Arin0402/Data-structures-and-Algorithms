#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// memo
// O(n*n*n)
// O(n*n) + O(n)
class Solution
{
public:
    int helper(int i, int j, int arr[], vector<vector<int>> &dp)
    {

        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e9;

        for (int k = i; k < j; k++)
        {

            int steps = helper(i, k, arr, dp) + helper(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, steps);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(int N, int arr[])
    {

        vector<vector<int>> dp(N, vector<int>(N, -1));
        return helper(1, N - 1, arr, dp);
    }
};

// 2
// tab
// O(n*n*n)
// O(n*n)
class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {

        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {

                int mini = 1e9;

                for (int k = i; k < j; k++)
                {

                    int steps = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    mini = min(mini, steps);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][N - 1];
    }
};