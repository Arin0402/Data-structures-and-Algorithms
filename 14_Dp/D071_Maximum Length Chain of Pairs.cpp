#include <bits/stdc++.h>
using namespace std;
struct val
{
    int first;
    int second;
};

// https://practice.geeksforgeeks.org/problems/max-length-chain/1

// dp solution
// time limit exceed
// this is just for understanding
class Solution
{
public:
    /*You are required to complete this method*/
    int helper(int ind, int prev, int n, struct val p[], vector<vector<int>> &dp)
    {

        if (ind < 0)
            return 0;

        if (dp[ind][prev] != -1)
            return dp[ind][prev];

        int not_take = helper(ind - 1, prev, n, p, dp);
        int take = 0;

        if (prev == n || p[prev].first > p[ind].second)
            take = 1 + helper(ind - 1, ind, n, p, dp);

        return dp[ind][prev] = max(take, not_take);
    }

    static bool cmp(struct val p1, struct val p2)
    {
        return p1.second < p2.second;
    }

    int maxChainLen(struct val p[], int n)
    {

        // sorting is necessary as we can select pairs in any order.
        sort(p, p + n, cmp);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(n - 1, n, n, p, dp);
    }
};

// 2
// efficient solution

class Solution
{
public:
    /*You are required to complete this method*/
    static bool cmp(struct val p1, struct val p2)
    {
        return p1.second < p2.second;
    }

    int maxChainLen(struct val p[], int n)
    {

        // sorting is necessary as we can select pairs in any order.
        sort(p, p + n, cmp);

        vector<int> ans;

        int i = 0, j = 1;
        int count = 1;

        while (j < n)
        {

            if (p[i].second < p[j].first)
            {
                count++;
                i = j;
            }

            j++;
        }
        return count;
    }
};