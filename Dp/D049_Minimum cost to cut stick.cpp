#include <bits/stdc++.h>
using namespace std;

// 1
// memo
// O(n*n*n)
// O(n*n) + O(n)
class Solution
{
public:
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {

        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e9;

        for (int k = i; k <= j; k++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + helper(i, k - 1, cuts, dp) + helper(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int> &cuts)
    {

        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return helper(1, c, cuts, dp);
    }
};

// 2
// tab
// O(n*n*n)
// O(n*n)
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {

        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--)
        {
            for (int j = i; j <= c; j++)
            {
                int mini = 1e9;

                for (int k = i; k <= j; k++)
                {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};