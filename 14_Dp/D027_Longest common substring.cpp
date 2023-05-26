#include <bits/stdc++.h>
using namespace std;

// 1
// recursive

class Solution
{
public:
    int lcs(int i, int j, int &count, string &X, string &Y)
    {

        if (i < 0 || j < 0)
            return 0;

        int length = 0;

        if (X[i - 1] == Y[j - 1])
        {
            length = 1 + lcs(i - 1, j - 1, count, X, Y);
        }
        count = max(length,
                    max(lcs(i, j - 1, count, X, Y),
                        lcs(i - 1, j, count, X, Y)));
        return count;
    }

    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int count = 0;
        return lcs(n - 1, m - 1, count, S1, S2);
    }
};

// 2
// based on the longest common subsequence.
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;
        for (int j = 0; j <= n; j++)
            dp[j][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (S1[i - 1] == S2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;

                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};