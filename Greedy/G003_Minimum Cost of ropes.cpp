#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1.

class Solution
{

public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {

        // this will help to get the minimum elements at the top.
        priority_queue<long long, vector<long long>, greater<int>> pq;

        // push all the lengths in pq.
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        long long cost = 0;

        // while there are at least 2 elements.
        while (pq.size() > 1)
        {

            long long first = pq.top(); // first minumum element.
            pq.pop();

            long long int second = pq.top(); // second minumum element.
            pq.pop();

            cost += first + second; // sum of their lengths.

            pq.push(first + second); // push it back , as it wiil added to another cost.
        }

        return cost;
    }
};
