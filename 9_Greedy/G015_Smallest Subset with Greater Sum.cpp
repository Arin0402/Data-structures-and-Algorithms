#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubset(vector<int> &Arr, int N)
    {

        sort(Arr.begin(), Arr.end());

        long long leftTotal = 0;

        for (int i = 0; i < N - 1; i++)
            leftTotal += Arr[i];

        int count = 1;
        long long rightTotal = Arr[N - 1];

        for (int i = N - 2; i >= 0; i--)
        {

            if (rightTotal > leftTotal)
                return count;

            count++;
            leftTotal -= Arr[i];
            rightTotal += Arr[i];
        }

        return count;
    }
};