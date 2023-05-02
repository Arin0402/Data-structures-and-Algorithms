#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/set-bits0143/1

// 1
// O(logn) (logn represents the number of bits in a number n)'
// simple
// right shift n by 1 and count.
class Solution
{
public:
    int setBits(int N)
    {

        int count = 0;

        while (N != 0)
        {

            if (N & 1 == 1)
                count++;

            N >>= 1;
        }

        return count;
    }
};

// 2
// Brian Kerninghan algorithm
// remove the right most bit one by one untill N becomes zero.
class Solution
{
public:
    int setBits(int N)
    {

        int count = 0;

        while (N != 0)
        {

            count++;
            N = (N) & (N - 1);
        }

        return count;
    }
};