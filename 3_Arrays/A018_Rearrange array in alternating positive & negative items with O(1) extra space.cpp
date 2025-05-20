#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/5MeI5Kk8KTQ?t=495
// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
// get intutiion by this video.


// 1
// segregate positive and negative numbers into two arrays.
// and then simple update the array by iterating. 

// 2
// O(N^2)
// only the intution
// code is giving tle

class Solution{
public:
    
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    void rotate(int arr[], int l, int r)
    {
        int t = arr[r];
        
        for (int i = r; i > l; i--){
            swap(&arr[i], &arr[i - 1]);
        }
        
        arr[l] = t;
    }

	void rearrange(int arr[], int n) {
	    
	    int l = 0, r =0;
	    
	    while(l < n && r < n){
	        
	        
	        // index is even 
	        if(l%2 == 0){
	            
	            // element is positive.
	            if(arr[l] >= 0){
	                
	                l++;
	                if(r < l) r++;    
	            }
	            // element is negative.
	            else{
	                
	                r++;
	                while (arr[r] < 0 && r < n ) r++;
	                
	                if( r < n){
	                    
	                    rotate(arr, l, r);
	                    l++;
	                }
	                
	            }
	            
	        }
	        // index is odd.
	        else{
	            
	            if(arr[l] < 0){
	                
	                l++;
	                if(r < l) r++;    
	            }
	            // element is negative.
	            else{
	                
	                r++;
	                while (arr[r] >= 0 && r < n ) r++;
	                
	                if( r < n){
	                    
	                    rotate(arr, l, r);
	                    l++;
	                    
	                }
	                
	            }
	        }
	        
	    }
	    
	}
};