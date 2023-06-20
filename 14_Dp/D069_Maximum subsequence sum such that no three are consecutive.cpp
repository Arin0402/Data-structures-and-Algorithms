#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents-2/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// memo
// O(3*N)
// O(3*N) + O(N)
class Solution
{
public:
    // keep a counter which will denote consecutiveness.
    int helper(int ind, int count, vector<int> &a, vector<vector<int>> &dp)
    {

        if (ind < 0)
            return 0;

        if (dp[ind][count] != -1)
            return dp[ind][count];

        // for not_take condition, reset counter to zero.
        int not_take = helper(ind - 1, 0, a, dp);

        int take = 0;

        // if count is 2 , then it means we have already taken two consecutive elements
        // ans we can not take this one.
        if (count < 2)
            take = a[ind] + helper(ind - 1, count + 1, a, dp);

        return dp[ind][count] = max(take, not_take);
    }
    int findMaxSum(vector<int> &a)
    {

        int n = a.size();

        vector<vector<int>> dp(n, vector<int>(3, -1));
        return helper(n - 1, 0, a, dp);
    }
};

// OR

class Solution
{
public:
    // keep a counter which will denote consecutiveness.
    int helper(int ind, int count, vector<int> &a, vector<vector<int>> &dp)
    {

        if (ind == 0)
            return 0;

        if (dp[ind][count] != -1)
            return dp[ind][count];

        // for not_take condition, reset counter to zero.
        int not_take = helper(ind - 1, 0, a, dp);

        int take = 0;

        // if count is 2 , then it means we have already taken two consecutive elements
        // ans we can not take this one.
        if (count < 2)
            take = a[ind - 1] + helper(ind - 1, count + 1, a, dp);

        return dp[ind][count] = max(take, not_take);
    }
    int findMaxSum(vector<int> &a)
    {

        int n = a.size();

        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return helper(n, 0, a, dp);
    }
};

// 2
// tab
class Solution
{
public:
    // keep a counter which will denote consecutiveness.
    int findMaxSum(vector<int> &a)
    {

        int n = a.size();

        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2; j++)
            {

                int not_take = dp[i - 1][0];
                int take = 0;

                if (j < 2)
                    take = a[i - 1] + dp[i - 1][j + 1];

                dp[i][j] = max(take, not_take);
            }
        }

        return dp[n][0];
    }
};

// 3
// space optimised
class Solution
{
public:
    // keep a counter which will denote consecutiveness.
    int findMaxSum(vector<int> &a)
    {

        int n = a.size();

        vector<int> prev(3, 0);

        for (int i = 1; i <= n; i++)
        {

            vector<int> temp(3, 0);
            for (int j = 0; j <= 2; j++)
            {

                int not_take = prev[0];
                int take = 0;

                if (j < 2)
                    take = a[i - 1] + prev[j + 1];

                temp[j] = max(take, not_take);
            }

            prev = temp;
        }

        return prev[0];
    }
};
