#include <bits/stdc++.h>
using namespace std;

// find the largest palindromic subsequence in the given string.
// subtract it from the string size.

class Solution
{
public:
    // largest palindromic subsequence code.
    int helper(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
    {

        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (str1[ind1] == str2[ind2])
            return dp[ind1][ind2] = 1 + helper(ind1 - 1, ind2 - 1, str1, str2, dp);

        return dp[ind1][ind2] = max(helper(ind1, ind2 - 1, str1, str2, dp), helper(ind1 - 1, ind2, str1, str2, dp));
    }

    int countMin(string str)
    {

        int n = str.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        string str1 = str;

        reverse(str.begin(), str.end());

        return n - helper(n - 1, n - 1, str, str1, dp);
    }
};
