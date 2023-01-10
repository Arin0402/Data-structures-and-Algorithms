#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

// 1
// memo
// O(n*n)  extra n for FOR LOOP
// O(n) + O(n)
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {

        while (i < j)
        {

            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int helper(int i, int n, string &s, vector<int> &dp)
    {

        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mini = 1e9;

        for (int j = i; j < n; j++)
        {

            if (isPalindrome(i, j, s))
            {

                int parts = 1 + helper(j + 1, n, s, dp);
                mini = min(mini, parts);
            }
        }

        return dp[i] = mini;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();

        vector<int> dp(n, -1);
        return helper(0, n, str, dp) - 1;
    }
};

// 2
// tab
// O(n*n)  extra n for FOR LOOP
// O(n)
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {

        while (i < j)
        {

            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            int mini = 1e9;

            for (int j = i; j < n; j++)
            {

                if (isPalindrome(i, j, str))
                {

                    int parts = 1 + dp[j + 1];
                    mini = min(mini, parts);
                }
            }

            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};