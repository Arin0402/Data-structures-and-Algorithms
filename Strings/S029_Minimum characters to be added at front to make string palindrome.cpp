#include <bits/stdc++.h>
using namespace std;

// 1
// naive
// start checking if the string is palindromic or not by deleting last character each time.
// if we found the substring return the length which is = n - length of substring.
// TC - O(N^2)

// 2
// using LPS array
class Solution
{
public:
    // To get the lps of an array.
    vector<int> lpsArray(string str)
    {

        int n = str.size();

        vector<int> lps(n, 0);

        lps[0] = 0;

        int i = 1;
        int j = 0;

        while (i < n)
        {

            if (str[i] == str[j])
            {

                lps[i] = j + 1;
                i++;
                j++;
            }
            else if (j == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                j = lps[j - 1];
        }

        return lps;
    }

    int minChar(string str)
    {

        // main idea is to find the longest palindromic substring from the starting index.
        // then subtract the string length from this length.

        string revstr = str; // reversed string.
        reverse(revstr.begin(), revstr.end());

        vector<int> lps;
        lps = lpsArray(str + revstr);

        // the last index of the lps array will give the longest palindromic subtring from the start.

        return str.length() - lps.back();
    }
};
