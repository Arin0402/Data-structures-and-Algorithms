#include <bits/stdc++.h>
using namespace std;

// Plain DFS
// TC - O(3^(n*m))
// SC - (n*m) stack space.

class Solution
{
public:
    void helper(int steps, int &maxSteps, int xs, int ys, int xd, int yd, vector<vector<int>> &matrix, int n, int m)
    {

        if (xs == xd && ys == yd)
        {
            maxSteps = max(maxSteps, steps);
            return;
        }

        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {

            int nrow = xs + rows[i];
            int ncol = ys + cols[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == 1)
            {

                matrix[nrow][ncol] = 2;
                helper(steps + 1, maxSteps, nrow, ncol, xd, yd, matrix, n, m);

                matrix[nrow][ncol] = 1;
            }
        }
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int maxSteps = -1;

        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0)
            return -1;

        int n = matrix.size();
        int m = matrix[0].size();

        matrix[xs][ys] = 2;

        helper(0, maxSteps, xs, ys, xd, yd, matrix, n, m);

        return maxSteps;
    }
};