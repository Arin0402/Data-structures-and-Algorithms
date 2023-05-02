#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {

        int i = 0;

        while (s[i] == ' ')
            i++; // check for white spaces in the starting.

        int sign = 1;

        if (s[i] == '-' || s[i] == '+')
        {                                   // checks for the sign , only at the beginning.
            sign = 1 - 2 * (s[i++] == '-'); // 1 - 2*(true or false)
        }

        int base = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {

            if (base > INT_MAX / 10 || base == INT_MAX / 10 && (s[i] - '0') > 7)
            {
                if (sign == 1)
                    return INT_MAX;

                return INT_MIN;
            }

            base = 10 * base + (s[i++] - '0');
        }

        return base * sign;
    }
};