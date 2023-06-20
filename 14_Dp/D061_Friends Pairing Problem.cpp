#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
// https://www.youtube.com/watch?v=wOtRnD0f7Yw

// 1
// memo
class Solution
{
public:
    long long int helper(int n, vector<long long int> &dp)
    {

        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        // recur for the remaining friends.
        long long int staySingle = helper(n - 1, dp) % MOD;

        // make pair with the remaining friends in n-1 ways and one friend would be taken
        // so recur for n-2 friends.
        long long int makePair = ((n - 1) % MOD * helper(n - 2, dp) % MOD) % MOD;

        return dp[n] = (staySingle % MOD + makePair % MOD) % MOD;
    }

    int countFriendsPairings(int n)
    {

        vector<long long int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

// 2
// tab
class Solution
{
public:
    int countFriendsPairings(int n)
    {

        vector<long long int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {

            long long int staySingle = dp[i - 1] % MOD;
            long long int makePair = ((i - 1) % MOD * dp[i - 2] % MOD) % MOD;

            dp[i] = (staySingle % MOD + makePair % MOD) % MOD;
        }

        return dp[n];
    }
};

// 3
// space optimised
class Solution
{
public:
    int countFriendsPairings(int n)
    {

        long long int prev2 = 1;
        long long int prev1 = 2;
        long long int temp = 0;

        if (n <= 2)
            return n;

        for (int i = 3; i <= n; i++)
        {

            long long int staySingle = prev1 % MOD;
            long long int makePair = ((i - 1) % MOD * prev2 % MOD) % MOD;

            temp = (staySingle % MOD + makePair % MOD) % MOD;

            prev2 = prev1;
            prev1 = temp;
        }

        return temp;
    }
};