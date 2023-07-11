#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

class Solution
{
    void dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<char>> &mat, int n, int m)
    {

        vis[r][c] = true;

        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {

            int nrow = r + rows[i];
            int ncol = c + cols[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol <= m && mat[nrow][ncol] == 'O' && vis[nrow][ncol] == false)
            {

                dfs(nrow, ncol, vis, mat, n, m);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {

        vector<vector<bool>> vis(n, vector<bool>(m, 0)); // visited.

        // top row and bottom row.
        for (int i = 0; i < m; i++)
        {

            // if we find O at the sides of the matrix, we will call the dfs.
            if (mat[0][i] == 'O' && vis[0][i] == false)
                dfs(0, i, vis, mat, n, m);
            if (mat[n - 1][i] == 'O' && vis[n - 1][i] == false)
                dfs(n - 1, i, vis, mat, n, m);
        }
        // left col and right col.
        for (int i = 0; i < n; i++)
        {

            if (mat[i][0] == 'O' && vis[i][0] == false)
                dfs(i, 0, vis, mat, n, m);
            if (mat[i][m - 1] == 'O' && vis[i][m - 1] == false)
                dfs(i, m - 1, vis, mat, n, m);
        }

        // The O's/X's are unvisited will be converted to X as they are surrounded by X from all the sides.
        // if they were not surrounded , then those O's would have been reached.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (vis[i][j] == false)
                    mat[i][j] = 'X';
                else
                    mat[i][j] = 'O';
            }
        }

        return mat;
    }
};