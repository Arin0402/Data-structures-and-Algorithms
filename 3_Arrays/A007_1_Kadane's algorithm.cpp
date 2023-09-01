#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Q. Is Kadane’s algorithm Dynamic Programming?
// A. Yes, It is an iterative dynamic programming algorithm.

// Kadane's Algorithm can be viewed both as greedy and DP.
// As we can see that we are keeping a running sum of integers and when it becomes less than 0, we reset it to 0 (Greedy Part).
// This is because continuing with a negative sum is way worse than restarting with a new range.
// Now it can also be viewed as a DP, at each stage we have 2 choices: Either take the current element and continue with the previous sum OR restart a new range.
// Both choices are being taken care of in the implementation.

// Q. What should be the maximum subarray sum if all the elements of the array are negative?
// A. It depends if we are considering empty subarray or not. If we consider an empty subarray then the output should be 0 else, the output should be the maximum element of the array(the element closest to 0).

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {

        int sum = 0;       // temporary sum.
        int maxi = arr[0]; // maximim sum.

        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0; // Order does not matter, it can be at starting as well.
        }

        return maxi;
    }
};

// Note:
// For finding the minimum subarray sum, multiply all the numbers by -1 and apply kadane's algo.
// multiply the result by -1 to get the required result.
// OR we can do just the reverse of the above code.

class Solution
{
public:
    int smallestSumSubarray(vector<int> &arr)
    {

        int n = arr.size();
        int sum = 0;
        int mini = arr[0];

        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
            mini = min(mini, sum);

            if (sum > 0)
                sum = 0;
        }

        return mini;
    }
};

// !--------------------------------IMP----------------------------!

// maximum subarray sum without using the kadane's algorithm with O(n) TC and O(1) SC.

class Solution{ 
    public:
    
    long long maxSubarraySum(int arr[], int n){
        
        // total sum till the ith index.
        long long int prefixSum = 0;
        
        // minimum sum till the ith index.
        long long int minPrefix = 0;
        
        // result
        long long int ans = arr[0];
        
        // run a loop for n elements
        for(int i = 0; i < n; i++ ){
            
            // add the current element to the total sum
            prefixSum += arr[i];
            
            // to get the maximum answer, we would substract the sum till now - the minimum subarray sum before
            ans = max(ans, prefixSum - minPrefix );
            
            // update the minimum subarray sum.
            minPrefix = min(minPrefix, prefixSum);
            
        }
        
        // return the answer
        return ans;
    }
};

// !------------------------------------IMP----------------------------!

// printing the subbarray having the maximum sum

int main(){
        
    int n;
    int arr[n];

    // maximum sum
    int ans = arr[0];

    // prefix sum till ith index
    int prefSum = 0;

    // minimum prefix sum till ith index
    int minPrefSum = 0;
    
    // kahaMila -> index at which the minimum subarray is found
    int kahaMila = -1, L = -1, R = -1;

    for(int i = 0; i < n ; i++){
        
        // add to the prefix sum
        prefSum += arr[i];

        // found maximum subarray
        if(prefSum - minPrefSum > ans){
            
            // update the value
            ans = prefSum-minPrefSum;

            // update the indexes
            R = i;
            L = kahaMila +1;
        }
        if(prefSum < minPrefSum){
            
            // update the minimum prefix sum
            minPrefSum = prefSum;

            // update the index
            kahaMila = i;
        }
        
    }

    // printitng the subarray
    for(int i=L ; i<=R; i++) std::cout<<arr[i]<<" ";
    
}