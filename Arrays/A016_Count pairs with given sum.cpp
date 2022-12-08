#include <bits/stdc++.h>
using namespace std;

// 1
// brute force n^2

// 2
// using map
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {

        unordered_map<int, int> mp;

        int count = 0; // number of pairs.

        for (int i = 0; i < n; i++)
        {

            if (mp.find(k - arr[i]) != mp.end())
            {

                count += mp[k - arr[i]]; // add the frequency of the number which we are seacrhing.
            }

            mp[arr[i]]++; // increase the frequency of elements.
        }

        return count;
    }
};