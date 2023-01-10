#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
// using kadane's algo
class Solution
{
public:
    // kadane's algo.
    int maxSubarraySum(vector<int> &arr, int n)
    {

        int sum = 0;       // temporary sum.
        int maxi = arr[0]; // maximim sum.

        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0; // Order does not matter, it can be at starting as well.
        }

        return maxi;
    }

    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {

        int maxi = INT_MIN;

        for (int i = 0; i < R; i++)
        {

            vector<int> temp(C, 0);

            for (int j = i; j < R; j++)
            {

                for (int k = 0; k < C; k++)
                {

                    temp[k] += M[j][k];
                }

                maxi = max(maxi, maxSubarraySum(temp, C));
            }
        }

        return maxi;
    }
};
