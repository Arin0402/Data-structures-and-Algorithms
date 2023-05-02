#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Brute(string haystack, string needle)
    {
        int ptr = 0;

        if (haystack.size() < needle.size())
            return -1;

        while (ptr <= haystack.size() - needle.size())
        {

            if (haystack[ptr] == needle[0])
            {

                bool found = true;

                for (int i = 0; i < needle.size(); i++)
                {
                    if (haystack[ptr + i] != needle[i])
                    {
                        found = false;
                        break;
                    }
                }

                if (found)
                    return ptr;
            }

            ptr++;
        }

        return -1;
    }

    // KMP algo. //https://www.youtube.com/watch?v=JoF0Z7nVSrA
    int strStr(string haystack, string needle)
    {

        int n = haystack.size();
        int m = needle.size();

        if (m == 0 || m > n)
            return -1;

        int prevLps = 0;
        int i = 1;

        vector<int> lps(m, 0);

        while (i < m)
        {

            if (needle[i] == needle[prevLps])
            {
                lps[i] = prevLps + 1;
                prevLps += 1;
                i += 1;
            }
            else if (prevLps == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                prevLps = lps[prevLps - 1];
        }

        i = 0;     // ptr for haystack;
        int j = 0; // ptr for needle;

        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else if (j == 0)
                i++;

            else
                j = lps[j - 1];

            if (j == m)
                return i - m;
        }

        return -1;
    }
};