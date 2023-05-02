#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

// 1
// memo
// TLE
// O(N*N*2)
class Solution
{
public:
    int helper(int ind, int prev, int condition, vector<int> &nums, int n, vector<vector<vector<int>>> &dp)
    {

        if (ind == 0)
            return 0;
        if (dp[ind][prev][condition] != -1)
            return dp[ind][prev][condition];

        int not_take = helper(ind - 1, prev, condition, nums, n, dp);

        int take = 0;
        if (condition == 1)
        {
            if (prev == n || nums[ind - 1] > nums[prev])
                take = 1 + helper(ind - 1, ind - 1, 0, nums, n, dp);
        }
        else
        {
            if (prev == n || nums[ind - 1] < nums[prev])
                take = 1 + helper(ind - 1, ind - 1, 1, nums, n, dp);
        }

        return dp[ind][prev][condition] = max(take, not_take);
    }

    int AlternatingaMaxLength(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        int choice1 = helper(n, n, 1, nums, n, dp);
        int choice2 = helper(n, n, 0, nums, n, dp);

        return max(choice1, choice2);
    }
};

// 2
// tab
// TLE
// O(N*N*2)
// NOTE - observe one thing in this solution.
class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        // no base case conditions and default value is zero.

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k < 2; k++)
                {

                    int not_take = dp[i - 1][j][k]; // can eliminate j

                    int take = 0;
                    if (k == 1)
                    {
                        if (j == n || nums[i - 1] > nums[j])
                            take = 1 + dp[i - 1][i - 1][0]; // here we are not required j
                    }
                    else
                    {
                        if (j == n || nums[i - 1] < nums[j])
                            take = 1 + dp[i - 1][i - 1][1]; // here we are not required j
                    }

                    dp[i][j][k] = max(take, not_take); // can eliminate j
                }
            }
        }

        int choice1 = dp[n][n][1];
        int choice2 = dp[n][n][0];

        return max(choice1, choice2);
    }
};

// 3
// O(N*2)
// Mine optimised solution
class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &nums)
    {

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int k = 0; k < 2; k++)
            {

                int not_take = dp[i - 1][k];

                int take = 0;
                if (k == 1)
                {
                    if (i == n || nums[i - 1] > nums[i])
                        take = 1 + dp[i - 1][0];
                }
                else
                {
                    if (i == n || nums[i - 1] < nums[i])
                        take = 1 + dp[i - 1][1];
                }

                dp[i][k] = max(take, not_take);
            }
        }

        int choice1 = dp[n][1];
        int choice2 = dp[n][0];

        return max(choice1, choice2);
    }
};

// 4
// Efficient solution
// o(N)
// https://youtu.be/UogHvfQ3e18?t=853
class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &nums)
    {

        int n = nums.size();
        int ma = 1;
        int mi = 1;

        for (int i = 1; i < n; i++)
        {

            if (nums[i] > nums[i - 1])
            {
                ma = mi + 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                mi = ma + 1;
            }
        }

        return max(mi, ma);
    }
};