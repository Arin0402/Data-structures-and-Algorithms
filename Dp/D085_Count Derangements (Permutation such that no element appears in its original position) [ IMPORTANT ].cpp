#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.youtube.com/watch?v=NW-BLDQHFXk

// 1
// memo
#define MOD 1000000007

class Solution
{
public:
    long int disarrange(int N)
    {

        vector<long int> dp(N + 1, 0);
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= N; i++)
        {

            dp[i] = ((i - 1) % MOD * (dp[i - 1] % MOD + dp[i - 2] % MOD)) % MOD;
        }

        return dp[N];
    }
};