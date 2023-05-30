#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// brute
// try each subarray

// 2
// prefix sum 
// O(N)
// O(N)
class Solution{
public:	
// 	int longSubarrWthSumDivByK(int arr[], int n, int k)
    int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // element -> index
	    unordered_map<int, int> mp;
	    mp[0] = -1;
	    
	    // maximum length
	    int maxi = 0;
	    
	    // prefix sum
	    long long int pref = 0;
	    
	    int rem;
	    
	    for(int i = 0; i < n; i++){
	        
	        // add the current element    
	        pref += arr[i];
	        
	        // calculate the remainder
	        rem = pref%k;
	        
	        // if the remainder is negative then add k to it.
	        // this is done to avoid negative integers.
	        // -rem == k + (-rem)
	        if(rem < 0) rem += k;
	        
	        // remainder we need to substract in order to make prefsum divisible by k is already
	        // present
            if(mp.find(rem) != mp.end()){
	            maxi = max(maxi, i - mp[rem]);
	        }
	        
	        // first time occuring
	        if(mp.find(rem) == mp.end()) mp[rem] = i;
	        
	        // else keep the minimum index as we need the longest possible subarray
	        
	    }
	    
	    return maxi;
	   
	    
	}
};