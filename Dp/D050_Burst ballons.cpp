#include <bits/stdc++.h>
using namespace std;

// 1
// memo
// O(n*n*n)
// O(n*n) + O(n)
class Solution
{
public:
    int helper(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;

        for (int ind = i; ind <= j; ind++)
        {

            int val = arr[i - 1] * arr[ind] * arr[j + 1] + helper(i, ind - 1, arr, dp) + helper(ind + 1, j, arr, dp);

            maxi = max(maxi, val);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(int N, vector<int> &arr)
    {

        arr.push_back(1);
        arr.insert(arr.begin(), 1);

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

        return helper(1, N, arr, dp);
    }
};

// 2
// tab
// O(n*n*n)
// O(n*n)
class Solution
{
public:
    int maxCoins(int N, vector<int> &arr)
    {

        arr.push_back(1);
        arr.insert(arr.begin(), 1);

        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));

        for (int i = N; i >= 1; i--)
        {
            for (int j = i; j <= N; j++)
            {

                int maxi = INT_MIN;

                for (int ind = i; ind <= j; ind++)
                {

                    int val = arr[i - 1] * arr[ind] * arr[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];

                    maxi = max(maxi, val);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][N];
    }
};