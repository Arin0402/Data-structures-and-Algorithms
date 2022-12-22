#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-string-chain/1?page=1&sortBy=accuracy

// extension of longest increasing subsequence.

// 1
// O(n*n*l) ( l is the size of the string , as we are compairing both the strings)  + O(nlogn)(sorting)
// O(2*n)

class Solution
{
public:
    bool checkPossible(string &s1, string &s2)
    {

        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0;
        int second = 0;

        while (first < s1.size())
        {

            if (s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }

        if (first == s1.size() && second == s2.size())
            return true;
        return false;
    }

    static bool cmp(string &s1, string &s2)
    {

        return s1.size() < s2.size();
    }

    int longestChain(int n, vector<string> &words)
    {

        vector<int> dp(n, 1);

        // sort on the basis of length.
        // we can pick words in any order(subsequence is not necessary)
        sort(words.begin(), words.end(), cmp);

        vector<int> prev(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            vector<int> temp(n + 1, 0);
            for (int j = i - 1; j >= -1; j--)
            {

                int not_take = prev[j + 1];

                int take = 0;

                if (j == -1 || checkPossible(words[i], words[j]))
                {

                    take = 1 + prev[i + 1];
                }

                temp[j + 1] = max(take, not_take);
            }

            prev = temp;
        }

        return prev[-1 + 1];
    }
};
