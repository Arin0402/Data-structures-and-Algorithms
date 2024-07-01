#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

// TC  The worst-case time complexity is O(N*2^n), where n is the length of the input string. This is because the algorithm explores all possible partitions, and for each partition, it explores all possible substrings to check if they are palindromes.

class Solution
{
public:
    bool isPalindrome(string s)
    {

        int n = s.size();

        int l = 0;
        int r = n - 1;

        while (l <= r)
        {

            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    void helper(int pos, string &s, vector<string> &temp, vector<vector<string>> &ans, int n)
    {

        if (pos >= n)
        {

            ans.push_back(temp);
            return;
        }

        for (int i = pos; i < n; i++)
        {

            string st = s.substr(pos, i - pos + 1);

            if (isPalindrome(st))
            {

                temp.push_back(st);
                helper(i + 1, s, temp, ans, n);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> allPalindromicPerms(string S)
    {

        vector<vector<string>> ans;
        vector<string> temp;

        int n = S.size();

        helper(0, S, temp, ans, n);

        return ans;
    }
};
