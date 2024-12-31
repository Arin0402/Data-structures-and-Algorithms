#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/ncr1019/1
// https://www.youtube.com/watch?v=jIb1W3ObIho

// 1
// o(r*r);
// O(r)

#define MOD 1000000007

class Solution
{
public:
    int nCr(int n, int r)
    {

        if (n < r)
            return 0;
        if (n - r < r)
            r = n - r;

        vector<int> dp(r + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {

            int ind = r;

            while (ind > 0)
            {
                dp[ind] = (dp[ind] + dp[ind - 1]) % MOD;
                ind--;
            }
        }

        return dp[r];
    }
};
