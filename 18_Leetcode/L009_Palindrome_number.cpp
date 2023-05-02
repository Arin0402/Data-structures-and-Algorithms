#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0 || (x != 0 && x % 10 == 0))
            return false; // case = 5000

        int rev = 0;

        while (x > rev)
        { // if number is palindrome the nthis condidtion will become false
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        return (x == rev || x == rev / 10); // case = 121 or 431134
    }
};