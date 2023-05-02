#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// O(n)
class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int k)
    {
        unordered_map<int, int> mp; // to store the occurence of the sums
        mp[0] = -1;

        int tempSum = 0;
        int maxi = 0; // maximum length

        for (int i = 0; i < N; i++)
        {

            tempSum += A[i];

            // if tempSum - k is present, find the max length.
            if (mp.find(tempSum - k) != mp.end())
            {
                maxi = max(maxi, i - mp[tempSum - k]);
            }

            // insert the index only and only if when the tempSum is not present.
            // if present, then we will not update. we will consider the previuos index in order
            // to find the maximum.
            if (mp.find(tempSum) == mp.end())
            {
                mp[tempSum] = i;
            }
        }

        return maxi;
    }
};