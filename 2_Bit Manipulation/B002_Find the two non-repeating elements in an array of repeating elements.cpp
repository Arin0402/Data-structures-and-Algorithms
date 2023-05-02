#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
// https://www.youtube.com/watch?v=pnx5JA9LNM4

// 1
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        int xor_of_all = 0;
        for (auto ele : nums)
            xor_of_all ^= ele;

        /* Get the rightmost set bit in set_bit_no */
        int set_bit_no = xor_of_all & ~(xor_of_all - 1);

        int xor1 = 0, xor2 = 0;

        for (auto ele : nums)
        {

            if (ele & set_bit_no)
                xor1 = xor1 ^ ele;
            else
                xor2 = xor2 ^ ele;
        }

        if (xor1 < xor2)
            return {xor1, xor2};
        else
            return {xor2, xor1};
    }
};

// or

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        int xor_of_all = 0;

        for (auto ele : nums)
            xor_of_all ^= ele;
        

        int ind_of_right_bit = 0;

        while (xor_of_all)
        {            
            if ((xor_of_all & 1) == 0)
            {
                ind_of_right_bit++;
            }
            else
                break;

            xor_of_all >>= 1;
        }        

        int xor1 = 0, xor2 = 0;

        for (auto ele : nums)
        {

            if ((ele & (1 << ind_of_right_bit)) == 0)
                xor1 = xor1 ^ ele;
            else
                xor2 = xor2 ^ ele;
        }

        if (xor1 < xor2)
            return {xor1, xor2};
        else
            return {xor2, xor1};
    }
};