#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=eiM8LGi4h_g

// 1;
// naive
// pick time slots one by one and check with other time intervals that how many overlap with this time interval.
// do it for every time interval.
// keep the max count.
// O(n^2)

// 2
// using priority queue
// TC - O(nlogn)
// Sc - O(n)
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {

        priority_queue<int, vector<int>, greater<int>> pq;

        vector<pair<int, int>> time;

        for (int i = 0; i < n; i++)
        {

            time.push_back({arr[i], dep[i]});
        }

        // sort the array on the basis of arrival time as we will assign stations to the
        // which will come first.

        sort(time.begin(), time.end());

        // minimum on estation will be required.
        int minStations = 1;

        // insert the departure time of the first train.
        pq.push(time[0].second);

        for (int i = 1; i < n; i++)
        {

            // the arrival time is greater then the departure time, so that train will leave
            // and the current train will occupy that station.
            if (time[i].first > pq.top())
            {
                pq.pop();
            }
            // else we will be required new station.
            else
                minStations++;

            // insert the departure time of the current train.
            pq.push(time[i].second);
        }

        return minStations;
    }
};

// 3
// using two pointer approach
// TC - O(nlogn)

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.

    int findPlatform(int arr[], int dep[], int n)
    {
        // we will assign the trains on the basis of their arrival.
        sort(arr, arr + n);

        // the arrived train will look for for the train taht will depart first
        // so sort the departure array.
        sort(dep, dep + n);

        int minStations = 1;

        int i = 1;
        int j = 0;

        while (i < n)
        {

            // arrival time is greater than departure, so increment the j counter.
            if (arr[i] > dep[j])
            {
                j++;
            }
            // departure time os greater, so station is required.
            else
                minStations++;

            i++;
        }

        return minStations;
    }
};
