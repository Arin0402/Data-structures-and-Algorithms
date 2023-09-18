#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/d54c71dc974b7db3a200eb63f34e3d1cba955d86/1

// 1
// run three nested loops

// 2
// O(n)
// Scan the array and compute the Maximum, second maximum, third maximum element, and minimum and second minimum element present in the array, and the answer will always be maximum of product of Maximum, second maximum and third maximum or product of Minimum, second minimum, and Maximum element.

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	
    	long long max1 = LLONG_MIN;
    	long long max2 = LLONG_MIN;
    	long long max3 = LLONG_MIN;
    	
    	long long min1 = LLONG_MAX;
    	long long min2 = LLONG_MAX;
    	long long min3 = LLONG_MAX;
    	
    	for(int i = 0; i < n; i++){
    	    
    	    long long num = arr[i];
    	    
    	   // finding the top 3 maximum numbers
    	   if(num >= max1){
    	       max3 = max2;
    	       max2 = max1;
    	       max1 = num;
    	   }
    	   else if(num < max1 && num >= max2){
    	       max3 = max2;
    	       max2 = num;
    	   }
    	   else if(num < max2 && num >= max3){
    	       max3 = num;
    	   }
    	   
    	   // findind the top 2 minimum numbers
		   
    	   if(num <= min1){
    	       min3 = min2;
    	       min2 = min1;
    	       min1 = num;
    	   }
    	   else if(num  > min1 && num <= min2){
    	       min3 = min2;
    	       min2 = num;
    	   }
    	   else if(num > min2 && num <= min3){
    	       min3 = num;
    	   }
    	    
    	}
    	
    	return max( min1*min2*max1, max1*max2*max3);
    	
    	
    }
};