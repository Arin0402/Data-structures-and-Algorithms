#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

// 1
// memo
// O(n*m)
// O(n*m) + O(n + m)
class Solution
{
public:
    bool helper(int i, int j, string &pattern, string &str, vector<vector<int>> &dp)
    {

        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (i >= 0 && j < 0)
        {

            for (int k = 0; k <= i; k++)
                if (pattern[k] != '*')
                    return false;

            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (pattern[i] == str[j] || pattern[i] == '?')
            return dp[i][j] = helper(i - 1, j - 1, pattern, str, dp);

        if (pattern[i] == '*')
            return dp[i][j] = helper(i - 1, j, pattern, str, dp) | helper(i, j - 1, pattern, str, dp);

        return dp[i][j] = false;
    }

    int wildCard(string pattern, string str)
    {

        int n = pattern.size();
        int m = str.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(n - 1, m - 1, pattern, str, dp);
    }
};

// 2
// tab
// O(n*m)
// O(n*m)
class Solution
{
public:
    int wildCard(string pattern, string str)
    {

        int n = pattern.size();
        int m = str.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++)
            dp[0][j] = false;

        for (int i = 1; i <= n; i++)
        {

            bool flag = true;

            for (int k = 1; k <= i; k++)
                if (pattern[k - 1] != '*')
                {
                    flag = false;
                    break;
                }

            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= m; j++)
            {

                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (pattern[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];

                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};

// 3
// 2D space optimised
// O(n*m)
// O(2*m)
class Solution
{
public:
    int wildCard(string pattern, string str)
    {

        int n = pattern.size();
        int m = str.size();

        vector<int> prev(m + 1, 0);

        prev[0] = true;

        for (int j = 1; j <= m; j++)
            prev[j] = false;

        for (int i = 1; i <= n; i++)
        {

            vector<int> temp(m + 1, 0);

            // ------Copied Portion from base case-------
            bool flag = true;
            for (int k = 1; k <= i; k++)
                if (pattern[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            temp[0] = flag;
            // ------Copied Portion from base case-------

            for (int j = 1; j <= m; j++)
            {

                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                    temp[j] = prev[j - 1];

                else if (pattern[i - 1] == '*')
                    temp[j] = prev[j] | temp[j - 1];

                else
                    temp[j] = false;
            }

            prev = temp;
        }

        return prev[m];
    }
};