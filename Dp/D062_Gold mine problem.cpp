#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// memo
class Solution
{
public:
    int helper(int i, int j, int n, int m, vector<vector<int>> M, vector<vector<int>> &dp)
    {

        if (i < 0 || j < 0 || i >= n || j >= m)
            return 0;
        if (j == m - 1)
            return M[i][m - 1];

        if (dp[i][j] != -1)
            return dp[i][j];

        int gold = M[i][j] + max({helper(i - 1, j + 1, n, m, M, dp),
                                  helper(i, j + 1, n, m, M, dp),
                                  helper(i + 1, j + 1, n, m, M, dp)});

        return dp[i][j] = gold;
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {

        int maxi = -1e9;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, helper(i, 0, n, m, M, dp));
        }

        return maxi;
    }
};

// 2
// tab
class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][m - 1] = M[i][m - 1];
        }

        // NOTICE here that column loop is outside and row loop is inside
        for (int j = m - 2; j >= 0; j--)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                int leftup = 0;
                int left = 0;
                int leftdown = 0;

                if (i - 1 >= 0 && j + 1 < m)
                    leftup = dp[i - 1][j + 1];

                if (j + 1 < m)
                    left = dp[i][j + 1];

                if (i + 1 < n && j + 1 < m)
                    leftdown = dp[i + 1][j + 1];

                int gold = M[i][j] + max({leftup, left, leftdown});

                dp[i][j] = gold;
            }
        }

        int ans = -1e9;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};
