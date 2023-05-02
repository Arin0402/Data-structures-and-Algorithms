#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1.

// 1
// this is for understanding
// this will give TLE

// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    long long int helper(int l, int r, int chance, int arr[], vector<vector<vector<long long int>>> &dp)
    {

        if (l > r)
            return 0;

        if (dp[l][r][chance] != -1)
            return dp[l][r][chance];

        // user chooses
        if (chance == 1)
        {
            long long int choice1 = 0, choice2 = 0;

            // either take the left element.
            choice1 = arr[l] + helper(l + 1, r, 0, arr, dp);

            // or take the right element.
            choice2 = arr[r] + helper(l, r - 1, 0, arr, dp);

            // max of both the answers.
            return dp[l][r][chance] = max(choice1, choice2);
        }

        // other opponent chooses
        else
        {

            // we do not care about the amount of the opponent so do not take value.
            // the opponent can take the left or the right coin.
            // here we are assuming the worst case in which the maximum goes into the opponents
            // pocket and minimum is left for us.
            return dp[l][r][chance] = min(helper(l + 1, r, 1, arr, dp), helper(l, r - 1, 1, arr, dp));
        }
    }

    long long maximumAmount(int arr[], int n)
    {

        vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(n, vector<long long int>(2, -1)));

        return helper(0, n - 1, 1, arr, dp);
    }
};

// In the above code, we are using 3d dp and more recursive calls , we can reduce them to the following code
// This is accepted.

class Solution
{
public:
    long long int helper(int l, int r, int arr[], vector<vector<long long int>> &dp)
    {

        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        long long int choice1 = 0, choice2 = 0;

        // either take the left element.
        // get the minimum from the opponent
        choice1 = arr[l] + min(helper(l + 2, r, arr, dp), helper(l + 1, r - 1, arr, dp));

        // or take the right element.
        // get the minimum from the opponent
        choice2 = arr[r] + min(helper(l + 1, r - 1, arr, dp), helper(l, r - 2, arr, dp));

        // max of both the answers.
        return dp[l][r] = max(choice1, choice2);
    }

    long long maximumAmount(int arr[], int n)
    {

        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
        return helper(0, n - 1, arr, dp);
    }
};

// 2

class Solution
{
public:
    long long maximumAmount(int arr[], int n)
    {

        vector<vector<long long int>> dp(n + 1, vector<long long int>(n + 1, 0));

        for (int l = n - 1; l >= 0; l--)
        {

            for (int r = l + 1; r < n; r++)
            {

                long long int choice1 = 0, choice2 = 0;

                choice1 = arr[l] + min(dp[l + 2][r], dp[l + 1][r - 1]);

                choice2 = arr[r] + min(dp[l + 1][r - 1], dp[l][r - 2]);

                dp[l][r] = max(choice1, choice2);
            }
        }

        return dp[0][n - 1];
    }
};