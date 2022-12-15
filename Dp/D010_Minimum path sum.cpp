#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/

// 1
// memo
// O(n*m)
// (n*m) + O(n-1 + m-1)

class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {

        if (row == 0 && col == 0)
            return grid[row][col];
        if (row < 0 || col < 0)
            return 1e9;

        if (dp[row][col] != -1)
            return dp[row][col];

        int right = grid[row][col] + helper(row, col + 1, grid, dp);
        int down = grid[row][col] + helper(row + 1, col, grid, dp);

        return dp[row][col] = min(right, down);
    }

    int minPathSum(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(0, 0, grid, dp);
    }
};

// 2
// tab
// o(n*m)
// O(n*m)

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {

                    int left = 1e9, upper = 1e9;
                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];
                    if (i > 0)
                        upper = grid[i][j] + dp[i - 1][j];

                    dp[i][j] = min(left, upper);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

// 3
// optimised
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, -1);

        for (int i = 0; i < n; i++)
        {

            vector<int> temp(m, -1);
            for (int j = 0; j < m; j++)
            {

                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else
                {

                    int left = 1e9, upper = 1e9;
                    if (j > 0)
                        left = grid[i][j] + temp[j - 1];
                    if (i > 0)
                        upper = grid[i][j] + prev[j];

                    temp[j] = min(left, upper);
                }
            }

            prev = temp;
        }

        return prev[m - 1];
    }
};