#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

// 1
// recursion
// User function Template for C++

class Solution
{
public:
    bool helper(int pos, long int temp, int N, long int sum, int arr[])
    {

        // if(dp[temp] == )
        if (temp == sum)
            return true;

        if (temp > sum)
            return false;
        if (pos >= N)
            return false;
        // if(dp[pos][temp] != -1) return dp[pos][temp];

        if (helper(pos + 1, temp + arr[pos], N, sum, arr))
            return true;
        if (helper(pos + 1, temp, N, sum, arr))
            return true;
    }

    // to calculate sum.
    long int sum(int N, int arr[])
    {

        long int total = 0;

        for (int i = 0; i < N; i++)
        {
            total += arr[i];
        }

        return total;
    }

    int equalPartition(int N, int arr[])
    {

        long int total = sum(N, arr);

        // vector<vector<int>> dp(N+1, vector<int>(total/2 + 1, -1));
        vector<int> dp(total / 2 + 1, -1);

        if (total % 2 != 0)
            return 0;

        return helper(0, 0, N, total / 2, arr);
    }
};

// 2
// memoiation
// TC - O(N * Total/2);
// Sc - O(N * Total/2) + O(N)(stack space);

class Solution
{
public:
    bool helper(int pos, long int temp, int N, long int sum, int arr[], vector<vector<int>> &dp)
    {

        if (temp == sum)
            return true;
        if (pos >= N)
            return false;
        if (temp > sum)
            return false; // required is greater than target.

        if (dp[pos][temp] != -1)
            return dp[pos][temp]; // return the answer beyond this point.

        bool pick = helper(pos + 1, temp + arr[pos], N, sum, arr, dp);
        bool not_pick = helper(pos + 1, temp, N, sum, arr, dp);

        return dp[pos][temp] = pick | not_pick; // true if one of them is true.
    }

    // to calculate sum.
    long int sum(int N, int arr[])
    {

        long int total = 0;

        for (int i = 0; i < N; i++)
        {
            total += arr[i];
        }

        return total;
    }

    int equalPartition(int N, int arr[])
    {

        long int total = sum(N, arr);

        // dp array.
        vector<vector<int>> dp(N + 1, vector<int>(total / 2 + 1, -1));

        if (total % 2 != 0)
            return 0;
        return helper(0, 0, N, total / 2, arr, dp);
    }
};

    // 3
    // tabulation
    // not done here, in dp series.