#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// 1
// memo
// O(n*n)
// O(n*n) + O(n)
// my solution
class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    int helper(int ind, int prevInd, int n, int a[], vector<vector<int>> &dp)
    {

        if (ind < 0)
            return 0;

        if (dp[ind][prevInd] != -1)
            return dp[ind][prevInd];

        int not_take = helper(ind - 1, prevInd, n, a, dp);
        int take = 0;

        if (prevInd == n || a[prevInd] > a[ind])
            take = 1 + helper(ind - 1, ind, n, a, dp);

        return dp[ind][prevInd] = max(take, not_take);
    }

    int longestSubsequence(int n, int a[])
    {

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(n - 1, n, n, a, dp);
    }
};

// OR
class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    int helper(int ind, int prevInd, int n, int a[], vector<vector<int>> &dp)
    {

        if (ind == 0)
            return 0;

        if (dp[ind][prevInd] != -1)
            return dp[ind][prevInd];

        int not_take = helper(ind - 1, prevInd, n, a, dp);
        int take = 0;

        if (prevInd == n || a[prevInd] > a[ind - 1])
            take = 1 + helper(ind - 1, ind - 1, n, a, dp);

        return dp[ind][prevInd] = max(take, not_take);
    }

    int longestSubsequence(int n, int a[])
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        return helper(n, n, n, a, dp);
    }
};

// memo (second solution (striver))
// striver's solution is complicated
// giving TLE as we are creating dp table of size 10^5 * 10^5 ( see problem constraints)
class Solution
{
public:
    int helper(int ind, int prevInd, int n, int a[], vector<vector<int>> dp)
    {

        if (ind == n)
            return 0;

        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        int not_take = helper(ind + 1, prevInd, n, a, dp);

        int take = 0;

        if (prevInd == -1 || a[prevInd] < a[ind])
        {

            take = 1 + helper(ind + 1, ind, n, a, dp);
        }

        return dp[ind][prevInd + 1] = max(take, not_take);
    }

    int longestSubsequence(int n, int a[])
    {

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(0, -1, n, a, dp);
    }
};

// 2
// O(n*n)
// O(n*n)
// my solution

class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    int longestSubsequence(int n, int a[])
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {

                int not_take = dp[i - 1][j];
                int take = 0;

                if (j == n || a[j] > a[i - 1])
                    take = 1 + dp[i - 1][i - 1];

                dp[i][j] = max(take, not_take);
            }
        }

        return dp[n][n];
    }
};

// tab(striver's solution)
// complicated
class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {

                int not_take = dp[i + 1][j + 1];

                int take = 0;

                if (j == -1 || a[j] < a[i])
                {

                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][j + 1] = max(take, not_take);
            }
        }

        return dp[0][-1 + 1];
    }
};

// 3
// O(n*n)
// O(2*n)
// my solution
class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    int longestSubsequence(int n, int a[])
    {
        vector<int> prev(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {

            vector<int> temp(n + 1, 0);
            for (int j = 0; j <= n; j++)
            {

                int not_take = prev[j];
                int take = 0;

                if (j == n || a[j] > a[i - 1])
                    take = 1 + prev[i - 1];

                temp[j] = max(take, not_take);
            }

            prev = temp;
        }

        return prev[n];
    }
};

// striver's solution
class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {

        vector<int> prev(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            vector<int> temp(n + 1, 0);
            for (int j = i - 1; j >= -1; j--)
            {

                int not_take = prev[j + 1];

                int take = 0;

                if (j == -1 || a[j] < a[i])
                {

                    take = 1 + prev[i + 1];
                }

                temp[j + 1] = max(take, not_take);
            }

            prev = temp;
        }

        return prev[-1 + 1];
    }
};

// 4
// using binary search
// O(nlogn)
// O(n)
class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {

            int ind = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();

            if (ind >= ans.size())
                ans.push_back(a[i]);
            else
                ans[ind] = a[i];
        }

        return ans.size();
    }
};
