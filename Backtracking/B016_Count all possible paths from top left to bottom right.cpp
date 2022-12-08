#include <bits/stdc++.h>
using namespace std;

// 1
// recursion
// exponential

// 2
// dp
// O(N*M)
class Solution
{
public:
    long long int helper(int row, int col, int n, int m, vector<vector<int>> &mat, vector<vector<long long int>> &dp)
    {

        if (row == n - 1 && col == m - 1)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        long long int cnt = 0;

        int rows[2] = {0, 1};
        int cols[2] = {1, 0};

        for (int i = 0; i < 2; i++)
        {

            int nrow = row + rows[i];
            int ncol = col + cols[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                cnt += helper(nrow, ncol, n, m, mat, dp) % 1000000007;
            }
        }

        dp[row][col] = cnt;

        return cnt;
    }
    long long int numberOfPaths(int m, int n)
    {

        vector<vector<int>> mat(m, vector<int>(n, 1));

        vector<vector<long long int>> dp(m, vector<long long int>(n, -1));

        return helper(0, 0, m, n, mat, dp) % 1000000007;
    }
};

// 3
// TC - O(N-1) or O(M-1)
// Sc - O(1)
// https://youtu.be/t_f0nwwdg5o?t=819