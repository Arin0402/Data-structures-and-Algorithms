#include <bits/stdc++.h>
using namespace std;

// similar to S028 (smallest distinct window) .

// 1
// generate all the substrings and check.
// O(n^2)

// 2
// sliding window technique.
// TC- O(N)
// Sc- O(1) (constant space)

class Solution
{
public:
    // similar to Write a program tofind the smallest window that contains all characters of string itself.
    // shrinking window.
    string smallestWindow(string s, string p)
    {
        // to check which characters are present in p and what are thier frequencies.
        vector<int> isPresent(26, 0);

        for (int i = 0; i < p.size(); i++)
        {
            isPresent[p[i] - 'a']++;
        }

        // store the frequencies of the characters which are present in p;
        vector<int> freq(26, 0);

        int cnt = 0; // nubmber of characters in the current window.
        int total = p.size();

        int mini = INT_MAX;

        string ans = "-1";

        int i = 0, j = 0;

        while (i <= j && j < s.size())
        {

            char c = s[j];

            // less than total.
            if (cnt < total)
            {

                // only if the element is present in p.
                if (isPresent[c - 'a'] > 0)
                {

                    // increase count only when the current frequency of the character is less than
                    // it's total frequency.
                    // this for handling duplicataes.
                    if (freq[c - 'a'] < isPresent[c - 'a'])
                        cnt++;

                    freq[c - 'a']++;
                }

                j++;
            }
            else if (cnt == total)
            {

                c = s[i]; // character will be from starting.

                if (j - i < mini)
                { // got smaller window.

                    ans = s.substr(i, j - i);
                    mini = j - i;
                }

                // only if present.
                if (isPresent[c - 'a'] > 0)
                {

                    // if frequencies are same , then decrease count.
                    if (freq[c - 'a'] == isPresent[c - 'a'])
                        cnt--;

                    freq[c - 'a']--;
                }
                i++;
            }
        }

        // check for the last window.
        while (cnt == total)
        {

            char c = s[i];

            if (j - i < mini)
            {

                ans = s.substr(i, j - i);
                mini = j - i;
            }

            if (isPresent[c - 'a'] > 0)
            {

                if (freq[c - 'a'] == isPresent[c - 'a'])
                    cnt--;
                freq[c - 'a']--;
            }
            i++;
        }

        return ans;
    }
};
