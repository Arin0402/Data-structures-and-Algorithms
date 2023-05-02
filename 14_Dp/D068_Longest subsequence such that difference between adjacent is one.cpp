#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

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

        if (prevInd == n || abs(arr[prevInd] - arr[ind]) == 1)
            take = 1 + helper(ind - 1, ind, n, arr, dp);

        return dp[ind][prevInd] = max(take, not_take);
    }

    int longestSubsequence(int N, int A[])
    {

        vector<vector<int>> dp(N, vector<int>(N + 1, -1));
        return helper(N - 1, N, N, A, dp);
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

        if (prevInd == n || abs(arr[prevInd] - arr[ind - 1]) == 1)
            take = 1 + helper(ind - 1, ind - 1, n, arr, dp);

        return dp[ind][prevInd] = max(take, not_take);
    }

    int longestSubsequence(int N, int A[])
    {

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

        return helper(N, N, N, A, dp);
    }
};

// 2
// tab
class Solution
{
public:
    int longestSubsequence(int N, int A[])
    {

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {

                int not_take = dp[i - 1][j];
                int take = 0;

                if (j == N || abs(A[j] - A[i - 1]) == 1)
                    take = 1 + dp[i - 1][i - 1];

                dp[i][j] = max(take, not_take);
            }
        }

        return dp[N][N];
    }
};

// 3
// space optimised
class Solution
{
public:
    int longestSubsequence(int N, int A[])
    {

        vector<int> prev(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {

            vector<int> temp(N + 1, 0);
            for (int j = 0; j <= N; j++)
            {

                int not_take = prev[j];
                int take = 0;

                if (j == N || abs(A[j] - A[i - 1]) == 1)
                    take = 1 + prev[i - 1];

                temp[j] = max(take, not_take);
            }

            prev = temp;
        }

        return prev[N];
    }
};