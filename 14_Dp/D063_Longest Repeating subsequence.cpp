#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// same as LCS
// we will find LCS with the same string , but the indeces should be different.

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {

        int n = str.size();

        vector<int> prev(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {

            vector<int> temp(n + 1, 0);
            for (int j = 1; j <= n; j++)
            {

                if (str[i - 1] == str[j - 1] && i != j)
                    temp[j] = 1 + prev[j - 1];
                else
                    temp[j] = max(prev[j], temp[j - 1]);
            }

            prev = temp;
        }

        return prev[n];
    }
};