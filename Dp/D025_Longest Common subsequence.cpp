#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/description/

// 1
// memo
// O(n*m)
// O(n*m) + O(n + m)
class Solution
{
public:
    int helper(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
    {

        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (text1[ind1] == text2[ind2])
            return dp[ind1][ind2] = 1 + helper(ind1 - 1, ind2 - 1, text1, text2, dp);
        else
            return dp[ind1][ind2] = max(helper(ind1 - 1, ind2, text1, text2, dp), helper(ind1, ind2 - 1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(n - 1, m - 1, text1, text2, dp);
    }
};

// 2
// tab
// O(n*m)
// O(n*m)
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;
        for (int j = 0; j <= n; j++)
            dp[j][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
};

// 3
// space optimization.
// O(n*m)
// O(2*m)
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0);

        for (int i = 0; i <= m; i++)
            prev[i] = 0;

        for (int i = 1; i <= n; i++)
        {

            vector<int> temp(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {

                if (text1[i - 1] == text2[j - 1])
                    temp[j] = 1 + prev[j - 1];
                else
                    temp[j] = max(temp[j - 1], prev[j]);
            }

            prev = temp;
        }

        return prev[m];
    }
};