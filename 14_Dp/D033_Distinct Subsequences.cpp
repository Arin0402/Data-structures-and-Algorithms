#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/distinct-subsequences/description/

// 1
// memo
// O(n*m)
// O(n*m) + O(n + m)

class Solution
{
public:
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {

        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = (helper(i - 1, j - 1, s, t, dp) + helper(i - 1, j, s, t, dp));

        return dp[i][j] = helper(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(n - 1, m - 1, s, t, dp);
    }
};

// 2
// tab
// O(n*m)
// O(n*m)

class Solution
{
public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();

        // using long long is giving overflow.
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        // we start from the index 1 as we cannot override the previous for loop's value
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        // type cast it back
        return (int)dp[n][m];
    }
};

// 3
// space optimised
// O(n*m)
// O(2*m)

class Solution
{
public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();

        vector<double> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {

            vector<double> temp(m + 1, 0);
            temp[0] = 1; // why ? , becuase we are runnig for loop for every row in base case, (see solution 2, line marked with /**/)

            for (int j = 1; j <= m; j++)
            {

                if (s[i - 1] == t[j - 1])
                    temp[j] = prev[j - 1] + prev[j];
                else
                    temp[j] = prev[j];
            }

            prev = temp;
        }

        return (int)prev[m];
    }
};

// 4
// 1D array optimisation

class Solution
{
public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();

        vector<double> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {

            // Reason for why start from back is given in the solution.
            for (int j = m; j >= 1; j--)
            {

                if (s[i - 1] == t[j - 1])
                    prev[j] = prev[j - 1] + prev[j];
            }
        }

        return (int)prev[m];
    }
};