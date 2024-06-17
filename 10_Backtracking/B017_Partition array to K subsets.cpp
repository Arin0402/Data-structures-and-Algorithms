#include <bits/stdc++.h>
using namespace std;

// 1
// TC -  O(k^N) -> for each element, we have k choices as we can put that element into any of the bucket .
// SC - O(N)
class Solution
{
public:
    int totalSum(int a[], int n, int k)
    {

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += a[i];

        return sum;
    }

    bool helper(int ind, int target, int n, int k, int a[], vector<int> &sums)
    {

        if (ind == n)
        {
            return true;
        }

        for (int i = 0; i < k; i++)
        {

            sums[i] += a[ind];

            if (sums[i] > target)
            { // greater than target, not possible.
                sums[i] -= a[ind];
                continue;
            }

            if (helper(ind + 1, target, n, k, a, sums))
                return true;
            sums[i] -= a[ind];

            // This is important case.
            // for a subset if is empty, then we will add the element to the sums[i]
            // ans recur.
            // we will not try any other empty subset after this.
            // beacuse  1 | _ | _  is same as _ | 1 | _ && _ | _ | 1.
            // sinsce we are filling in sequential manner,
            // once we get an empty subset, subsets after that will also be empty. so break

            if (sums[i] == 0)
                break;
        }

        return false;
    }

    bool isKPartitionPossible(int a[], int n, int k)
    {

        int total = totalSum(a, n, k);

        if (total % k != 0)
            return false; // unable to divide.

        int target = total / k;

        vector<int> sums(k); // to store the sum of each subset.

        return helper(0, target, n, k, a, sums);
    }
};
