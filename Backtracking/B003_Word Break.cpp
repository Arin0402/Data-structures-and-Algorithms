#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/word-break1352/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// recursive
// O(2^n) // for very index , we have two choices , whether to take that index in partiton or not.

class Solution
{
public:
    bool helper(int pos, int n, string &A, unordered_map<string, int> &mp, vector<bool> &dp)
    {

        // reached the end;
        if (pos == n)
            return true;

        string temp1 = "";

        if (dp[pos] == true)
            return true;

        // increase the partition size every time. start from size 1.
        for (int i = pos + 1; i <= n; i++)
        {

            temp1 = A.substr(pos, i - pos);

            // first part is present.
            if (mp[temp1] > 0)
            {

                // second is also present.
                if (dp[pos] = helper(i, n, A, mp, dp))
                    return true;
            }
        }

        return false;
    }
    int wordBreak(string A, vector<string> &B)
    {

        // to check if word is present.
        unordered_map<string, int> mp;

        for (auto ele : B)
            mp[ele]++;

        int n = A.size();

        // dp array. This will store the if it is possible to partition from the current index
        // such that all the words combination from this index onwards and till the end of the string
        // will be present in the dictionary.
        vector<bool> dp(n, false);

        return helper(0, n, A, mp, dp);
    }
};
// DP
// memoization
// O(N^2)
// top down

class Solution
{
public:
    bool helper(int pos, int n, string &A, unordered_map<string, int> &mp, vector<bool> &dp)
    {

        // reached the end;
        if (pos == n)
            return true;

        string temp1 = "";

        if (dp[pos] == true)
            return true;

        // increase the partition size every time. start from size 1.
        for (int i = pos + 1; i <= n; i++)
        {

            temp1 = A.substr(pos, i - pos);

            // first part is present.
            if (mp[temp1] > 0)
            {

                // second is also present.
                if (dp[pos] = helper(i, n, A, mp, dp))
                    return true;
            }
        }

        return false;
    }
    int wordBreak(string A, vector<string> &B)
    {

        // to check if word is present.
        unordered_map<string, int> mp;

        for (auto ele : B)
            mp[ele]++;

        int n = A.size();

        // dp array. This will store the if it is possible to partition from the current index
        // such that all the words combination from this index onwards and till the end of the string
        // will be present in the dictionary.
        vector<bool> dp(n, false);

        return helper(0, n, A, mp, dp);
    }
};

// 3
// tabulation
// O(N^3) // techdose.
// bottom up