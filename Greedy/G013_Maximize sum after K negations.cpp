#include <bits/stdc++.h>
using namespace std;

// 1
// O(nlogn)
class Solution
{
public:
    long long int total(int ind, long long int a[], int n, int k)
    {

        long long int sum = 0;

        for (int i = ind; i < n; i++)
            sum += a[i];

        return sum;
    }

    long long int maximizeSum(long long int a[], int n, int k)
    {

        sort(a, a + n);

        int i = 0;

        long long int sum = 0;

        for (int i = 0; i < n; i++)
        {

            // current element is positive so the remaining will also be positive.
            if (a[i] >= 0)
            {

                // we have to spend all the operations on this current element.
                if (k % 2 == 0)
                    sum += total(i, a, n, k);
                else
                    sum += -1 * a[i] + total(i + 1, a, n, k);

                break;
            }
            // last element of the array and operations are still left.
            // so we have to spend all the operations on this current element.
            else if (i == n - 1)
            {

                if (k % 2 == 0)
                    sum += a[i];
                else
                    sum += -1 * a[i];
            }
            // negative element.
            else
            {

                // operations are left so make element positive.
                if (k > 0)
                {
                    sum += -1 * a[i];
                    k--;
                }

                // operations are over , so add the remaining elements.
                else
                    sum += a[i];
            }
        }

        return sum;
    }
};