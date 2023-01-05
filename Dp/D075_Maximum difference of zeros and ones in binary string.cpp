#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

// Based on Kadane's algorthm
class Solution
{
public:
    int maxSubstring(string S)
    {

        int n = S.size();

        // check for this condition -> In the case of all 1s, the answer will be -1.
        bool hasZero = false;
        for (int i = 0; i < n; i++)
        {
            if (S[i] == '0')
            {
                hasZero = true;
                break;
            }
        }
        if (hasZero == false)
            return -1;

        // Appling kadane's algorithm.
        // considering 1's as -1 and 0's as 1.
        int maxSum = 0;
        int temp = 0;

        for (int i = 0; i < n; i++)
        {

            if (S[i] == '1')
            {
                temp += -1;
            }
            else
                temp += 1;

            maxSum = max(maxSum, temp);

            if (temp < 0)
                temp = 0;
        }

        return maxSum;
    }
};