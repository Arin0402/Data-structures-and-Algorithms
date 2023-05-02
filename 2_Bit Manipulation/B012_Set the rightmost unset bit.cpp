#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1


// The idea is x|(x+1) sets the lowest(rightmost) unset bit but it may set a leading zero bit if the given number doesn’t contain any unset bits , for example 

// if all bits set
// 15 is  1111 = 00001111 
// 16 is 10000 = 00010000
//              _________
// x|(x+1)       00011111
// on performing x|(x+1) it converts to 00011111 
// but here we should only consider only 1111 and return 1111 as there are no unset bits.

// else 
// 13 is 1101 = 00001101
// 14 is 1110 = 00001110
//             _________
// x|(x+1)      00001111
// on performing x|(x+1) it converts to 00011111 which is required number.

// So we can eliminate this type of redundant operation by checking if there are any zeroes in the given number. We observe only number whose all bits set are of form 2k -1 have no unset bits in them so by catching these number we can perform our idea.

// TC - O(1)
class Solution
{
public:
    int setBit(int n)
    {
        
        // if all bits of 'n' are set
        // the number is of form 2^k -1 return n
        if ((n & (n + 1)) == 0)
            return n;
        // else
        return n | (n + 1);
        
    }
};