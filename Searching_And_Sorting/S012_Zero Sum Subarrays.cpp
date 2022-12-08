#include <bits/stdc++.h>
using namespace std;

// 1
// try all
// O(n^2)

// 2
// refrenece from A019 ,   https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// O(n)
//
class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    long long findSubarray(vector<long long> arr, int n)
    {

        int cnt = 0;
        long sum = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {

            sum += arr[i];

            if (sum == 0)
                cnt++;

            if (mp.find(sum) != mp.end())
            {

                // add the number of times sum has appeared.
                cnt += mp[sum];
            }

            // keep the track how many times the sum had appeared.
            mp[sum]++;
        }

        return cnt;
    }
};