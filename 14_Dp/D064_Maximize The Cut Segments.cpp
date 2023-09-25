#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

// 1
// memo
// O(n)
// O(n) + O(n)
class Solution
{
public:
    int helper(int n, int x, int y, int z, vector<int> &dp)
    {

        if (n == 0)
            return 0;
        else if (n < x && n < y && n < z)
            return -1e9;

        if (dp[n] != -1)
            return dp[n];

        int choice1 = INT_MIN, choice2 = INT_MIN, choice3 = INT_MIN;

        if (x <= n)
            choice1 = 1 + helper(n - x, x, y, z, dp);
        if (y <= n)
            choice2 = 1 + helper(n - y, x, y, z, dp);
        if (z <= n)
            choice3 = 1 + helper(n - z, x, y, z, dp);

        return dp[n] = max(choice1, max(choice2, choice3));
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {

        vector<int> dp(n + 1, -1);
        int ways = helper(n, x, y, z, dp);

        return (ways >= 0 ? ways : 0);
    }
};

// 2
// tab
// O(n)
// O(n)
class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {

        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {

            int choice1 = INT_MIN, choice2 = INT_MIN, choice3 = INT_MIN;

            if (x <= i)
                choice1 = 1 + dp[i - x];
            if (y <= i)
                choice2 = 1 + dp[i - y];
            if (z <= i)
                choice3 = 1 + dp[i - z];

            dp[i] = max({choice1, choice2, choice3});
        }

        int ways = dp[n];
        return (ways >= 0 ? ways : 0);
    }
};