#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

// 1
// memo
// O(3*N) ( four each day three different states )
// O(N*4) + O(N)

class Solution
{
public:
    int helper(int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {

        if (ind < 0)
            return 0;

        if (dp[ind][last] != -1)
            return dp[ind][last];
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;

        if (last != 0)
            choice1 = points[ind][0] + helper(ind - 1, 0, points, dp);
        if (last != 1)
            choice2 = points[ind][1] + helper(ind - 1, 1, points, dp);
        if (last != 2)
            choice3 = points[ind][2] + helper(ind - 1, 2, points, dp);

        return dp[ind][last] = max({choice1, choice2, choice3});
    }

    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n - 1, 3, points, dp);
    }
};

// 2
// tabulation
// O(4*N)
// O(4*N)

class Solution
{
public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][1], points[0][1], points[0][2]});

        for (int i = 1; i < n; i++)
        {

            for (int last = 0; last < 4; last++)
            {

                int choice1 = 0;
                int choice2 = 0;
                int choice3 = 0;

                if (last != 0)
                    choice1 = points[i][0] + dp[i - 1][0];
                if (last != 1)
                    choice2 = points[i][1] + dp[i - 1][1];
                if (last != 2)
                    choice3 = points[i][2] + dp[i - 1][2];

                dp[i][last] = max({choice1, choice2, choice3});
            }
        }

        return dp[n - 1][3];
    }
};

// 3
// optimised
// O(4*N)
// O(4)

class Solution
{

public:
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<int> prev(4, 0);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][1], points[0][1], points[0][2]});

        for (int i = 1; i < n; i++)
        {

            vector<int> temp(4, 0);

            for (int last = 0; last < 4; last++)
            {

                int choice1 = 0;
                int choice2 = 0;
                int choice3 = 0;

                if (last != 0)
                    choice1 = points[i][0] + prev[0];
                if (last != 1)
                    choice2 = points[i][1] + prev[1];
                if (last != 2)
                    choice3 = points[i][2] + prev[2];

                temp[last] = max({choice1, choice2, choice3});
            }

            prev = temp;
        }

        return prev[3];
    }
};
