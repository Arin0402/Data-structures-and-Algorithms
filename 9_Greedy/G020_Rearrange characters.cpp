#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rearrange-characters4649/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// 1
// TC - O(nlogn) (queue opeartions)
// Sc - O(n);

class Solution
{
public:
    string rearrangeString(string str)
    {
        /// idea os to insert the two highest frequency letters together in the new string.

        // count the frequency of letters.
        vector<int> arr(26, 0);

        for (int i = 0; i < str.size(); i++)
        {
            arr[str[i] - 'a']++;
        }

        // to get the highset frequency letter.
        priority_queue<pair<int, char>> pq;

        // push elements.
        for (int i = 0; i < 26; i++)
        {

            if (arr[i] > 0)
            {
                pq.push({arr[i], i + 'a'});
            }
        }

        string res = "";

        // more tha one element in pq.
        while (pq.size() > 1)
        {

            auto p1 = pq.top();
            pq.pop();

            auto p2 = pq.top();
            pq.pop();

            res += p1.second;
            p1.first--; // dercease the frequency.

            res += p2.second;
            p2.first--; // dercease the frequency.

            // if elements still left, then insert again.
            if (p1.first > 0)
                pq.push(p1);
            if (p2.first > 0)
                pq.push(p2);
        }

        // got some left in pq.
        if (!pq.empty())
        {

            // if the frequency is greater than 1 , then it is not possible as it will bring adjacency.
            if (pq.top().first > 1)
            {
                return "-1";
            }
            // frequency is one.
            else
                res += pq.top().second;
        }

        return res;
    }
};
