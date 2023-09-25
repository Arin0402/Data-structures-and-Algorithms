#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/assembly-line-scheduling/1

// 1
// memo
// this solution is giving segmentation fault error after clearing 1002 test cases.
// O(2*n)
// O(2*n) + O(n)

class Solution
{
public:
    // i and j represents lineNo. and station number.
    int helper(int i, int j, vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &x, int n, vector<vector<int>> &dp)
    {

        // reached the end;
        if (j == n)
            return x[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        // continue on the same line.
        int choice1 = helper(i, j + 1, a, T, x, n, dp);

        int choice2 = INT_MAX;

        if (j + 1 < n)
        {

            choice2 = T[i][j + 1];

            // switch
            if (i == 0)
                choice2 += helper(1, j + 1, a, T, x, n, dp);
            else
                choice2 += helper(0, j + 1, a, T, x, n, dp);
        }

        return dp[i][j] = a[i][j] + min(choice1, choice2);
    }

    int carAssembly(vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
    {

        int n = a[0].size();

        vector<vector<int>> dp(2, vector<int>(n, -1));

        int cost1 = e[0] + helper(0, 0, a, T, x, n, dp);
        int cost2 = e[1] + helper(1, 0, a, T, x, n, dp);

        return min(cost1, cost2);
    }
};

// 2
// tab
// O(2*n)
// O(2*n)
class Solution
{
public:
    // i and j represents lineNo. and station number.
    int carAssembly(vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
    {

        int n = a[0].size();

        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        dp[0][n] = x[0];
        dp[1][n] = x[1];

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 1; i >= 0; i--)
            {

                int choice1 = dp[i][j + 1];

                int choice2 = INT_MAX;

                if (j + 1 < n)
                {

                    choice2 = T[i][j + 1];

                    if (i == 0)
                        choice2 += dp[1][j + 1];
                    else
                        choice2 += dp[0][j + 1];
                }

                dp[i][j] = a[i][j] + min(choice1, choice2);
            }
        }

        return min(e[0] + dp[0][0], e[1] + dp[1][0]);
    }
};