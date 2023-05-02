#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// memo
// O(n*target)
// O(n*target) + O(n);
class Solution
{
public:
    bool helper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (target == 0)
            return true;
        if (ind == 0)
            return (arr[0] == target);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool not_take = helper(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = helper(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (take | not_take);
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return helper(n - 1, sum, arr, dp);
    }
};

// 2
// tab
// O(n*target)
// O(n*target)
class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int target)
    {

        int n = arr.size();

        // make sure to change -1 to 0 in dp for tabulation.
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

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

        return dp[n - 1][target];
    }
};

// 3
// space optimised
// O(n*target)
// O(2*target);
class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int target)
    {

        int n = arr.size();

        // make sure to change -1 to 0 in dp for tabulation.
        vector<int> prev(target + 1, 0);

        // This case is important.
        prev[0] = true;

        if (arr[0] <= target)
            prev[arr[0]] = true;

        for (int i = 1; i < n; i++)
        {

            vector<int> temp(target + 1, 0);

            for (int j = 1; j <= target; j++)
            {

                bool not_take = prev[j];
                bool take = false;
                if (arr[i] <= j)
                    take = prev[j - arr[i]];

                temp[j] = (take | not_take);
            }

            prev = temp;
        }

        return prev[target];
    }
};