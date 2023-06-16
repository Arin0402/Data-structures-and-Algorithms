#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/array-removals/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// O(nlogn) approach is important. discussed below( number 4)

// 1
// memo
class Solution
{
public:
    int helper(int i, int j, vector<int> &arr, int k, vector<vector<int>> &dp)
    {

        if (i > j)
            return 1e9;
        if (arr[j] - arr[i] <= k)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int choice1 = 0, choice2 = 0, choice3 = 0;

        choice1 = 1 + helper(i, j - 1, arr, k, dp);
        choice2 = 1 + helper(i + 1, j, arr, k, dp);
        choice3 = 2 + helper(i + 1, j - 1, arr, k, dp);

        return dp[i][j] = min({choice1, choice2, choice3});
    }
    int removals(vector<int> &arr, int k)
    {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, arr, k, dp);
    }
};

// 2
// tab
class Solution
{
public:
    int removals(vector<int> &arr, int k)
    {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {

                if (arr[j] - arr[i] <= k)
                    dp[i][j] = 0;

                else
                {
                    int choice1 = INT_MAX, choice2 = INT_MAX, choice3 = INT_MAX;

                    if (j - 1 >= 0)
                        choice1 = 1 + dp[i][j - 1];
                    if (i + 1 < n)
                        choice2 = 1 + dp[i + 1][j];
                    if (i + 1 < n && j - 1 >= 0)
                        choice3 = 2 + dp[i + 1][j - 1];

                    dp[i][j] = min({choice1, choice2, choice3});
                }
            }
        }

        return dp[0][n - 1];
    }
};

// 3
class Solution
{
public:
    int removals(vector<int> &arr, int k)
    {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> prev(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            vector<int> temp(n, 0);
            for (int j = i; j < n; j++)
            {

                if (arr[j] - arr[i] <= k)
                    temp[j] = 0;

                else
                {
                    int choice1 = INT_MAX, choice2 = INT_MAX, choice3 = INT_MAX;

                    if (j - 1 >= 0)
                        choice1 = 1 + temp[j - 1];
                    if (i + 1 < n)
                        choice2 = 1 + prev[j];
                    if (i + 1 < n && j - 1 >= 0)
                        choice3 = 2 + prev[j - 1];

                    temp[j] = min({choice1, choice2, choice3});
                }
            }

            prev = temp;
        }

        return prev[n - 1];
    }
};

// 4
// O(nlogn)
// O(1)
//  
class Solution
{
public:
    int removals(vector<int> &arr, int k)
    {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {

            int ind = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin() - 1;

            ans = min(ans, n - (ind - i + 1));
        }

        return ans;
    }
};
