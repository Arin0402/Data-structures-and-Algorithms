#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

// 1
// memo
// O(n*target)
// O(n*target) + O(n);

class Solution
{
public:
    bool helper(int ind, int target, int arr[], vector<vector<int>> &dp)
    {

        if (target == 0)
            return true;
        if (ind == 0)
            return (arr[0] == target);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool not_take = helper(ind - 1, target, arr, dp);
        bool take = false;

        if (arr[ind] <= target)
            take = helper(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take | not_take;
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1 == 1)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(N, vector<int>(target + 1, -1));

        return helper(N - 1, target, arr, dp);
    }
};

// 2
// tab
// O(n*target)
// O(n*target)
class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1 == 1)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(N, vector<int>(target + 1, 0));

        for (int i = 0; i < N; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] == target)
            dp[0][arr[0]] = true;

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j <= target; j++)
            {

                bool not_take = dp[i - 1][j];
                bool take = false;
                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = (take | not_take);
            }
        }

        return dp[N - 1][target];
    }
};

// 3
// space optimised
// O(n*target)
// O(2*target);
class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1 == 1)
            return false;

        int target = sum / 2;

        vector<int> prev(target + 1, 0);
        prev[0] = true;

        if (arr[0] == target)
            prev[arr[0]] = true;

        for (int i = 1; i < N; i++)
        {

            vector<int> temp(target + 1, 0);
            for (int j = 1; j <= target; j++)
            {

                bool not_take = prev[j];
                bool take = false;
                if (arr[i] <= j)
                    take = prev[j - arr[i]];

                temp[j] = (take | not_take);
            }

            prev = temp;
        }

        return prev[target];
    }
};