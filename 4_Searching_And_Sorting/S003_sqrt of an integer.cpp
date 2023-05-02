#include <bits/stdc++.h>
using namespace std;

// 1
// start from 1 and check if the square is less than or equal to N.
// return count.

// 2
// use sqrt function.

class Solution
{
public:
    int countSquares(int N)
    {

        return (int)sqrt(N - 1);
    }
};