#include <bits/stdc++.h>
using namespace std;

// 1
// use of recursion and try all the possible ways.
// expontential time complexity.

// 2
// we can try starting from distance 1 upto the maximum distance that is possible (i.e maximum element - minimum element).
// for each distance we will run a for loop to check if that distance is valid or not.
// so the TC will be O(n*n);

// 3
// since the distances are in increasing fashion , we can apply binary search.
// our low wil be minimum distance possible i.e 1.
// high will be maximum distance possible.
// try for the distances using binary search.
class Solution
{
public:
    bool canPlaceCows(vector<int> &v, int n, int k, int dis)
    {

        // number of cows placed.
        int cnt = 1;

        // current index of cow placed.
        int currInd = 0;

        for (int i = 1; i < n; i++)
        {

            // distance between the two indexes is greater than or equal to the required distance.
            if (v[i] - v[currInd] >= dis)
            {
                cnt++;       // cow placed.
                currInd = i; // update index.
            }
            // all cows are placed, so it is possible.
            if (cnt == k)
                return true;
        }

        return false;
    }

    int solve(int n, int k, vector<int> &v)
    {

        // sort the positions.
        sort(v.begin(), v.end());

        int low = 1;
        int high = v[n - 1] - v[0];

        // maximum distance.
        int res = 0;

        // binary search
        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            // distance is valid.
            if (canPlaceCows(v, n, k, mid))
            {
                res = mid; // store this distance nad check for greater distance.
                low = mid + 1;
            }
            // not possible so decrease the distance.
            else
                high = mid - 1;
        }

        return res;
    }
};
