#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

// 1
// memo
class Solution
{
public:
    int helper(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp)
    {

        if (ind < 0)
            return 0;

        if (dp[ind][prevInd] != -1)
            return dp[ind][prevInd];

        int not_take = helper(ind - 1, prevInd, n, arr, dp);
        int take = 0;

        if (prevInd == n || arr[prevInd] > arr[ind])
            take = arr[ind] + helper(ind - 1, ind, n, arr, dp);

        return dp[ind][prevInd] = max(take, not_take);
    }
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(n - 1, n, n, arr, dp);
    }
};

// OR

class Solution
{
public:
    int helper(int ind, int prevInd, int n, int arr[], vector<vector<int>> &dp)
    {

        if (ind == 0)
            return 0;

        if (dp[ind][prevInd] != -1)
            return dp[ind][prevInd];

        int not_take = helper(ind - 1, prevInd, n, arr, dp);
        int take = 0;

        if (prevInd == n || arr[prevInd] > arr[ind - 1])
            take = arr[ind - 1] + helper(ind - 1, ind - 1, n, arr, dp);

        return dp[ind][prevInd] = max(take, not_take);
    }
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return helper(n, n, n, arr, dp);
    }
};

// 2
// tab
class Solution
{
public:
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {

                int not_take = dp[i - 1][j];
                int take = 0;

                if (j == n || arr[j] > arr[i - 1])
                    take = arr[i - 1] + dp[i - 1][i - 1];

                dp[i][j] = max(take, not_take);
            }
        }

        return dp[n][n];
    }
};

// 3
// space optimised
class Solution
{
public:
    int maxSumIS(int arr[], int n)
    {

        vector<int> prev(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {

            vector<int> temp(n + 1, 0);
            for (int j = 0; j <= n; j++)
            {

                int not_take = prev[j];
                int take = 0;

                if (j == n || arr[j] > arr[i - 1])
                    take = arr[i - 1] + prev[i - 1];

                temp[j] = max(take, not_take);
            }
            prev = temp;
        }

        return prev[n];
    }
};