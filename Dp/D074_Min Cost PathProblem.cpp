#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

// 1
// memo
// O(n*n)
// O(n*n) + O(n)
class Solution
{
public:
    int helper(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {

        if (j < 0 || j >= m)
            return 0;
        if (i == n - 1)
            return mat[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int choice1 = helper(i + 1, j - 1, n, m, mat, dp);
        int choice2 = helper(i + 1, j, n, m, mat, dp);
        int choice3 = helper(i + 1, j + 1, n, m, mat, dp);

        return dp[i][j] = mat[i][j] + max({choice1, choice2, choice3});
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n = Matrix.size();
        int m = Matrix[0].size();

        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int j = 0; j < m; j++)
        {
            ans = max(ans, helper(0, j, n, m, Matrix, dp));
        }

        return ans;
    }
};

// 2
// tab
// O(n*n)
// O(n*n)
class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n = Matrix.size();
        int m = Matrix[0].size();

        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
            dp[n - 1][j] = Matrix[n - 1][j];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                int choice1 = 0, choice2 = 0, choice3 = 0;
                if (j - 1 >= 0)
                    choice1 = dp[i + 1][j - 1];
                choice2 = dp[i + 1][j];
                if (j + 1 < m)
                    choice3 = dp[i + 1][j + 1];

                dp[i][j] = Matrix[i][j] + max({choice1, choice2, choice3});
            }
        }

        for (int j = 0; j < m; j++)
        {
            ans = max(ans, dp[0][j]);
        }

        return ans;
    }
};

// 3
// space optimised

// O(n*n)
// O(2*n)
class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n = Matrix.size();
        int m = Matrix[0].size();

        int ans = 0;

        vector<int> prev(m, 0);

        for (int j = 0; j < m; j++)
            prev[j] = Matrix[n - 1][j];

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> temp(m, 0);

            for (int j = m - 1; j >= 0; j--)
            {

                int choice1 = 0, choice2 = 0, choice3 = 0;

                if (j - 1 >= 0)
                    choice1 = prev[j - 1];
                choice2 = prev[j];
                if (j + 1 < m)
                    choice3 = prev[j + 1];

                temp[j] = Matrix[i][j] + max({choice1, choice2, choice3});
            }

            prev = temp;
        }

        for (int j = 0; j < m; j++)
        {
            ans = max(ans, prev[j]);
        }

        return ans;
    }
};