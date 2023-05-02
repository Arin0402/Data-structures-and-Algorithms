#include <bits/stdc++.h>
using namespace std;

// 1
// O(nlogn) (sorting)

class Solution
{
public:
    static bool cmp(pair<int, char> a, pair<int, char> b)
    {

        return a.first > b.first;
    }

    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
    {

        // when the pieces are less, we would use the highest cost to cut.
        // this will be the most optimal as vice versa is not optimal.

        vector<pair<int, char>> arr;

        for (int i = 0; i < M - 1; i++)
        {
            arr.push_back(make_pair(X[i], 'V'));
        }

        for (int i = 0; i < N - 1; i++)
        {
            arr.push_back(make_pair(Y[i], 'H'));
        }

        // sort on the basis of cost.
        sort(arr.begin(), arr.end(), cmp);

        // denoting the quantity of pieces in these directions.
        int hori = 1;
        int vert = 1;

        int cost = 0;

        for (int i = 0; i < M + N - 2; i++)
        {

            auto p = arr[i];

            int val = p.first;
            char direc = p.second;

            // if we make a cut in horizontal direction, the pieces
            // in vertical direction will increase by one.
            if (direc == 'H')
            {

                cost += hori * val; // multilpy by the number of pieces in horizontal direction.
                vert++;
            }
            else
            {

                cost += vert * val;
                hori++;
            }
        }

        return cost;
    }
};