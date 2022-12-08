#include <bits/stdc++.h>
using namespace std;

// 1

class Solution
{
public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
    {

        // idea is to remove the top element of the stack for which the sum is maximum among the three.

        // calculate the sum of the three stacks.
        int sum1 = 0, sum2 = 0, sum3 = 0;

        for (int i = 0; i < N1; i++)
            sum1 += S1[i];
        for (int i = 0; i < N2; i++)
            sum2 += S2[i];
        for (int i = 0; i < N3; i++)
            sum3 += S3[i];

        // pointers.
        int p1 = 0, p2 = 0, p3 = 0;

        while (true)
        {

            // same sum.
            if (sum1 == sum2 && sum2 == sum3)
                return sum1;

            // pointers out of bound, so sum is zero.
            if (p1 >= N1 || p2 >= N2 || p3 >= N3)
                return 0;

            // sum1 is maximum.
            if (sum1 >= sum2 && sum1 >= sum3)
            {
                sum1 -= S1[p1++];
            }
            // sum2 is maximum.
            else if (sum2 >= sum1 && sum2 >= sum3)
            {
                sum2 -= S2[p2++];
            }
            // sum3 is maximum.
            else
                sum3 -= S3[p3++];
        }
    }
};