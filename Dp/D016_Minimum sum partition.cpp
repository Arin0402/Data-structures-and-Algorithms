#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// memo
class Solution
{

public:
    int helper(int ind, int sum1, int sum2, int arr[], vector<vector<int>> &dp)
    {

        if (ind < 0)
        {
            return abs(sum1 - sum2);
        }

        if (dp[ind][sum1] != -1)
            return dp[ind][sum1];

        int choice1 = 1e9, choice2 = 1e9;

        choice1 = helper(ind - 1, sum1 + arr[ind], sum2, arr, dp);
        choice2 = helper(ind - 1, sum1, sum2 + arr[ind], arr, dp);

        return dp[ind][sum1] = min(choice1, choice2);
    }

    int minDifference(int arr[], int n)
    {

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return helper(n - 1, 0, 0, arr, dp);
    }
};

// 2
// tab
// watch video for explanation.

class Solution
{

public:
    int minDifference(int arr[], int n)
    {

        int target = 0;
        for (int i = 0; i < n; i++)
            target += arr[i];

        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        // if element is greater than target then not possible.
        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {

                bool not_take = dp[i - 1][j];
                bool take = false;
                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = (take | not_take);
            }
        }

        int ans = 1e9;

        for (int i = 0; i <= target / 2; i++)
        {

            if (dp[n - 1][i] == true)
                ans = min(ans, abs(target - i - i));
        }

        return ans;
    }
};