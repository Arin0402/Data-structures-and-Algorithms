#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/count-subarray-with-k-odds/1
// same concept of "subarrays with sum k" (A073)

// 1
// try all the subarrays
// O(N^2)

// 2
// O(N)
// reduce the problem into "count the subnumsays  with sum equal to k"
// replace the odd with 1 and even with 0
class Solution
{
public:
    int countSubarray(int n, vector<int> &nums, int k)
    {

        for (int i = 0; i < n; i++)
        {

            // if number is odd, then replace it by 1
            if (nums[i] & 1)
                nums[i] = 1;

            // number is even , set it to zero
            else
                nums[i] = 0;
        }

        unordered_map<int, int> mp;

        // for sum zero, count = 1;
        mp[0] = 1;

        // current sum
        int currSum = 0;

        // answer
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            // add it to the answer
            currSum += nums[i];

            // add count of all the subnumsays to the answer
            // whose value is equal to currSum - k
            if (mp.find(currSum - k) != mp.end())
            {
                ans += mp[currSum - k];
            }

            // !--------------NOTE-----------!
            // we have to increase the count for currSum only at the end
            // if we increase the count before, then it will not work for the case
            // ex- 0 0 0 0 0, k = 0
            mp[currSum]++;
        }

        return ans;
    }
};