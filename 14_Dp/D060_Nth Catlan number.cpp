#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
// https://www.youtube.com/watch?v=eUw9A1wsFg8

// useful link if time
// https://www.youtube.com/watch?v=0pTN0qzpt-Y

// 1
class Solution
{
public:
    // Function to find the nth catalan number.
    int findCatalan(int n)
    {

        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {

            int j = 0;
            int k = i - 1;

            dp[i] = 0;

            while (j <= k)
            {

                if (j == k)
                    dp[i] += dp[j] * dp[k];
                else
                    dp[i] += 2 * dp[j] * dp[k];

                j++;
                k--;
            }
        }

        return dp[n];
    }
};
