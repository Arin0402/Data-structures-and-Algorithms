#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=UvksR0hR9nA
// https://www.youtube.com/watch?v=S49zeUjeUL0.
// Reason for maximum - watch pepcoding video

// 1
// memo
// O(N*(K^2))
// O(N*K) + O(n + k)
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int helper(int eggs, int floors, vector<vector<int>> &dp)
    {

        if (floors == 0 || floors == 1)
            return floors;
        if (eggs == 1)
            return floors;

        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int mini = INT_MAX;

        for (int i = 1; i <= floors; i++)
        {

            int not_broke = 1 + helper(eggs, floors - i, dp);
            int broke = 1 + helper(eggs - 1, i - 1, dp);

            int temp = max(not_broke, broke);

            mini = min(mini, temp);
        }

        return dp[eggs][floors] = mini;
    }

    int eggDrop(int n, int k)
    {

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(n, k, dp);
    }
};

// 2
// tab
// O(N*(K^2))
// O(N*K)
class Solution
{
public:
    int eggDrop(int n, int k)
    {

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][1] = 1;
        }

        for (int j = 0; j <= k; j++)
            dp[1][j] = j;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= k; j++)
            {

                int mini = INT_MAX;

                for (int x = 1; x <= j; x++)
                {

                    int not_broke = 1 + dp[i][j - x];
                    int broke = 1 + dp[i - 1][x - 1];

                    int temp = max(not_broke, broke);

                    mini = min(mini, temp);
                }

                dp[i][j] = mini;
            }
        }

        return dp[n][k];
    }
};