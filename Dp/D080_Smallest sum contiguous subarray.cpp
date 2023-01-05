#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// based on Kadane's algorithm

// 1
class Solution
{
public:
    int smallestSumSubarray(vector<int> &arr)
    {

        int n = arr.size();
        int sum = 0;
        int mini = arr[0];

        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
            mini = min(mini, sum);

            if (sum > 0)
                sum = 0;
        }

        return mini;
    }
};
