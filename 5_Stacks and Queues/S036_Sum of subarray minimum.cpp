#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

// 1
// generate all the subarrays and find the minimum element in then
// O(N^3)

// 2
// O(N)
// o(N)
// count the number of element greater than the arr[i] on the left;
// count the number of element greater than or equal to the arr[i] on the right;

// total number of subarrays in which arr[i] would be minimum is equal to
// (count_left + 1)(count_right + 1)
// so for a particular index, arr[i]*(count_left + 1)(count_right + 1)
// would be added to the answer.

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