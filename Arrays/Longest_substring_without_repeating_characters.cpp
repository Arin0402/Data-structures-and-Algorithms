// https://www.youtube.com/watch?v=qtVh-XEpsJo
// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLen = 0, left = 0, right = 0;
        int n = s.size();
        vector<int> mp(256, -1);

        while (right < n)
        {
            if (mp[s[right]] != -1)
                left = max(mp[s[right]] + 1, left);

            maxLen = max(maxLen, right - left + 1);
            mp[s[right]] = right;
            right++;
        }
        return maxLen;
    }
};