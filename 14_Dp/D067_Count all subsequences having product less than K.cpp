#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-subsets-with-product-less-than-k/1

// 1
// memo
class Solution
{
public:
    int helper(int ind, int prod, int k, int arr[], vector<vector<int>> &dp)
    {

        if (ind < 0)
        {
            return prod <= k;
        }

        if (dp[ind][prod] != -1)
            return dp[ind][prod];

        int not_take = helper(ind - 1, prod, k, arr, dp);
        int take = 0;

        if (prod * arr[ind] <= k)
            take = helper(ind - 1, prod * arr[ind], k, arr, dp);

        return dp[ind][prod] = take + not_take;
    }
    int numOfSubsets(int arr[], int N, int K)
    {

        vector<vector<int>> dp(N, vector<int>(K + 1, -1));

        // -1 because we do not have to include the empty subsequence(the product of the empty subsequence will be one
        // because of the default value).
        return helper(N - 1, 1, K, arr, dp) - 1;
    }
};

// OR

class Solution
{
public:
    int helper(int ind, int prod, int k, int arr[], vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            return prod <= k;
        }

        if (dp[ind][prod] != -1)
            return dp[ind][prod];

        int not_take = helper(ind - 1, prod, k, arr, dp);
        int take = 0;

        if (prod * arr[ind - 1] <= k)
            take = helper(ind - 1, prod * arr[ind - 1], k, arr, dp);

        return dp[ind][prod] = take + not_take;
    }
    int numOfSubsets(int arr[], int N, int K)
    {

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));

        // -1 because we do not have to include the empty subsequence(the product of the empty subsequence will be one
        // because of the default value).
        return helper(N, 1, K, arr, dp) - 1;
    }
};

// 2
// tab
class Solution
{
public:
    int numOfSubsets(int arr[], int N, int K)
    {

        vector<vector<int>> dp(N + 1, vector<int>(K + 2, 0));

        for (int j = 0; j <= K + 1; j++)
        {
            if (j <= K)
                dp[0][j] = 1;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= K + 1; j++)
            {

                int not_take = dp[i - 1][j];
                int take = 0;

                if (j * arr[i - 1] <= K)
                    take = dp[i - 1][j * arr[i - 1]];

                dp[i][j] = take + not_take;
            }
        }

        // -1 because we do not have to include the empty subsequence(the product of the empty subsequence will be one
        // because of the default value).
        return dp[N][1] - 1;
    }
};

// 3
// space optimised
class Solution
{
public:
    int numOfSubsets(int arr[], int N, int K)
    {

        vector<int> prev(K + 2, 0);

        for (int j = 0; j <= K + 1; j++)
        {
            if (j <= K)
            {
                prev[j] = 1;
            }
        }

        for (int i = 1; i <= N; i++)
        {

            vector<int> temp(K + 2, 0);
            for (int j = 1; j <= K + 1; j++)
            {

                int not_take = prev[j];
                int take = 0;

                if (j * arr[i - 1] <= K)
                    take = prev[j * arr[i - 1]];

                temp[j] = take + not_take;
            }

            prev = temp;
        }

        // -1 because we do not have to include the empty subsequence(the product of the empty subsequence will be one
        // because of the default value).
        return prev[1] - 1;
    }
};