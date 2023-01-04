#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1

// 1
// kind of greedy
class Solution
{
public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // sort the array.
        sort(arr, arr + N);

        // one pointer at last and one at n-2;
        int i = N - 2, j = N - 1;

        int sum = 0;

        // we will start from the end to get large elememts into our sum to make it maximum.
        while (i >= 0)
        {

            // satisfies the condition.
            if (arr[j] - arr[i] < K)
            {
                sum += arr[j];
                sum += arr[i];
                i -= 2;
                j -= 2;
            }
            // try next pair.
            else
            {
                i--;
                j--;
            }
        }

        return sum;
    }
};