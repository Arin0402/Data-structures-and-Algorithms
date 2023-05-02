#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1

// 1
// memo

class Solution
{

public:
    int helper(int n, vector<int> &heights, vector<int> &dp)
    {

        if (n == 0)
            return 0;
        if (n == 1)
            return abs(heights[1] - heights[0]);

        if (dp[n] != -1)
            return dp[n];

        int choice1 = abs(heights[n] - heights[n - 1]) + helper(n - 1, heights, dp);
        int choice2 = abs(heights[n] - heights[n - 2]) + helper(n - 2, heights, dp);

        return dp[n] = min(choice1, choice2);
    }

    int frogJump(int n, vector<int> &heights)
    {

        vector<int> dp(n, -1);
        return helper(n - 1, heights, dp);
    }
};

// 2
// Tab
class Solution
{

public:
    int frogJump(int n, vector<int> &heights)
    {
        // 0 based indexing , that's why n;
        // we include the last index that is involved.

        vector<int> dp(n, -1);

        dp[0] = 0;
        dp[1] = abs(heights[1] - heights[0]);

        // loop till index n-1, that's the index till we want answer.
        for (int i = 2; i <= n - 1; i++)
        {

            int choice1 = abs(heights[i] - heights[i - 1]) + dp[i - 1];
            int choice2 = abs(heights[i] - heights[i - 2]) + dp[i - 2];

            dp[i] = min(choice1, choice2);
        }

        return dp[n - 1];
    }
};

// 3
// optmised
// O(N)
// O(1)

class Solution
{

public:
    int frogJump(int n, vector<int> &heights)
    {

        int prev2 = 0;
        int prev1 = abs(heights[1] - heights[0]);
        int mini;

        for (int i = 2; i < n; i++)
        {

            int choice1 = abs(heights[i] - heights[i - 1]) + prev1;
            int choice2 = abs(heights[i] - heights[i - 2]) + prev2;

            mini = min(choice1, choice2);

            prev2 = prev1;
            prev1 = mini;
        }

        return mini;
    }
};
