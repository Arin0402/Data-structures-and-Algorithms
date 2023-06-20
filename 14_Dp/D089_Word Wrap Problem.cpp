#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/word-wrap1646/1

// 1

class Solution
{
public:
    int dp[505][2005];

    // rem -> remaining space.
    int rec(int i, int rem, vector<int> &arr, int k)
    {

        // last word. will not count any cost of white space
        if (i == arr.size())
            return 0;

        if (dp[i][rem] != -1)
            return dp[i][rem];

        int ans;

        // word length is greater than the remaining space.
        if (arr[i] > rem)
        {

            ans = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k);
        }
        // word length is <= the remaining space.
        else
        {

            // put the word in the next line.
            int choice1 = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k);

            // put the word in that space.
            int choice2 = rec(i + 1, rem - arr[i] - 1, arr, k);

            ans = min(choice1, choice2);
        }

        dp[i][rem] = ans;

        return ans;
    }

    int solveWordWrap(vector<int> arr, int k)
    {
        memset(dp, -1, sizeof(dp));

        return rec(0, k, arr, k);
    }
};