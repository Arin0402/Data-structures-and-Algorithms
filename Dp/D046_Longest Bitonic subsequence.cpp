#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

// 1
// O(N*N)
// O(N)
// find LIS (longest increasing subsequence from the beginning and from the end, add both of them for each index
// and find the maximum )

class Solution
{
public:
    int LongestBitonicSequence(vector<int> a)
    {
        int n = a.size();

        vector<int> dp1(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                if (a[j] < a[i] && 1 + dp1[j] > dp1[i])
                {
                    dp1[i] = 1 + dp1[j];
                }
            }
        }

        vector<int> dp2(n, 1);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {

                if (a[j] < a[i] && 1 + dp2[j] > dp2[i])
                {
                    dp2[i] = 1 + dp2[j];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }

        return ans;
    }
};