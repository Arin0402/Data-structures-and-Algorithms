#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?leftPanelTab=0

// 1
// memo
// top down
// O(n*m*m)*9 -> https://youtu.be/QGfn7JeXK54?t=1364
// O(n*m*m) + O(n)

class Solution
{
public:
    int helper(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {

        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
            return 0;
        if (i == r - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = INT_MIN;
        for (int a = -1; a < 2; a++)
        {
            for (int b = -1; b < 2; b++)
            {

                int chocolates = INT_MIN;
                if (j1 == j2)
                    chocolates = grid[i][j1] + helper(i + 1, j1 + a, j2 + b, r, c, grid, dp);
                else
                    chocolates = grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + a, j2 + b, r, c, grid, dp);
                maxi = max(maxi, chocolates);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    int maximumChocolates(int r, int c, vector<vector<int>> &grid)
    {

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        return helper(0, 0, c - 1, r, c, grid, dp);
    }
};

// 2
// tab
// bottom up
// O(n*m*m)*9
// O(n*m*m)
class Solution
{
public:
    int maximumChocolates(int r, int c, vector<vector<int>> &grid)
    {

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        // base case.
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {

                if (j1 == j2)
                    dp[r - 1][j1][j2] = grid[r - 1][j1];
                else
                    dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        for (int i = r - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < c; j1++)
            {
                for (int j2 = 0; j2 < c; j2++)
                {

                    int maxi = INT_MIN;
                    for (int a = -1; a < 2; a++)
                    {
                        for (int b = -1; b < 2; b++)
                        {

                            int chocolates = INT_MIN;
                            if (j1 + a >= 0 && j1 + a < c && j2 + b >= 0 && j2 + b < c)
                            {
                                if (j1 == j2)
                                    chocolates = grid[i][j1] + dp[i + 1][j1 + a][j2 + b];
                                else
                                    chocolates = grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + a][j2 + b];
                            }
                            maxi = max(maxi, chocolates);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][c - 1];
    }
};

// 3
// space optimised
// O(n*m*m)*9
// O(2*m*m)

class Solution
{
public:
    int maximumChocolates(int r, int c, vector<vector<int>> &grid)
    {

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        vector<vector<int>> prev(c, vector<int>(c, -1));

        // base case.
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {

                if (j1 == j2)
                    prev[j1][j2] = grid[r - 1][j1];
                else
                    prev[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        for (int i = r - 2; i >= 0; i--)
        {

            vector<vector<int>> temp(c, vector<int>(c, -1));
            for (int j1 = 0; j1 < c; j1++)
            {
                for (int j2 = 0; j2 < c; j2++)
                {

                    int maxi = INT_MIN;
                    for (int a = -1; a < 2; a++)
                    {
                        for (int b = -1; b < 2; b++)
                        {

                            int chocolates = INT_MIN;
                            if (j1 + a >= 0 && j1 + a < c && j2 + b >= 0 && j2 + b < c)
                            {
                                if (j1 == j2)
                                    chocolates = grid[i][j1] + prev[j1 + a][j2 + b];
                                else
                                    chocolates = grid[i][j1] + grid[i][j2] + prev[j1 + a][j2 + b];
                            }
                            maxi = max(maxi, chocolates);
                        }
                    }

                    temp[j1][j2] = maxi;
                }
            }

            prev = temp;
        }

        return prev[0][c - 1];
    }
};
