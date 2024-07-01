#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

// 1
// generate all the subarrays and find the minimum element in then
// O(N^3)

// 2
// O(N)
// o(N)
// find the index of next smaller element on left for every index
// find the index of the next smaller element on the the right for every index

// by this we will get the number of contiguous elements greater than the index on both left and right side.
// to calculate the number of subarrays in which the ith element is smaller  = (i - nextSmallerElementIndex on left) (nextSmallerElementIndex on right - i).
// and sum would be ans*(i - nextSmallerElementIndex on left) (nextSmallerElementIndex on right - i)

// Note: we may have duplicate elements so to avoid that, we will the condition ( > instead of  <= ) on any of the one side.

class Solution {
  public:
    
    int sumSubarrayMins(int N, vector<int> &arr) {
        
        stack<int> s1, s2;
        
        // tp store the indexes of the next smaller element
        vector<int> left_smaller(N, 0);
        vector<int> right_smaller(N, 0);
        
        // push the default values for the left and right stack respectively
        s1.push(0);
        s2.push(N-1);
        
        left_smaller[0] = -1;
        right_smaller[N-1] = N;
        
        for(int i = 1; i < N; i++){
            
            // number of elements strictly greater than the arr[i] are poppoed out
            while(!s1.empty() && arr[s1.top()] > arr[i]) s1.pop();
            
            if(s1.empty()) left_smaller[i] = -1;
            else left_smaller[i] = s1.top();
            
            s1.push(i);
        }
        
        for(int  i = N-2; i >= 0; i--){
            
            // !---------------NOTE----------------!
            // Here the condition is different
            // number of elements strictly greater than or equal to the arr[i] are poppoed out
            while(!s2.empty() && arr[s2.top()] >= arr[i] ) s2.pop();
            
            if(s2.empty()) right_smaller[i] = N;
            else right_smaller[i] = s2.top();
            
            s2.push(i);
        }
        
        long long int count = 0;
        
        for(int i = 0; i < N; i++){
            
            count = (count%1000000007 + ( arr[i]*(i - left_smaller[i])*(right_smaller[i] - i) )%1000000007 + 1000000007)%1000000007;
            
            // count += ( arr[i]*(i - left_smaller[i])*(right_smaller[i] - i) );
            
        }
        
        return count;
    }
};
