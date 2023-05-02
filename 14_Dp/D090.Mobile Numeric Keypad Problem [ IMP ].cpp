#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

// 1
// memo
// O(n) (for loops are runiing for negligible number so consider O(n))
// O(n)
class Solution
{
public:
    long long helper(int i, int j, int count, int n, vector<vector<int>> &nums, vector<vector<vector<long long int>>> &dp)
    {

        if (nums[i][j] == -1)
            return 0;
        if (count == n)
            return 1;
        if (dp[i][j][count] != -1)
            return dp[i][j][count];

        int rows[5] = {0, -1, 0, 1, 0};
        int cols[5] = {0, 0, -1, 0, 1};

        long long int ways = 0;

        for (int k = 0; k < 5; k++)
        {

            int nrow = i + rows[k];
            int ncol = j + cols[k];

            if (nrow >= 0 && nrow < 4 && ncol >= 0 && ncol < 3 && nums[nrow][ncol] != -1)
            {
                ways += helper(nrow, ncol, count + 1, n, nums, dp);
            }
        }

        return dp[i][j][count] = ways;
    }

    long long getCount(int n)
    {
        vector<vector<int>> nums(4, vector<int>(3, -1));

        for (int i = 0; i < 3; i++)
        {
            nums[0][i] = i + 1;
            nums[1][i] = i + 4;
            nums[2][i] = i + 7;
        }

        nums[3][1] = 0;

        long long int count = 0;

        vector<vector<vector<long long int>>> dp(4, vector<vector<long long int>>(3, vector<long long int>(n + 1, -1)));

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                count += helper(i, j, 1, n, nums, dp);
            }
        }

        return count;
    }
};