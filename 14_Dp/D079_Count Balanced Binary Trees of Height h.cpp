#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
// https://practice.geeksforgeeks.org/problems/bbt-counter4914/1
// youtube.com/watch?v=pyO2FJE7G9o

// 1
// memo

class Solution
{
public:
    long long int helper(int h, vector<long long int> &dp)
    {

        if (h == 0 || h == 1)
            return 1;

        if (dp[h] != -1)
            return dp[h];

        return dp[h] = ((2 * helper(h - 1, dp) * helper(h - 2, dp)) % MOD + (helper(h - 1, dp) * helper(h - 1, dp)) % MOD + MOD) % MOD;
    }
    long long int countBT(int h)
    {

        vector<long long int> dp(h + 1, -1);
        return helper(h, dp);
    }
};

// 2
// tab
class Solution
{
public:
    long long int countBT(int h)
    {

        vector<long long int> dp(h + 1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= h; i++)
        {
            dp[i] = ((2 * dp[i - 1] * dp[i - 2]) % MOD + (dp[i - 1] * dp[i - 1]) % MOD + MOD) % MOD;
        }

        return dp[h];
    }
};

// 3
class Solution
{
public:
    long long int countBT(int h)
    {

        long long int prev2 = 1;
        long long int prev1 = 1;

        long long int temp;

        for (int i = 2; i <= h; i++)
        {
            temp = ((2 * prev1 * prev2) % MOD + (prev1 * prev1) % MOD + MOD) % MOD;

            prev2 = prev1;
            prev1 = temp;
        }

        return temp;
    }
};