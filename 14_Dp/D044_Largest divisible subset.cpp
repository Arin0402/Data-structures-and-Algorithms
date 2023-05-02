#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/e866d887f78664cdbf24c61ef9404691f4fb9e59/1?page=1&sortBy=newest&query=page1sortBynewest

// same as printing the longest increasing subsequence.
// 1
// O(n*2)
// O(n*2)
class Solution
{
public:
    vector<int> LargestSubset(int n, vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {

            hash[i] = i;
            for (int j = 0; j < i; j++)
            {

                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
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
        ans.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {

            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};