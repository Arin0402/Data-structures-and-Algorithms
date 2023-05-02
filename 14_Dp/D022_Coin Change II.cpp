#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change-ii/description/

// 1
// memo
// O(n*amount)
// O(n*amount) + O(amount);
class Solution
{
public:
    int helper(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (amount % coins[0] == 0)
                return 1;
            return 0;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int not_take = helper(ind - 1, amount, coins, dp);
        int take = 0;
        if (coins[ind] <= amount)
            take = helper(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = take + not_take;
    }

    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1, amount, coins, dp);
    }
};

// 2
// tab
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {

                int not_take = dp[i - 1][j];
                int take = 0;
                if (coins[i] <= j)
                    take = dp[i][j - coins[i]];
                dp[i][j] = take + not_take;
            }
        }

        return dp[n - 1][amount];
    }
};

// 3
// space optimised
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();

        vector<int> prev(amount + 1, 0);

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = 1;
            else
                prev[i] = 0;
        }

        for (int i = 1; i < n; i++)
        {

            vector<int> temp(amount + 1, 0);
            for (int j = 0; j <= amount; j++)
            {

                int not_take = prev[j];
                int take = 0;
                if (coins[i] <= j)
                    take = temp[j - coins[i]];
                temp[j] = take + not_take;
            }

            prev = temp;
        }

        return prev[amount];
    }
};