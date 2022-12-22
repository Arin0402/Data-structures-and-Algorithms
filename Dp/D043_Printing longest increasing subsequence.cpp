#include <bits/stdc++.h>
using namespace std;

// O(n*2)
// O(n)

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {

        vector<int> dp(n, 1);
        vector<int> hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {

            hash[i] = i;

            for (int j = 0; j < i; j++)
            {

                if (a[j] < a[i] && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        ans.push_back(a[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {

            lastIndex = hash[lastIndex];
            ans.push_back(a[lastIndex]);
        }

        reverse(ans.begin(), ans.end());

        for (auto itr : ans)
            cout << itr << " ";
    }
};