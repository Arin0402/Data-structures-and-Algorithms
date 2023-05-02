#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

// 1
// same as previous word break problem. just dont break out of the loop.
//  O(2^n)

// can also use trie instead of map
class Solution
{
public:
    void helper(int pos, string temp, unordered_map<string, int> &mp, vector<string> &ans, int wordSize, string &s)
    {

        if (pos >= wordSize)
        {

            int n = temp.size();
            ans.push_back(temp.substr(0, n - 1));
            return;
        }

        for (int i = pos + 1; i <= wordSize; i++)
        {

            string st = s.substr(pos, i - pos);

            if (mp[st] > 0)
            {
                helper(i, temp + st + " ", mp, ans, wordSize, s);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {

        // map to store the occurence
        unordered_map<string, int> mp;

        for (auto ele : dict)
            mp[ele]++;

        vector<string> ans;

        helper(0, "", mp, ans, s.size(), s);

        return ans;
    }
};