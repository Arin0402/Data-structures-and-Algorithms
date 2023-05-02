#include <bits/stdc++.h>
using namespace std;

// 1
// recursion
// O(2^n);
// stack space.
class Solution
{
public:
    int helper(int p1, int p2, int x, int y, string &s1, string &s2)
    {

        if (p1 == x)
            return 0;
        if (p2 == y)
            return 0;

        if (s1[p1] == s2[p2])
            return 1 + helper(p1 + 1, p2 + 1, x, y, s1, s2);
        else
            return max(helper(p1 + 1, p2, x, y, s1, s2), helper(p1, p2 + 1, x, y, s1, s2));
    }

    int lcs(int x, int y, string s1, string s2)
    {
        return helper(0, 0, x, y, s1, s2);
    }
};

// 2
// memoization
// O(m *n)
class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int helper(int p1, int p2, int x, int y, string &s1, string &s2, vector<vector<int>> &dp)
    {

        if (p1 == x)
            return 0;
        if (p2 == y)
            return 0;

        if (dp[p1][p2] != -1)
            return dp[p1][p2];

        if (s1[p1] == s2[p2])
            return dp[p1][p2] = 1 + helper(p1 + 1, p2 + 1, x, y, s1, s2, dp);
        else
            return dp[p1][p2] = max(helper(p1 + 1, p2, x, y, s1, s2, dp), helper(p1, p2 + 1, x, y, s1, s2, dp));
    }

    int lcs(int x, int y, string s1, string s2)
    {

        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return helper(0, 0, x, y, s1, s2, dp);
    }
};

// 3
// tabulation
// O(m*n)
class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x + 1][y + 1];

        for (int i = 0; i <= x; i++)
        {

            for (int j = 0; j <= y; j++)
            {

                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[x][y];
    }
};
