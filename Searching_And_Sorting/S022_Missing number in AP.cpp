#include <bits/stdc++.h>
using namespace std;

// find missing number in an arithmetic progression.

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {

        // A  - first term
        // B - number to be checked
        // C - difference.

        if (C == 0)
            return (B == A);

        return ((B - A) % C == 0 && (B - A) / C >= 0);
    }
};