#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=0

// 1
// Recursion
// O(2^(m*n))

// 2
// memo
// O(m*n)
// O(m*n) + O(m-1 + n-1) (stack space)

class Solution
{

public:
    int helper(int row, int col, int m, int n, vector<vector<int>> &dp)
    {

        if (row >= m || col >= n)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];

        if (row == m - 1 && col == n - 1)
            return 1;

        int right = helper(row, col + 1, m, n, dp);
        int down = helper(row + 1, col, m, n, dp);

        return dp[row][col] = right + down;
    }

    int uniquePaths(int m, int n)
    {

        vector<vector<int>> mat(m, vector<int>(n, -1));
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(0, 0, m, n, dp);
    }
};

// 2
// tab
// O(m*n)
// O(m*n)

class Soluiton
{

public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (i == 0 && j == 0)
                    dp[0][0] = 1;
                else
                {

                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

// 3
// optimised
// O(m*n)
// O(2*n)

class Solution
{

public:
    int uniquePaths(int m, int n)
    {

        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {

            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {

                if (i == 0 && j == 0)
                    temp[0] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = temp[j - 1];

                    temp[j] = up + left;
                }
            }
            prev = temp;
        }

        return prev[n - 1];
    }
};
