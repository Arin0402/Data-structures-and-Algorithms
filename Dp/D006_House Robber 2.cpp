#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-ii/

// similar to D005
// here it is giver the houses are in circular array.
// so we can conclude :-
// first and last house can not be in the same subsequence.
// so will have two vectors temp1 (0 , n-1)
// temp2 (1, n)
// answer will be the maximum of the both.

class Solution
{
public:
    // space optimised code of the D005.
    int helper(vector<int> &nums)
    {

        int prev2 = INT_MIN;
        int prev1 = INT_MIN;
        int num;

        for (int i = 0; i < nums.size(); i++)
        {

            int pick = nums[i] + (i - 2 >= 0 ? prev2 : 0);
            int notPick = (i - 1 >= 0 ? prev1 : 0);

            num = max(pick, notPick);

            prev2 = prev1;
            prev1 = num;
        }

        return num;
    }

    int rob(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++)
        {

            if (i != n - 1)
                temp1.push_back(nums[i]);
            if (i != 0)
                temp2.push_back(nums[i]);
        }

        // call for both seperately.
        return max(
            helper(temp1),
            helper(temp2));
    }
};