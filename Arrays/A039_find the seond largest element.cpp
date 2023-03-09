#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest

// 1
// O(N)

// input contains duplicate elements.
// we have to find the distinct second largest element.
// for ex - 10 20 20 , ans is 10.
// second largest element cannot be equal to the largest element

class Solution{
public:	
	// Function returns the second
	// largest elements
		
    int print2largest(int arr[], int n) {

    	int lar = arr[0];
    	int sec = -1;
	    
	    for(int i = 1; i < n; i++){

            // element is greater than the largest element.
	        if(arr[i] > lar){
	            sec = lar; // update second largest.
	            lar = arr[i]; // update largest.
	        }

            // element is lesser than largest and greater than second largest.
	        else if(arr[i] < lar &&  arr[i] > sec) sec = arr[i];
	        
	    }
	    
	    return sec;
	    
	}
};