#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

// O(nlogn)
// N meetings in a room problem
class Solution
{
public:
    bool cmp(pair<int, int> a, pair<int, int> b)
    {

        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {

        // make vector having starting time and ending time.
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++)
        {

            vec.push_back({start[i], end[i]});
        }

        // sort the vector based on ending time.
        sort(vec.begin(), vec.end(), cmp);

        int cnt = 1; // starting meeting will take place any how.

        int last = vec[0].second; // ending time of the first meeting.

        for (int i = 1; i < n; i++)
        {

            // if the starting time of the current meeting is greater than the
            // ending time of the last meeting , then it is possible.

            if (vec[i].first > last)
            {

                cnt++;
                last = vec[i].second; // update last.
            }
        }

        return cnt;
    }
};
