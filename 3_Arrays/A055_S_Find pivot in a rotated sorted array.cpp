#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

class Solution{
public:
    int findMin(int arr[], int n){
        
        int low = 0;
	    int high = n-1;
	    
	    while(low <= high){
	        
	        int mid = low + (high - low)/2;
	        
	        if(arr[mid] > arr[mid +1]) return arr[mid+1];
	        else if(arr[mid] < arr[high]) high =  mid;
	        else low = mid + 1;
	        
	    }
	    
	    return arr[0];
    }
};
