#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/triangle_1229398?leftPanelTab=0

// 1
// memo

class Solution
{
public:
    int helper(int row, int col, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {

        if (row == n - 1)
            return triangle[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int choice1 = triangle[row][col] + helper(row + 1, col, triangle, n, dp);
        int choice2 = triangle[row][col] + helper(row + 1, col + 1, triangle, n, dp);

        return dp[row][col] = min(choice1, choice2);
    }
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(0, 0, triangle, n, dp);
    }
};

// 2
// tab

class Solution
{
public:
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {

                int choice1 = 1e9, choice2 = 1e9;
                choice1 = triangle[i][j] + dp[i + 1][j];
                choice2 = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(choice1, choice2);
            }
        }

        return dp[0][0];
    }
};

// 3
// space optimised.

class Solution
{
public:
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {

        vector<int> prev(n, 0);

        for (int i = 0; i < n; i++)
        {
            prev[i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {

            vector<int> temp(n, 0);
            for (int j = i; j >= 0; j--)
            {

                int choice1 = 1e9, choice2 = 1e9;
                choice1 = triangle[i][j] + prev[j];
                choice2 = triangle[i][j] + prev[j + 1];

                temp[j] = min(choice1, choice2);
            }
            prev = temp;
        }

        return prev[0];
    }
};