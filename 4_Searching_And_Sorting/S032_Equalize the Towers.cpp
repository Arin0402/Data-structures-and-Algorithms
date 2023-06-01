#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/equalize-the-towers2804/1?page=2&category[]=Binary%20Search&sortBy=difficulty


// This is a special binary search problem in which we cannot determine which side to go 
// after calculating the cost for the mid height
// so we will also calculate the cost for mid -1 height and mid + 1 height

// if we find all the cost from height 0 to the maximum height, the costs will be 
// either in the all decreasing fashion
// or in all increasing fashion
// or decreasing then increasing or vice versa

// for ex-
// 5
// 9 12 18 3 10
// 100 110 150 25 99

// the costs from the height 0 to 18 are
// 5985 5501 5017 4533 4099 3665 3231 2797 2363 1929 1695 1659 1623 1807 1991 2175 2359 2543 2727
// these are first decreasing and then increasing
// so the answer is 1623


class Solution{

	public:
	    
	// calculate the height for a particular height
	long long int calculateCost(int height, int h[], int cost[], int n){
	    
	    long long int ans = 0;
	    
	    for(int i = 0; i < n; i++) ans += abs(h[i] - height)*cost[i];
	    
	    return ans;
	}
	
	long long int Bsearch(int n, int h[], int cost[]) 
	{ 
	    // minimum height possible is zero
		long long int low = 0;
		
		// maximum height possible is largest height
		long long int high = *max_element(h, h + n);
		
		// answer
		long long int ans = LONG_LONG_MAX;
		
		while(low >= 0 && low <= high){
		    
		    long long mid = low + (high - low)/2;
		    
		    // cost at height mid - 1
		    long long int CostAtHeightLessThanMid = calculateCost(mid-1, h, cost, n);
		    
		    // cost at height mid 
		    long long int CostAtMid = calculateCost(mid, h, cost, n);
		    
		    // cost at height mid + 1
		    long long int CostAtHeightGreaterThanMid = calculateCost(mid+1, h, cost, n);
		    
		    // update minimum
		    ans = min(ans,CostAtMid);
		    
		    // left part has less cost
		    if(CostAtHeightLessThanMid <= CostAtMid) high = mid - 1;
		    
		    // right part has less cost
		    else if (CostAtHeightGreaterThanMid <= CostAtMid) low = mid + 1;
		    
		    // mid height is giving the least cost.
		    else break;
		}
		
		return ans;
		
	}		 
};
	  
