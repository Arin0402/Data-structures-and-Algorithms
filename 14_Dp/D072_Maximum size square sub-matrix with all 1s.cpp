#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

// 1
// memo
class Solution
{
public:
    int helper(int i, int j, int &maxi, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {

        if (i >= mat.size() || j >= mat[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = helper(i, j + 1, maxi, mat, dp);
        int diagonal = helper(i + 1, j + 1, maxi, mat, dp);
        int down = helper(i + 1, j, maxi, mat, dp);

        if (mat[i][j] == 1)
        {
            int ans = 1 + min({right, diagonal, down});
            maxi = max(maxi, ans);
            return dp[i][j] = ans;
        }
        else
            return dp[i][j] = 0;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {

        int maxi = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        helper(0, 0, maxi, mat, dp);

        return maxi;
    }
};

// 2
// tab
class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {

        int maxi = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (mat[i][j] == 1)
                {
                    int ans = 1 + min({right, diagonal, down});
                    maxi = max(maxi, ans);
                    dp[i][j] = ans;
                }
            }
        }

        return maxi;
    }
};

// 3
// space optimised
class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {

        int maxi = 0;
        vector<int> prev(m + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            vector<int> temp(m + 1, 0);
            for (int j = m - 1; j >= 0; j--)
            {

                int right = temp[j + 1];
                int diagonal = prev[j + 1];
                int down = prev[j];

                if (mat[i][j] == 1)
                {
                    int ans = 1 + min({right, diagonal, down});
                    maxi = max(maxi, ans);
                    temp[j] = ans;
                }
            }

            prev = temp;
        }

        return maxi;
    }
};