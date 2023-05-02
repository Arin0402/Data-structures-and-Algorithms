#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/coin-change2448/1

// 1
// memo
// O(n*sum)
// O(n*sum) + O(n + sum);

class Solution
{
public:
    long long int helper(int ind, int sum, int coins[], vector<vector<long long int>> &dp)
    {

        if (sum == 0)
            return 1;
        if (ind < 0)
        {
            return sum == 0;
        }

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        long long int not_take = helper(ind - 1, sum, coins, dp);
        long long int take = 0;

        if (coins[ind] <= sum)
            take = helper(ind, sum - coins[ind], coins, dp);

        return dp[ind][sum] = take + not_take;
    }

    long long int count(int coins[], int N, int sum)
    {

        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, -1));
        return helper(N - 1, sum, coins, dp);
    }
};

// 2
// tab
// O(n*sum)
// O(n*sum)
class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {

        vector<vector<long long int>> dp(N + 1, vector<long long int>(sum + 1, 0));

        for (int i = 0; i < N; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {

                long long int not_take = dp[i - 1][j];
                long long int take = 0;

                if (coins[i - 1] <= j)
                    take = dp[i][j - coins[i - 1]];

                dp[i][j] = take + not_take;
            }
        }

        return dp[N][sum];
    }
};

// 3
// space optimised
// O(n*sum)
// O(2*sum)
class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {

        vector<long long int> prev(sum + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= N; i++)
        {

            vector<long long int> temp(sum + 1, 0);
            temp[0] = 1;

            for (int j = 1; j <= sum; j++)
            {

                long long int not_take = prev[j];
                long long int take = 0;

                if (coins[i - 1] <= j)
                    take = temp[j - coins[i - 1]];

                temp[j] = take + not_take;
            }

            prev = temp;
        }

        return prev[sum];
    }
};
