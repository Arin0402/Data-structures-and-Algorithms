#include <bits/stdc++.h>
using namespace std;

// Vertical scanning.
// TC - O(n* minLength of prefix)
class Solution1
{
public:
    string longestCommonPrefix(vector<string> &str)
    {

        string pre = "";

        for (int i = 0; i < str[0].size(); i++)
        {

            for (int j = 1; j < str.size(); j++)
            {

                if (str[j][i] != str[0][i])
                    return pre;
            }

            pre += str[0][i];
        }

        return pre;
    }
};

class Solution2
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string smallestString = strs[0], largestString = strs[0];

        int n = strs.size();

        // To find the lexographically smallest and the largest string in the vector.
        // We could also sort the vector but it would be costly.
        for (int i = 0; i < n; ++i)
        {

            if (smallestString.compare(strs[i]) > 0)
            {
                smallestString = strs[i];
            }
            if (largestString.compare(strs[i]) < 0)
            {
                largestString = strs[i];
            }
        }

        string first = smallestString;
        string last = largestString;
        int c = 0;

        // compare the two substrings.
        while (c < first.size())
        {
            if (first[c] == last[c])
                c++;
            else
                break;
        }
        return c == 0 ? "" : first.substr(0, c);
    }
};

// Solution 3;
// Can also be done using Trie - love Babbar's video.
// But the time complexity of that solution is O(m*n) and SC is O(m*n) than the above solutions.
