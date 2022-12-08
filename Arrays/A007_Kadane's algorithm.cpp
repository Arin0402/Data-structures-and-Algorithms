#include <bits/stdc++.h>
using namespace std;

// Q. Is Kadane’s algorithm Dynamic Programming?
// A. Yes, It is an iterative dynamic programming algorithm.

// Kadane's Algorithm can be viewed both as greedy and DP. 
// As we can see that we are keeping a running sum of integers and when it becomes less than 0, we reset it to 0 (Greedy Part).
// This is because continuing with a negative sum is way worse than restarting with a new range.
// Now it can also be viewed as a DP, at each stage we have 2 choices: Either take the current element and continue with the previous sum OR restart a new range.
// Both choices are being taken care of in the implementation.

// Q. What should be the maximum subarray sum if all the elements of the array are negative?
// A. It depends if we are considering empty subarray or not. If we consider an empty subarray then the output should be 0 else, the output should be the maximum element of the array(the element closest to 0).

// Q. What is the time complexity of Kadane’s algorithm?
// A. The time complexity of Kadane’s algorithm is O(N) where N is the size of the array.

class Solution{
    public:
    
    long long maxSubarraySum(int arr[], int n){
        
        int sum = 0; // temporary sum.
        int maxi  = arr[0];    // maximim sum.
        
        for(int i = 0; i < n ; i++){
            
            sum += arr[i];
            maxi = max(maxi, sum);
            
            if(sum < 0) sum = 0; // Order does not matter, it can be at starting as well.
        }
        
        return maxi;
        
    }
};

// Note: 
// For finding the minimum subarray sum, multiply all the numbers by -1 and apply kadane's algo.
// multiply the result by -1 to get the required result.

