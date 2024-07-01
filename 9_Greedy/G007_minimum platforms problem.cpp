#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// https://www.youtube.com/watch?v=AsGzwR_FWok&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=10

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

        // minimum station will be required.
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

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        
        sort(arr, arr + n);
        sort(dep, dep + n);
    	
    	// final platforms required
    	int ans = 1;
    	
    	// platforms required at any instance
    	int platforms = 1;
    	
    	// right pointer
    	int i = 1; 
    	
    	// left pointer
    	int j = 0;
    	
    	while(i < n){
    	    
    	    // the arrival time is less than the departure time of the train at index j
    	    // so platform will be required
    	    if(arr[i] <= dep[j]){
    	        i++;
    	        platforms++;
    	    }
    	    
    	    // departure time of the train at index j is less than the arrival time 
    	    // of the train at the index i
    	    // so this train will leave vacating the station
    	    else{
    	        j++;
    	        
    	        // platform will be freed
    	        platforms--;
    	    }
    	    
    	    // update the maximum
    	    ans = max(ans, platforms);
    	    
    	}
    	
    	return ans;
    	
    }
};
