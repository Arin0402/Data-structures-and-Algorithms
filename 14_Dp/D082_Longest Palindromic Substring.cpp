#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/

// 1
// expand froom center
class Solution
{
public:
    int expandAroundCenter(string s, int left, int right)
    {

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s)
    {

        if (s.size() < 1)
            return "";

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++)
        {

            int len1 = expandAroundCenter(s, i, i);     // "xyz"
            int len2 = expandAroundCenter(s, i, i + 1); // "xyyz"

            int len = max(len1, len2);

            if (len > end - start + 1)
            {

                start = i - (len - 1) / 2;
                end = i + (len) / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
