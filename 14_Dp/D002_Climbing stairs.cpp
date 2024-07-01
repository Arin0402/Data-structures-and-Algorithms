#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/climbing-stairs/description/

// 1
// memo
// TC - O(N)
// SC - O(N) + O(N)(stack space)

class Solution
{
public:
    long long int helper(long long int n, long long int dp[])
    {

        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = (helper(n - 1, dp) % 1000000007 + helper(n - 2, dp) % 1000000007) % 1000000007;
    }

    long long int nthFibonacci(long long int n)
    {

        long long int dp[n + 1];
        memset(dp, -1, sizeof dp);

        return helper(n, dp);
    }
};

// 2
// Tabulation
// O(N)
// O(N)
class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {

        long long int dp[n + 1];
        memset(dp, -1, sizeof dp);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {

            dp[i] = (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007) % 1000000007;
        }

        return dp[n];
    }
};

// 3
// optimised
// O(N)
// O(1)

class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {

        int prev1 = 1;
        int prev2 = 1;

        int num;

        for (int i = 2; i <= n; i++)
        {

            num = (prev1 % 1000000007 + prev2 % 1000000007) % 1000000007;
            prev2 = prev1;
            prev1 = num;
        }

        return num;
    }
};
