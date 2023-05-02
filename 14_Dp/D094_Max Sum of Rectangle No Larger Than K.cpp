#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
// https://www.youtube.com/watch?v=f3-Q3iQysR8

class Solution
{
public:
    // function to find the maximum subarray sum and the sum should be <= k

    // so what happening here is that, we are calculating the prefix sum of the array
    // now we are at the index i ( 0 < i < n ), now we need to find the perfix sum
    // such that difference of this prefic sum and the sum till index i is <= k.
    // one option is to start from the index0 and try with each prefix sum
    // another option is to find the lower bound of (prefic sum at i - k). This will give the desired prefix sum.

    // we are using the second option here as the first option TC is O(n) and second option's TC is log(n)

    int maxSubarraySum(vector<int> &arr, int n, int k)
    {
        int sum = 0;        // temporary sum.
        int maxi = INT_MIN; // maximim sum.

        set<int> st;
        st.insert(0);

        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
            auto it = st.lower_bound(sum - k);

            if (it != st.end())
                maxi = max(maxi, sum - *it);

            st.insert(sum);
        }

        return maxi;
    }
    int maxSumSubmatrix(vector<vector<int>> &M, int k)
    {

        int R = M.size();
        int C = M[0].size();

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

                maxi = max(maxi, maxSubarraySum(temp, C, k));
            }
        }

        return maxi;
    }
};