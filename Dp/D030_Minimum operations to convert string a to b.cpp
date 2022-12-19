#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

// str1 length - n
// str2 length - m

// find lcs of both string - (length = k).

// number of deletions = n - k
// number of insertitions = m - k
// total operations = n + m - 2*k

class Solution
{

public:
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

    int minOperations(string str1, string str2)
    {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return n + m - 2 * helper(n - 1, m - 1, str1, str2, dp);
    }
};
