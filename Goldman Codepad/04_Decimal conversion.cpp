// https://leetcode.com/problems/fraction-to-recurring-decimal/

/*
Q. why are we converting to long long and where does the intution come for multiplying the remainder by 10

Sol.

In C++, the int type has a limited range:

    int: −2,147,483,648 to 2,147,483,647

    If the input is:

        numerator = -2147483648, denominator = 1

    Taking abs(numerator) as abs(-2147483648) would overflow, because the absolute value (2147483648) is greater than the max positive int.

Q. Why do we multiply the remainder by 10 in the loop?

Sol.

You're simulating how you would manually divide numbers in school.

    Let’s take the example:
    4 ÷ 333

Manually:

    333 goes into 4: 0 times → integer part = 0

    Bring down a 0: 4 becomes 40 → 40 / 333 = 0

    Bring down a 0: 40 becomes 400 → 400 / 333 = 1

    Remainder = 67

    Bring down a 0: 670 / 333 = 2
    ... and so on

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {

        int sign = 1;

        // XOR is true if one is negative
        if ((numerator < 0) ^ (denominator < 0))
            sign = -1;

        string ans = "";

        if (sign == -1 && numerator != 0)
            ans += '-';

        long num = abs((long)numerator);
        long deno = abs((long)denominator);

        // Integer   part
        ans += to_string(num / deno);

        // no remainder
        if (num % deno == 0)
            return ans;

        ans += '.';

        // to keep the track of repeating remainder
        unordered_map<long, int> mp;

        long remainder = num % deno;

        // run unitll we do not find a repeating remainder
        while (remainder != 0)
        {

            if (mp.find(remainder) != mp.end())
            {

                int pos = mp[remainder];
                ans.insert(pos, 1, '(');
                ans += ')';
                break;
            }

            mp[remainder] = ans.size();

            remainder *= 10;
            ans += to_string(remainder / deno);

            remainder %= deno;
        }

        return ans;
    }
};