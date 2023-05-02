#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-point-you-can-obtain-from-cards/1

// 1
// O(K^2)
// concept same as approach 2
// O(K^2) because of calcualting the sum of K elements k times

// 2
// O(K)
// O(1)
// we can pick x cards from the left and k - x cards from the right
// we will assume that we have picked all the k cards from the left hand side
// now we will start decreasing one card from the left and pick one card from the right
// calculate the maximum among them

class Solution
{
public:
    // calculate the sum of first k elements
    long long sum(vector<int> &cardPoints, int k)
    {

        long long int ans = 0;

        for (int i = 0; i < k; i++)
            ans += cardPoints[i];

        return ans;
    }

    long long maxScore(vector<int> &cardPoints, int N, int k)
    {

        // answer
        long long int ans = 0;

        int r = N - 1;
        int l = k - 1;

        // temporary sum
        // initially containing the sum of the first k elements
        long long temp = sum(cardPoints, k);

        ans = max(ans, temp);

        while (l >= 0)
        {

            temp -= cardPoints[l];
            l--;

            temp += cardPoints[r];
            r--;

            ans = max(ans, temp);
        }

        return ans;
    }
};