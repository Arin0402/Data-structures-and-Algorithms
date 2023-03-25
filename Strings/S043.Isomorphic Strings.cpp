#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        // size not equal
        if (str1.size() != str2.size())
            return false;

        // for mapping the characters
        unordered_map<char, char> mp;
        int n = str1.size();

        // vector to check if the same character is not used more than once for
        // different characters in str1.
        // ex  = py
        //       ff
        vector<int> used(26, 0);

        int i = 0;

        while (i < n)
        {

            char c1 = str1[i]; // character of first array
            char c2 = str2[i]; // character of second array

            // c1 already present in map
            if (mp.find(c1) != mp.end())
            {

                // elements do not match
                if (mp[c1] != c2)
                    return false;
            }
            else
            {

                // the character in c2 is already used for another character in c1
                if (used[c2 - 'a'] == 1)
                    return false;

                // insert in map
                mp[c1] = c2;

                // update
                used[c2 - 'a'] = 1;
            }

            i++;
        }

        return true;
    }
};