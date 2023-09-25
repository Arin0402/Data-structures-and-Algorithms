#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

// 1
// memo

class Solution
{

public:
    int helper(int row, int col, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {

        if (col < 0 || col >= m)
            return -1e9;
        if (row == 0)
            return matrix[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int choice1 = matrix[row][col] + helper(row - 1, col - 1, m, matrix, dp);
        int choice2 = matrix[row][col] + helper(row - 1, col, m, matrix, dp);
        int choice3 = matrix[row][col] + helper(row - 1, col + 1, m, matrix, dp);

        return dp[row][col] = max({choice1, choice2, choice3});
    }

    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = -1e9;
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, helper(n - 1, i, m, matrix, dp));
        }

        return ans;
    }
};

// 2
// tab

class Solution
{

public:
    int getMaxPathSum(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < m; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int choice1 = -1e8, choice2 = -1e8, choice3 = -1e8;
                if (j - 1 >= 0)
                    choice1 = matrix[i][j] + dp[i - 1][j - 1];

                choice2 = matrix[i][j] + dp[i - 1][j];
                
                if (j + 1 < m)
                    choice3 = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = max({choice1, choice2, choice3});
            }
        }

        int ans = -1e9;

        for (int i = 0; i < m; i++)
        {
            ans = max(ans, dp[n - 1][i]);
        }

        return ans;
    }
};

// 3
// space optimised

class Solution
{

public:
    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, -1);

        for (int i = 0; i < m; i++)
        {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {

            vector<int> temp(m, -1);
            for (int j = 0; j < m; j++)
            {

                int choice1 = -1e8, choice2 = -1e8, choice3 = -1e8;
                if (j - 1 >= 0)
                    choice1 = matrix[i][j] + prev[j - 1];
                choice2 = matrix[i][j] + prev[j];
                if (j + 1 < m)
                    choice3 = matrix[i][j] + prev[j + 1];

                temp[j] = max({choice1, choice2, choice3});
            }

            prev = temp;
        }

        int ans = -1e9;

        for (int i = 0; i < m; i++)
        {
            ans = max(ans, prev[i]);
        }

        return ans;
    }
};