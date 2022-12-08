#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=5MeI5Kk8KTQ
// get intutiion by this video.


// 1
// segregate positive and negative numbers into two arrays.
// and then simple update the array by iterating. 

// 2
// O(N^2)
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
    
    void print(int arr[], int n){
        
        for(int i =0 ; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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