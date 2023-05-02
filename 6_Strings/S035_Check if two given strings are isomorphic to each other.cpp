#include <bits/stdc++.h>
using namespace std;

// 1
// TC - O(N)
// SC - O(N)

class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        int n1 = str1.size(); // size of first string.
        int n2 = str2.size(); // size of second string.

        if (n1 != n2)
            return false; // size are not same, not possible.

        unordered_map<char, char> mp; // map elements of str1 to the elements of str2.

        // we will check if the element of str2 has already been used or not.
        // case when two different elements of str1 have same element at their index in str2.
        // ex pijfy  ( here p and y points to f).
        //    fvkmf
        vector<bool> isUsed(26, false);

        for (int i = 0; i < n1; i++)
        {

            char c1 = str1[i];
            char c2 = str2[i];

            // c1 is present.
            if (mp.find(c1) != mp.end())
            {

                // both the characters are not same so return false.
                if (mp[c1] != c2)
                    return false;
            }
            else
            {

                // if c2 is already used , return false.
                if (isUsed[c2 - 'a'] == true)
                    return false;

                mp[c1] = c2;             // map it.
                isUsed[c2 - 'a'] = true; // upadte.
            }
        }

        return true;
    }
};