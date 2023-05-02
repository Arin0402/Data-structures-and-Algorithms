#include <bits/stdc++.h>
using namespace std;

// 1
// Naive - Traverse through all the sub arrays.
// O(n^2);


// 2
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
	        maxVal = max((long long)arr[i], maxVal * arr[i]);
	        minVal = min((long long)arr[i], minVal * arr[i]);

	        // Max Product of array.
	        maxProduct = max(maxProduct, maxVal);
	    }

	    // Return maximum product found in array.
	    return maxProduct;
	}
};