#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

// 1
// Naive - Traverse through all the sub arrays.
// O(n^2);

// 2
// very simple
// - the idea is to find the two maximum product subarray  
// - first is starting from 0 till the end
// - second is starting from end till 0
// - the final answer would be the maximum of two
// - this is done so beacuse if we have an odd number of negative integers, then the answer would lie either to the left or 
// to the right of any one negative integer.
// if the we have even number of neagative integers, then it would by default result in positive integer.
// if at any point the product becomes zero, we reinitialize it with one.
// if required -https://www.youtube.com/watch?v=hnswaLJvr6g
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int maxi1 = nums[0];
        int maxi2 = nums[n-1];

        int temp1 = 1;
        int temp2 = 1;

        for(int i = 0; i < n; i++){

            temp1 = temp1*nums[i];
            temp2 = temp2*nums[n-1-i];

            maxi1 = max(maxi1, temp1);
            maxi2 = max(maxi2, temp2);

            if(temp1 == 0) temp1 = 1;
            if(temp2 == 0) temp2 = 1;

        }

        return max(maxi1, maxi2);
    }
};


// 3
// complex, do not tell this in an interview
// https://www.youtube.com/watch?v=tHNsZHXnYd4
class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // Variables to store maximum and minimum
	    // product till ith index.
	    long long minVal = arr[0];
	    long long maxVal = arr[0];

	    long long maxProduct = arr[0];

	    for (int i = 1; i < n; i++) {

	        // When multiplied by -ve number,
	        // maxVal becomes minVal
	        // and minVal becomes maxVal.
	        if (arr[i] < 0) swap(maxVal, minVal);

	        // maxVal and minVal stores the
	        // product of subarray ending at arr[i].

			// compairing it with arr[i] as we can start a new subarray from ith index.
	        maxVal = max((long long)arr[i], maxVal * arr[i]);
	        minVal = min((long long)arr[i], minVal * arr[i]);

	        // Max Product of array.
	        maxProduct = max(maxProduct, maxVal);
	    }

	    // Return maximum product found in array.
	    return maxProduct;
	}
};

