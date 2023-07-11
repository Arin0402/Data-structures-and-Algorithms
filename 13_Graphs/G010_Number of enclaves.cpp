#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

class Solution
{

public:
    void dfs(int r, int c, vector<vector<int>> &grid, int n, int m)
    {

        // convert land to water.
        grid[r][c] = 0;

        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {

            int nrow = r + rows[i];
            int ncol = c + cols[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
            {

                dfs(nrow, ncol, grid, n, m);
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        // top row and bottom row.
        for (int i = 0; i < m; i++)
        {

            // if we find 1 at the sides of the matrix, we will call the dfs.
            if (grid[0][i] == 1)
                dfs(0, i, grid, n, m);
            if (grid[n - 1][i] == 1)
                dfs(n - 1, i, grid, n, m);
        }

        // left col and right col.
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, n, m);
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid, n, m);
        }

        int count = 0;

        // count the remaining lands
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};