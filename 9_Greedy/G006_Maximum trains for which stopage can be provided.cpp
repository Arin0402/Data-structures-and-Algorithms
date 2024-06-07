// https://www.geeksforgeeks.org/problems/maximum-trains-for-which-stoppage-can-be-provided/1

#include <bits/stdc++.h>
using namespace std;

// This solution is correct . The test cases on gfg are wrong.
// O(mlogm)

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {

        return a[1] < b[1];
    }

    int maxStop(int n, int m, vector<vector<int>> &trains)
    {

        // this will store the departure time for each station.
        vector<int> stations(n + 1, -1);

        // sort the trains on the basis of departure time.
        sort(trains.begin(), trains.end(), cmp);

        int ans = 0;

        for (int i = 0; i < m; i++)
        {

            int stationNumber = trains[i][2];
            int arrival = trains[i][0];
            int depart = trains[i][1];

            if (arrival >= stations[stationNumber])
            {
                ans++;
                stations[stationNumber] = depart; // update the departure time for each station.
            }
        }

        return ans;
    }
};
