#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1

// 1
// using extra space
// O(n)
// O(n)
class Solution{
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   vector<int> vec(n);
	   
	   // store the elements.
	   for(int i=0;i<n;i++){
	       vec[i] = arr[(i+k)%n];
	   }
	   
	   // copy the elements.
	   for(int i=0;i<n;i++){
	       arr[i] = vec[i];
	   }
	} 		 
};

// 2
// without using extra space. !------------------IMP----------------!
// reverse algorithm
// O(n)
// O(1)
class Solution{
	public:
	
	// reverse function
	void Reverse(int arr[], int start, int end){
	    
	    while(start < end){
	        
	        arr[start] = arr[start]^arr[end];
	        arr[end] = arr[start]^arr[end];
	        arr[start] = arr[start]^arr[end];
	        
	        start++;
	        end--;
	    }
	    
	}
	void leftRotate(int arr[], int k, int n) 
	{ 
	   
	   k = k%n;
	  
	   // no need to reverse
	   if(k == 0) return;
	   
	    // Reverse first k elements
        Reverse(arr, 0, k - 1);
        // Reverse last n-k elements
        Reverse(arr, k, n - 1);
        // Reverse whole array
        Reverse(arr, 0, n - 1);
	  
	} 
		 

};