#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
// https://www.youtube.com/watch?v=SzaLN2r6P4E

// 1
long long int count(long long int n)
{

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 3];
    }

    for (int i = 5; i <= n; i++)
    {
        dp[i] += dp[i - 5];
    }

    for (int i = 10; i <= n; i++)
    {
        dp[i] += dp[i - 10];
    }

    return dp[n];
}
