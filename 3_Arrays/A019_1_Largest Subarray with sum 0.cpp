#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        map<int, int> mp;

        int maxLen = 0;
        int temp = 0;

        // declare the index for the sum 0 as -1.
        mp[0] = -1; // {-1, 1, -1, 1}

        for (int i = 0; i < n; i++)
        {

            temp += A[i];

            if (mp.find(temp) != mp.end())
            {
                maxLen = max(maxLen, i - mp[temp]);
            }
            else
                mp[temp] = i;
        }

        return maxLen;
    }
};
